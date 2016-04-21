//------------------------------------------------------------------------------
// Game.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
// Christopher Kopel 0730613
//------------------------------------------------------------------------------

#include "Game.h"
#include "Field.h"
#include "Coordinates.h"

using std::string;
using std::vector;



//------------------------------------------------------------------------------
Game::Game(vector<vector<Field* > >* new_board, string turns_string,
    int total_turns, Coordinates* start_point) : board_(new_board),
    finished_turns_(turns_string), max_turns_(total_turns),
    origin_(start_point), remaining_turns_(total_turns), finished_(false)
{
  pos_now_ = new Coordinates(*start_point);
}



//------------------------------------------------------------------------------
Game::~Game(){
  delete pos_now_;
  deleteFields();
  delete board_;
  delete origin_;
}



//------------------------------------------------------------------------------
void Game::setBoard(std::vector< std::vector<Field*> >* new_board)
{
  deleteFields();
  board_ = new_board;
}



//------------------------------------------------------------------------------
int Game::singleMove(Coordinates& tmp_pos, Coordinates& go_to,
    string go_to_str, int& bonus)
{
  int enter_code = 0;
  bool turn_is_over = false;
  
  // if game already finished or no more turns left => invalid move
  if((finished_ == true ) || (remaining_turns_ <= 0))
  {
    return -1; //invalid move
  }
  
  while(turn_is_over == false)
  {
    int nxt_field_code = calculateNextField(tmp_pos, go_to, go_to_str);
    
    // if next field is valid but not a teleport field
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
      string symbol_now = board_->at(y_tmp).at(x_tmp)->getFieldSymbol();
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
    }
    
    // if next field is a teleport field
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
int Game::move(string go_to_str)
{
  int move_validity = 0;
  int bonus = 0;
  Coordinates tmp_pos = *pos_now_;
  Coordinates go_to = tmp_pos;

  // convert "right" to "r" etc.
  longToShortMoveString(go_to_str);
  
  move_validity = singleMove(tmp_pos, go_to, go_to_str, bonus);
  
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
    
    return 0;
  }
  else
  {
    std::cout << "[ERR] Invalid move.\n";
    return 1;
  }
}



//------------------------------------------------------------------------------
int Game::fastMove(string all_turns_str)
{
  int move_validity = 0;
  int bonus, char_iterator = 0;
  unsigned long int nr_turns = all_turns_str.length(); //total number of turns
  
  // backup some members if fastmove fails
  int remaining_turns_backup = remaining_turns_;
  Coordinates tmp_pos = *pos_now_;
  
  Coordinates go_to = tmp_pos;
  string go_to_str;
  
  
  do
  {
    bonus = 0;
    go_to_str = all_turns_str[char_iterator]; //read next turn
    move_validity = singleMove(tmp_pos, go_to, go_to_str, bonus);
    char_iterator = char_iterator + 1;
    remaining_turns_ = remaining_turns_ + bonus - 1;
    if (remaining_turns_ < 0)
    {
      remaining_turns_ = 0;
    }
  }
  while ((char_iterator < nr_turns) && (move_validity == 0));
  
  
  
  if (move_validity == 0) // if move is valid
  {
    finished_turns_ = finished_turns_ + all_turns_str; // update finished turns
    *pos_now_ = tmp_pos; // update player position
    setGameIsFinished(); // check if player is on finish field
    return 0; // All OK
  }
  else
  {
    remaining_turns_ = remaining_turns_backup;
    std::cout << "[ERR] Invalid move.\n";
    return 1; // invalid series of turns
  }
}



//------------------------------------------------------------------------------
int Game::calculateNextField(Coordinates& position, Coordinates &go_to,
    string leaving_to)
{
  if(leaving_to == "l")
  {
    go_to.changeXBy(-1);
    return 0; // Next field is a valid neighboring field
  }
  else if(leaving_to == "r")
  {
    go_to.changeXBy(1);
    return 0;
  }
  else if(leaving_to == "u")
  {
    go_to.changeYBy(-1);
    return 0;
  }
  else if(leaving_to == "d")
  {
    go_to.changeYBy(1);
    return 0;
  }
  else if(isupper(leaving_to[0]) && isalpha(leaving_to[0]))
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
  string field_symbol = board_->at(y).at(x)->getFieldSymbol();
  if (field_symbol == "x")
  {
    finished_ = true;
    std::cout << "Congratulation! You solved the maze.\n";
  }
}



//------------------------------------------------------------------------------
void Game::longToShortMoveString(string& long_string)
{
  if (long_string == "up")
  {
    long_string = "u";
  }
  else if (long_string == "down")
  {
    long_string = "d";
  }
  else if (long_string == "left")
  {
    long_string = "l";
  }
  else if (long_string == "right")
  {
    long_string = "r";
  }
}



//------------------------------------------------------------------------------
void Game::findTeleportLocation(const string teleport_letter,
    const Coordinates& position, Coordinates& teleport_exit)
{
  int portal_x=0, portal_y=0;
  for (int y = 0; y < board_->size(); y++)
  {
    for (int x = 0; x < board_->at(y).size(); x++)
    {
      string symbol = board_->at(y).at(x)->getFieldSymbol();
      
      // If the momentary field in this loop is not the one the player wants to
      // enter and if it has the same portal letter as the one he wants to enter
      // it must be the corresponding portal of that field.
      if (((x != position.getX()) || (y != position.getY()))
          && symbol == teleport_letter)
      {
        portal_x = x;
        portal_y = y;
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
      if ((x != pos_now_->getX()) || (y != pos_now_->getY()))
      {
        std::cout << board_->at(y).at(x)->getFieldSymbol();
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
}



//------------------------------------------------------------------------------
void Game::deleteFields()
{
  // This Loop is used to delete all the Fields in the 2D Board Vector. Copied
  // and slightly adapted from a Stackoverflow discussion about 2D Vectors.
  for (int y = 0; y < board_->size(); ++y)
  {
    for (int x = 0; x < board_->at(y).size(); ++x)
    {
      delete board_->at(y).at(x);
      board_->at(y).at(x) = 0;
    }
  }
  board_->clear();
}
