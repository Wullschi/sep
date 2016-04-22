//------------------------------------------------------------------------------
// Game.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <vector> // Can't forward declare templates
#include <fstream>

#include "Command.h"   // necessary to access Status constants
class Field;
class Coordinates;
using std::string;
using std::vector;

class Game
{
  private:

    vector<vector<Field* > >* board_;
    Coordinates* origin_;
    Coordinates* pos_now_; //x and y coordinates of player
    int remaining_turns_;
    int max_turns_;
    string finished_turns_; //these turns have already been played
    bool finished_;
  
    //--------------------------------------------------------------------------
    // Private standard constructor
  
    Game();
  
    //--------------------------------------------------------------------------
    // Private copy constructor
  
    Game(const Game&);
  
    //--------------------------------------------------------------------------
    // This private Method executes a single move and is a helper method for
    // the move AND the fastmove command.
    //
    // @param tmp_pos a variable which holds the coordinates of the momentary
    //        position
    // @param go_to a variable which holds and returns the coordinates where
    //        the player wants to move next
    // @param go_to_str a string which holds the letter which indicates the
    //        direction of this move (l, r, u, d)
    // @param bonus saves and returns the bonus (or quicksand) points that were
    //        collected in this move
    //
    // @return int indicates if the move is valid or not

    int singleMove(Coordinates& tmp_pos, Coordinates& go_to,
        string go_to_str, int& bonus);
  
    //--------------------------------------------------------------------------
    // This methods takes the momentary coordinates and a move string and
    // calculates the coordinates in which the player ends up after this move.
    //
    // @param position the momentary position of the player
    // @param go_to returns the position where the player ends up after
    //        this move
    // @param leaving_to the direction in which the player is leaving the
    //        field (l, r, u. d)
    //
    // @return int indicates if next field is a teleport field, any other
    //         regular field or an invalid field
  
    int calculateNextField(Coordinates& position,
        Coordinates &go_to, string go_to_str);

    //--------------------------------------------------------------------------
    // This method checks if the player is standing on the finished field and
    // sets the finished_ member variable accordingly.
  
    void setGameIsFinished();
  
    //--------------------------------------------------------------------------
    // This method converts a string from the move notation to the
    // fastmove notation. For example "up" to "u" or "left" to "l"
    //
    // @param long_string long notation of move string

    void longToShortMoveString(string &move_string);
  
    //--------------------------------------------------------------------------
    // This method finds the exit to a teleport field that the player is about
    // to enter.
    //
    // @param teleport_letter the letter of the teleport field
    // @param position the position of the teleport field the player is about
    //        to enter
    // @param teleport_exit the position where the player appears after
    //        entering the teleport field
  
    void findTeleportLocation(const string teleport_letter,
        const Coordinates& position, Coordinates& teleport_exit);
  
    //--------------------------------------------------------------------------
    // This method deletes all fields of the game board.

    void deleteFields();
  
  public:
    //--------------------------------------------------------------------------
    // This is the Costructor of the Game class.
    //
    // @param new_board the gameboard that hoalds all the different fields
    // @param turns_string strings of all turns that were already played in the
    //        loaded file
    // @param total_turns maximum number of turns in the game
    // @param start_point the position of the start field
  
    Game(vector<vector<Field* > >* new_board, string turns_string,
        int total_turns, Coordinates* start_point);
  
    //--------------------------------------------------------------------------
    // Destructor
  
    virtual ~Game();
  
    //--------------------------------------------------------------------------
    // Setter: This Method assigns a new game board to the appropriate member
    // variable.
    //
    // @param new_board the game board which is passed to the corresponding
    //        member variable

    void setBoard(vector<vector<Field*> >* new_board);

    //--------------------------------------------------------------------------
    // Setter: sets/updates the all the turns that were already executed
    // in the game (fastmove notation)
    //
    // @param turns_string the string which contains all the executed turns

    void setFinishedTurns(string turns_string);
  
    //--------------------------------------------------------------------------
    // Getter: Returns the maximum turns for the game
    //
    // @return int the maximum turns in this game

    int getMaxTurns() const;
  
    //--------------------------------------------------------------------------
    // Getter: Returns the game board of the current game
    //
    // @return vector <vector<Field*> > the returned board
  
    vector <vector<Field*> >* getBoard() const;
  
    //--------------------------------------------------------------------------
    // Getter: returns a string of commands that were already executed in this
    // game (in fastmove notation)
    //
    // @return string the commands that were successfully executed in this game

    string getFinishedTurns() const;

    //--------------------------------------------------------------------------
    // This method is executed when the player uses the move-command. It makes
    // use of the single_move() method and updates the member variables of this
    // class (position of player, remaining turns etc.) if the move is valid.
    //
    // @param go_to_string the move string that was entered by the player
    //
    // @return Status constant of class Command: OK or INVALID_MOVE

    Command::Status move(string direction);
  
    //--------------------------------------------------------------------------
    // This method is executed when the player uses the fastmove-command. It makes
    // use of the single_move() method for every letter in the string. If the
    // series of single moves is valid, it updates the member variables of this
    // class (position of player, remaining turns etc.).
    //
    // @param all_moves_str the fastmove string entered by the player
    //
    // @return Status constant of class Command: OK or INVALID_MOVE

    Command::Status fastMove(string direction);

    //--------------------------------------------------------------------------
    // Resets the game

    void reset();
  
    //--------------------------------------------------------------------------
    // This method prints the game board to the console
    //
    // @param more true when remaining turns and finished moves should also be
    //        displayed
  
    void show(bool more) const;

};

#endif 