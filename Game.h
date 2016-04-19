//------------------------------------------------------------------------------
// game.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <vector> // again, can't forward declare a template
#include <fstream>
class Field;
class Coordinates;
using std::string;
using std::vector;

class Game
{
  private:
    vector<vector<Field* > > board_;
    Coordinates* pos_now_; //x und y Koordinate der jetzigen Position (Ursprung oben links)
    int remaining_turns_;
    int max_turns_;
    string finished_turns_; //Diese Züge wurden schon erfolgreich gespielt
    bool finished_;
  //-------------------------------------------------------------------------------------------------
    int calculateNextField(Coordinates& position, Coordinates &go_to, string go_to_str);
    int singleMove(Coordinates& tmp_pos, Coordinates& go_to,
        string go_to_str, int& bonus);
    void setGameIsFinished();
    void longToShortMoveString(string &move_string);
    void findTeleportLocation(const string teleport_letter,
        const Coordinates& position, Coordinates& teleport_exit);
  
  public:
    Game(vector<vector<Field* > > new_board, string turns_string,
    int total_turns, Coordinates* start_point);
    virtual ~Game();
    void setBoard(vector<vector<Field*> > new_board);
    int move(string direction);
    int fastMove(string direction);
    int save(string filename);
    int getMaxTurns() const;
    vector <vector<Field*> > getBoard() const;
    string getFinishedTurns() const;
    void setFinishedTurns(string turns_string);

};



#endif 