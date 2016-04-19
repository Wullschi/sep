//------------------------------------------------------------------------------
// game.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#include "Game.h"
#include "field.h"
#include "Coordinates.h"

using std::string;
using std::vector;



//------------------------------------------------------------------------------
// This is the Costructor of the Game class.
//
// @param new_board the gameboard that hoalds all the different fields
// @param turns_string strings of all turns that were already played in the loaded file
// @param total_turns maximum number of turns in the game
// @param start_point the position of the start field
//
Game::Game(vector<vector<Field* > > new_board, string turns_string,
    int total_turns, Coordinates* start_point) : board_(new_board),
    finished_turns_(turns_string), max_turns_(total_turns),
    pos_now_(start_point), remaining_turns_(total_turns), finished_(false)
{}


//------------------------------------------------------------------------------
// This is the Destructor of the Game class.
//
Game::~Game(){
  std::cout << "Deleting this game" << std::endl;
  delete pos_now_;
  
  // This Loop is used to delete all the Fields in the 2D Board Vector
  // Copied and slightly adapted from a Stackoverflow discussion about 2D Vectors
  for (int y = 0; y < board_.size(); ++y)
  {
    for (int x = 0; x < board_.size(); ++x)
    {
      delete board_[y][x];
    }
  }
}



//------------------------------------------------------------------------------
// This Method assigns a new game board to the appropriate member variable.
//
// @param new_board the game board which is passe to the corresponding member variable
//
void Game::setBoard(std::vector< std::vector<Field*> > new_board)
{
  board_ = new_board;
}



//------------------------------------------------------------------------------
// This private Method executes a single move and can therefore be used for
// the move AND the fastmove command.
//
// @param tmp_pos a variable which holds the coordinates of the momentary position
// @param go_to a variable which holds and returns the coordinates where the player wants to move next
// @param go_to_str a string which holds the letter which indicates the direction of this move (l, r, u, d)
// @param bonus saves and returns the bonus (or quicksand) points that were collected in this move
//
// @return int indicates if the move is valid or not
//
int Game::singleMove(Coordinates& tmp_pos, Coordinates& go_to,
    string go_to_str, int& bonus)
{
  int enter_code = 0;
  bool turn_is_over = false;
  if(finished_ == true)
  {
    std::cout << "invalid move" << std::endl;
    return -1; //invalid move
  }
  
  while(turn_is_over == false)
  {
    int nxt_field_code = calculateNextField(tmp_pos, go_to, go_to_str);
    
    if (nxt_field_code == 0)
    {
      int x_tmp = tmp_pos.getX();
      int y_tmp = tmp_pos.getY();
      bool can_leave = board_[y_tmp][x_tmp]->isAbleToLeave(&go_to);
      if (can_leave == false)
      {
        std::cout << "not able to leave this field in this direction" << std::endl;
        return -1; //invalid move
      }
      
      
      string entering_from;
      string symbol_now = board_[y_tmp][x_tmp]->getFieldSymbol();
      int go_x = go_to.getX();
      int go_y = go_to.getY();
      bool can_enter = board_[go_y][go_x]->isAbleToEnter(&tmp_pos, entering_from);
      if ((can_enter == false) && (enter_code != 1))
      {
        std::cout << "not able to enter new field from this direction" << std::endl;
        return -1; //invalid move
      }
      //move should still be valid when leaving an ice field
      //to a field which can't be entered
      else if ((can_enter == false) && (enter_code == 1))
      {
        turn_is_over = true;
        go_to = tmp_pos;
      }
      
      enter_code = board_[go_y][go_x]->enter(entering_from, bonus);
      turn_is_over = board_[go_y][go_x]->isTurnOver(go_to_str);
    }
    else if (nxt_field_code == 1)
    {
      turn_is_over = true; //sonst springt man endlos von einem Teleportfeld zum anderen
    }
    
    tmp_pos = go_to;
  }
  
  return 0; // All OK
}



//------------------------------------------------------------------------------
// This Method takes the string for a move command from the player, executes the single_move()
// method and updates the members (position of player, remaining turns etc.) of the game class
// the move is valid.
//
// @param go_to_string the move string that was entered by the player
//

int Game::move(string go_to_str)
{
  int move_validity = 0;
  int bonus = 0;
  Coordinates tmp_pos = *pos_now_;
  Coordinates go_to = tmp_pos;

  longToShortMoveString(go_to_str);
  
  move_validity = singleMove(tmp_pos, go_to, go_to_str, bonus);
  
  
  if (move_validity == 0)
  {
    finished_turns_ = finished_turns_ + go_to_str;
    remaining_turns_ = remaining_turns_ + bonus - 1;
    *pos_now_ = tmp_pos;
    std::cout << "X: "<< pos_now_->getX() << "   Y: " << pos_now_->getY() << "   Turns remaining: " <<remaining_turns_ << "    " << finished_turns_ << std::endl;
    
    setGameIsFinished();
    
  }
  
  return 0;
}



//------------------------------------------------------------------------------
// This Method takes the string from a fastmove command from the player, executes the single_move()
// method for every command-letter in the string. If the series of single moves is valid, it then
// updates the members (position of player, remaining turns etc.) of the game class.
//
// @param all_moves_str the fastmove string entered by the player
//

int Game::fastMove(string all_moves_str)
{
  int move_validity = 0;
  int bonus, char_iterator = 0;
  unsigned long int nr_moves = all_moves_str.length();
  int remaining_turns_backup = remaining_turns_;
  Coordinates tmp_pos = *pos_now_;
  Coordinates go_to = tmp_pos;
  string go_to_str;
  
  do
  {
    bonus = 0;
    go_to_str = all_moves_str[char_iterator];
    move_validity = singleMove(tmp_pos, go_to, go_to_str, bonus);
    char_iterator = char_iterator + 1;
    remaining_turns_ = remaining_turns_ + bonus - 1;
  }
  while ((char_iterator < nr_moves) && (move_validity == 0));
  
  
  
  if (move_validity == 0)
  {
    finished_turns_ = finished_turns_ + all_moves_str;
    *pos_now_ = tmp_pos;
    std::cout << "X: "<< pos_now_->getX() << "   Y: " << pos_now_->getY() << "   Turns remaining: " <<remaining_turns_ << "    " << finished_turns_ << std::endl;
    setGameIsFinished();
  }
  else
  {
    remaining_turns_ = remaining_turns_backup;
    std::cout << "X: "<< pos_now_->getX() << "   Y: " << pos_now_->getY() << "   Turns remaining: " <<remaining_turns_ << "    " << finished_turns_ << std::endl;
    setGameIsFinished();
  }
  
  return 0;
}



//------------------------------------------------------------------------------
// This methods takes the momentary coordinates and a move string and calculates the coordinates
// in which the player ends up after this move.
//
// @param position the momentary position of the player
// @param go_to returns the position where the player ends up after this move
// @param leaving_to the direction in which the player is leaving the field (l, r, u. d)
//
int Game::calculateNextField(Coordinates& position, Coordinates &go_to, string leaving_to)
{
  
  if (leaving_to.length() != 1)
  {
    return -1; //-1 heisst: kein gültiger "leaving_to" String
  }
  
  if(leaving_to == "l")
  {
    go_to.changeXBy(-1);
    return 0; //0 heisst: Funktion regulär beendet. Nächstes Feld ist ein benachbartes Feld.
    //Es kann nun versucht werden den Zug zu starten.
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
  
  
  if(isupper(leaving_to[0]) && isalpha(leaving_to[0]))
  {
    std::string portal_letter="";
    int portal_x=0, portal_y=0, portal_counter=0;
    for (int y = 0; y < board_.size(); y++)
    {
      for (int x = 0; x < board_[y].size(); x++)
      {
        if ((x != position.getX()) || (y != position.getY()))
        {
          
          // **************************************************
          // TODO: zuviele Verschachtelungen!!!!!!!!!!!!!!!!!
          // **************************************************
          
          string symbol = board_[y][x]->getFieldSymbol();
          if (symbol == leaving_to)
          {
            portal_x = x;
            portal_y = y;
            portal_counter++;
            portal_letter = "";
          }
        }
      }
    }
    
    if (portal_counter == 1)
    {
      go_to.setX(portal_x);
      go_to.setY(portal_y);
      return 1; //1 heisst: Funktion regulär beendet. Nächstes Feld ist ein Portal.
      //Es kann nun versucht werden den Zug zu starten.
    }
    else
    {
      return -2; //-2 heisst: gibt kein 2. Teleportfeld welches regulär benutzt werden könnte.
    }
  }
  return 0;
}



//------------------------------------------------------------------------------
// Returns the maximum turns for the game
//
int Game::getMaxTurns() const
{
  return max_turns_;
}



//------------------------------------------------------------------------------
// returns a string of commands that were already executed in this game (in fastmove notation)
//
std::string Game::getFinishedTurns() const
{
  return finished_turns_;
}



//------------------------------------------------------------------------------
// This method sets/updates the all the turns that were already executed in the game (fastmove notation)
//
// @param turns_string the string which contains all the executed turns
//
void Game::setFinishedTurns(std::string turns_string)
{
  finished_turns_ = turns_string;
}



//
//
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// EVENTUELL LÖSCHEN

/*int Game::save(std::string file_name)
{
  //TODO: hier die Überprüfung des Dateinamens noch implementieren.
  bool name_is_valid = true;
  if(name_is_valid == true)
  {
    
    std::ofstream file(file_name);
    if (!file.is_open())
    {
      std::cout << "[ERR] File could not be written.\n";
    } else
    {
      
      file << finished_turns_<<"\n";
      file << max_turns_<<"\n";
      
      
      for (int y = 0; y < board_.size(); y++)
      {
        for (int x = 0; x < board_[y].size(); x++)
        {
          file << board_[y][x]->getFieldSymbol();
        }
        file << "\n";
      }
      file.close();
    }
  }
  else
  {
    std::cout << "[ERR] Wrong parameter.\n";
  }
  return 0;
}
*/
// EVENTUELL LÖSCHEN
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
// **
//
//



//------------------------------------------------------------------------------
// This method checks if the player is standing on the finished field and sets the
// finished_ member variable accordingly.
//
void Game::setGameIsFinished()
{
  int x = pos_now_->getX();
  int y = pos_now_->getY();
  string field_symbol = board_[y][x]->getFieldSymbol();
  if (field_symbol == "x")
  {
    finished_ = true;
    std::cout << "Congratulation! You solved the maze.\n";
  }
}



//------------------------------------------------------------------------------
// This method coverts a string from the move notation to the fastmove notation
// for example "up" to "u" or "left" to "l"
//
// @param long_string long notation of move string
//
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



vector< std::vector<Field*> > Game::getBoard() const
{
  return board_;
}