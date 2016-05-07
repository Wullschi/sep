//------------------------------------------------------------------------------
// Game.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Game.h"
#include "Field.h"
#include "Coordinates.h"
#include "Command.h"
#include "Path.h"
#include "Bonus.h"
#include "Move.h"
#include "Fastmove.h"

using std::string;
using std::vector;



//------------------------------------------------------------------------------
Game::Game(vector<vector<Field* > >* new_board, string turns_string,
    int total_turns, Coordinates* start_point) : board_(new_board),
    origin_(start_point), remaining_turns_(total_turns),
    max_turns_(total_turns), finished_turns_(turns_string), finished_(false)
{
    pos_now_ = new Coordinates(*start_point);
}

//------------------------------------------------------------------------------
Game::~Game() throw()
{
  delete pos_now_;
  pos_now_ = 0;
  deleteFields();
  delete board_;
  board_ = 0;
  delete origin_;
  origin_ = 0;
}


//------------------------------------------------------------------------------
void Game::setBoard(vector<vector<Field*> >* new_board)
{
  deleteFields();
  board_ = new_board;
}



//------------------------------------------------------------------------------
int Game::singleMove(Coordinates& tmp_pos, Coordinates& go_to,
    vector <Coordinates>& bonus_list, string go_to_str, int& bonus)
{
  int enter_code = 0;
  bool turn_is_over = false;
  
  // if game already finished or no more turns left => invalid move
  if (finished_)
  {
    return -1; //invalid move
  }
  
  while(turn_is_over == false)
  {
    int nxt_field_code = calculateNextField(tmp_pos, go_to, go_to_str);
    
    // if next field is valid but not the exit portal of a teleport field
    if (nxt_field_code == 0)
    {
      int x_tmp = tmp_pos.getX();
      int y_tmp = tmp_pos.getY();
      
      // check if we can leave the field in the desired direction
      bool can_leave = board_->at(y_tmp).at(x_tmp)->isAbleToLeave(&go_to);
      if (can_leave == false)
      {
        return -1; //invalid move
      }
      
      string entering_from;
      int go_x = go_to.getX();
      int go_y = go_to.getY();
      
      // check if we can enter the next field in the desired direction
      bool can_enter = board_->at(go_y).at(go_x)->isAbleToEnter(&tmp_pos,
          entering_from);
      if ((can_enter == false) && (enter_code != 1))
      {
        return -1; //invalid move
      }
      
      // If enter_code is 1, we previously entered an ice field which we now
      // leave again. Move should still be valid when leaving an ice field
      // to a field which can't be entered (stop in front of field which
      // can't be entered)
      else if ((can_enter == false) && (enter_code == 1))
      {
        turn_is_over = true;
        go_to = tmp_pos;
      }
      
      
      enter_code = board_->at(go_y).at(go_x)->enter(entering_from, bonus);
      turn_is_over = board_->at(go_y).at(go_x)->isTurnOver(go_to_str);
      
      if (bonus > 0)
      {
        Coordinates found_bonus(go_x, go_y);
        bonus_list.push_back(found_bonus);
      }
    }
    
    // if next field is a exit portal of a teleport field
    else if (nxt_field_code == 1)
    {
      // prevents from endlessly jumping between portals
      turn_is_over = true;
    }
    
    // single move has been successful. Update new temporary position
    tmp_pos = go_to;
  }
  
  return 0; // All OK
}



//------------------------------------------------------------------------------
Command::Status Game::move(string go_to_str)
{
  vector <Coordinates> bonus_list;

  
  if (finished_)
  {
    return Command::INVALID_MOVE_;
  }
  else if (!remaining_turns_)
  {
    return Command::NO_MORE_STEPS_;
  }
  
  int move_validity = 0;
  int bonus = 0;
  Coordinates tmp_pos = *pos_now_;
  Coordinates go_to = tmp_pos;

  // convert "right" to "r" etc.
  longToShortMoveString(go_to_str);
  
  try
  {
    move_validity = singleMove(tmp_pos, go_to, bonus_list, go_to_str, bonus);
  }
  catch (std::bad_alloc& exception)
  {
    return Command::OUT_OF_MEMORY_;
  }
  
  // if the move is valid
  if (move_validity == 0)
  {
    finished_turns_ = finished_turns_ + go_to_str; // update finished turns
    remaining_turns_ = remaining_turns_ + bonus - 1;
    *pos_now_ = tmp_pos; // update player position
    
    if (remaining_turns_ < 0)
    {
      remaining_turns_ = 0;
    }
    
    // check if player is on finish field
    setGameIsFinished();
    
    return (finished_) ? Command::GAME_WON_ : Command::OK_;
  }
  else
  {
    return Command::INVALID_MOVE_;
  }
}



//------------------------------------------------------------------------------
Command::Status Game::fastMove(string all_turns_str)
{
  vector <Coordinates> bonus_list;
  if (finished_)
  {
    return Command::INVALID_MOVE_;
  }
  else if (!remaining_turns_)
  {
    return Command::NO_MORE_STEPS_;
  }

  int move_validity = 0;
  int bonus = 0;
  std::size_t char_iterator = 0;
  std::size_t nr_turns = all_turns_str.length(); // total number of turns
  
  // backup some members if fastmove fails
  int remaining_turns_backup = remaining_turns_;
  Coordinates tmp_pos = *pos_now_;
  
  Coordinates go_to = tmp_pos;
  string go_to_str;
  
  
  do
  {
    bonus = 0;
    go_to_str = all_turns_str[char_iterator]; // read next turn
    
    try
    {
      move_validity = singleMove(tmp_pos, go_to, bonus_list, go_to_str, bonus);
    }
    catch (std::bad_alloc& exception)
    {
      return Command::OUT_OF_MEMORY_;
    }
    
    char_iterator = char_iterator + 1;
    remaining_turns_ = remaining_turns_ + bonus - 1;
    if (remaining_turns_ < 0)
    {
      remaining_turns_ = 0;
    }
    if ((remaining_turns_ == 0) && ((nr_turns - char_iterator) > 0))
    {
      move_validity = -1;
    }
  }
  while ((char_iterator < nr_turns) && (move_validity == 0));
  
  
  
  if (move_validity == 0) // if move is valid
  {
    finished_turns_ = finished_turns_ + all_turns_str; // update finished turns
    *pos_now_ = tmp_pos; // update player position
    setGameIsFinished(); // check if player is on finish field
    
    return (finished_) ? Command::GAME_WON_ : Command::OK_;
  }
  else
  {
    
    for(std::vector<Coordinates>::iterator coord = bonus_list.begin();
        coord != bonus_list.end(); ++coord)
    {
      int x = coord->getX();
      int y = coord->getY();
      board_->at(y).at(x)->reset();
    }
    
    remaining_turns_ = remaining_turns_backup;
    return Command::INVALID_MOVE_; // invalid series of turns
  }
}



//------------------------------------------------------------------------------
int Game::calculateNextField(Coordinates& position, Coordinates &go_to,
    string leaving_to)
{
  if (leaving_to == Fastmove::LEFT_)
  {
    go_to.changeXBy(-1);
    return 0; // Next field is a valid neighboring field
  }
  else if (leaving_to == Fastmove::RIGHT_)
  {
    go_to.changeXBy(1);
    return 0;
  }
  else if (leaving_to == Fastmove::UP_)
  {
    go_to.changeYBy(-1);
    return 0;
  }
  else if (leaving_to == Fastmove::DOWN_)
  {
    go_to.changeYBy(1);
    return 0;
  }
  else if (isupper(leaving_to[0]) && isalpha(leaving_to[0]))
  {
    findTeleportLocation(leaving_to, position, go_to);
    return 1; // Next field is a teleport field.
  }
  else
  {
    return -1; // leaving_to string not valid
  }
}



//------------------------------------------------------------------------------
int Game::getMaxTurns() const
{
  return max_turns_;
}



//------------------------------------------------------------------------------
std::string Game::getFinishedTurns() const
{
  return finished_turns_;
}



//------------------------------------------------------------------------------
void Game::setFinishedTurns(std::string turns_string)
{
  finished_turns_ = turns_string;
}



//------------------------------------------------------------------------------
void Game::setGameIsFinished()
{
  int x = pos_now_->getX();
  int y = pos_now_->getY();
  string field_symbol = board_->at(y).at(x)->getFieldSymbol(Field::FOR_GAME);
  if (field_symbol == "x")
  {
    finished_ = true;
  }
}



//------------------------------------------------------------------------------
void Game::longToShortMoveString(string& long_string)
{
  if (long_string == Move::UP_)
  {
    long_string = Fastmove::UP_;
  }
  else if (long_string == Move::DOWN_)
  {
    long_string = Fastmove::DOWN_;
  }
  else if (long_string == Move::LEFT_)
  {
    long_string = Fastmove::LEFT_;
  }
  else if (long_string == Move::RIGHT_)
  {
    long_string = Fastmove::RIGHT_;
  }
}



//------------------------------------------------------------------------------
void Game::findTeleportLocation(const string teleport_letter,
    const Coordinates& position, Coordinates& teleport_exit)
{
  int portal_x=0, portal_y=0;
  for (std::size_t y = 0; y < board_->size(); y++)
  {
    for (std::size_t x = 0; x < board_->at(y).size(); x++)
    {
      string symbol = board_->at(y).at(x)->getFieldSymbol(Field::FOR_GAME);
      
      // If the momentary field in this loop is not the one the player wants to
      // enter and if it has the same portal letter as the one he wants to enter
      // it must be the corresponding portal of that field.
      std::size_t player_x = position.getX();
      std::size_t player_y = position.getY();
      if (((x != player_x) || (y != player_y))
          && symbol == teleport_letter)
      {
        portal_x = static_cast<int>(x);
        portal_y = static_cast<int>(y);
      }
    }
  }

  teleport_exit.setX(portal_x);
  teleport_exit.setY(portal_y);
}



//------------------------------------------------------------------------------
void Game::show(bool more) const
{
  if (more == true)
  {
    std::cout << "Remaining Steps: " << remaining_turns_ << std::endl;
    std::cout << "Moved Steps: " << finished_turns_ << std::endl;
  }

  for (unsigned int y = 0; y < board_->size(); y++)
  {
    for (unsigned int x = 0; x < board_->at(y).size(); x++)
    {
      std::size_t player_x = pos_now_->getX();
      std::size_t player_y = pos_now_->getY();
      if ((x != player_x) || (y != player_y))
      {
        std::cout << board_->at(y).at(x)->getFieldSymbol(Field::FOR_GAME);
      }
      else
      {
        std::cout << "*";
      }
    }
    std::cout << "\n";
  }
}



//------------------------------------------------------------------------------
vector< std::vector<Field*> >* Game::getBoard() const
{
  return board_;
}



//------------------------------------------------------------------------------
void Game::reset()
{
  finished_ = false;
  remaining_turns_ = getMaxTurns();
  setFinishedTurns("");
  *pos_now_ = *origin_;
  
  for (std::size_t y = 0; y < board_->size(); ++y)
  {
    for (std::size_t x = 0; x < board_->at(y).size(); ++x)
    {
      board_->at(y).at(x)->reset();
    }
  }
}



//------------------------------------------------------------------------------
void Game::deleteFields()
{
  // This Loop is used to delete all the Fields in the 2D Board Vector. Copied
  // and slightly adapted from a Stackoverflow discussion about 2D Vectors.
  // http://stackoverflow.com/questions/11417772/
  // fill-2d-vector-of-type-base-class-with-derived-class
  // begin
  for (std::size_t y = 0; y < board_->size(); ++y)
  {
    for (std::size_t x = 0; x < board_->at(y).size(); ++x)
    {
      delete board_->at(y).at(x);
      board_->at(y).at(x) = 0;
    }
  }
  // end
  board_->clear();
}
