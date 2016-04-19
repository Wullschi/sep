//------------------------------------------------------------------------------
// basic.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Christopher Kopel 0730613
// Stefan Maier 1014203
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

/*#include <iostream>
 #include "field.h"
 #include "start.h"
 #include "finish.h"
 #include "path.h"
 #include "wall.h"
 #include "bonus.h"
 #include "teleport.h"
 #include "ice.h"
 #include "oneway.h"
 #include <vector>
 #include <memory>
 #include "game.h"
 #include "Coordinates.h"*/






#include "Game.h"
#include "UserInput.h"



int main(int argc, const char* argv[])
{
  
  Game* current_game;
  int error_code = 0;
  
  error_code = UserInput::checkCommandLineOptions(argc, argv, current_game);
  
  if (error_code)
  {
    return error_code;
  }
  
  
  UserInput::commandLine(current_game);
  
  std::cout << "tschautschu" << std::endl;
  delete current_game;
  return 0;
  
  
}






















/*
 
 int main(int argc, const char * argv[]) {
 // insert code here...
 Coordinates* start_point = new Coordinates(1, 1);
 
 
 std::vector< std::vector< Field* > > newBoard;
 
 std::vector<Field*> Row;
 Row.clear();
 Row.push_back(new Wall(0,0));
 Row.push_back(new Wall(1,0));
 Row.push_back(new Wall(2,0));
 Row.push_back(new Wall(3,0));
 Row.push_back(new Wall(4,0));
 Row.push_back(new Wall(5,0));
 Row.push_back(new Wall(6,0));
 newBoard.push_back(Row);
 
 Row.clear();
 Row.push_back(new Wall(0,1));
 Row.push_back(new Start(1,1));
 Row.push_back(new Path(2,1));
 Row.push_back(new Ice(3,1));
 Row.push_back(new Path(4,1));
 Row.push_back(new Teleport(5,1,"B"));
 Row.push_back(new Wall(6,1));
 newBoard.push_back(Row);
 
 Row.clear();
 Row.push_back(new Wall(0,2));
 Row.push_back(new Path(1,2));
 Row.push_back(new Path(2,2));
 Row.push_back(new Finish(3,2));
 Row.push_back(new Path(4,2));
 Row.push_back(new Path(5,2));
 Row.push_back(new Wall(6,2));
 newBoard.push_back(Row);
 
 Row.clear();
 Row.push_back(new Wall(0,3));
 Row.push_back(new Path(1,3));
 Row.push_back(new Ice(2,3));
 Row.push_back(new Ice(3,3));
 Row.push_back(new Ice(4,3));
 Row.push_back(new Path(5,3));
 Row.push_back(new Wall(6,3));
 newBoard.push_back(Row);
 
 Row.clear();
 Row.push_back(new Wall(0,4));
 Row.push_back(new Finish(1,4));
 Row.push_back(new Path(2,4));
 Row.push_back(new Path(3,4));
 Row.push_back(new Ice(4,4));
 Row.push_back(new Path(5,4));
 Row.push_back(new Wall(6,4));
 newBoard.push_back(Row);
 
 Row.clear();
 Row.push_back(new Wall(0,5));
 Row.push_back(new Path(1,5));
 Row.push_back(new Teleport(2,5,"B"));
 Row.push_back(new OneWay(3,5,">"));
 Row.push_back(new Bonus(4,5,"e"));
 Row.push_back(new Path(5,5));
 Row.push_back(new Wall(6,5));
 newBoard.push_back(Row);
 
 Row.clear();
 Row.push_back(new Wall(0,6));
 Row.push_back(new Wall(1,6));
 Row.push_back(new Wall(2,6));
 Row.push_back(new Wall(3,6));
 Row.push_back(new Wall(4,6));
 Row.push_back(new Wall(5,6));
 Row.push_back(new Wall(6,6));
 newBoard.push_back(Row);
 
 
 Game Labyrinth(newBoard, "", 40, start_point);
 
 Labyrinth.move("down");
 Labyrinth.move("down");
 Labyrinth.move("down");
 Labyrinth.move("down");
 Labyrinth.move("down");
 
 //Labyrinth.Move("u");
 //Labyrinth.fastMove("dddd");
 //std::string direction;
 
 Labyrinth.save("maze1.txt");
 
 
 //FREE MEMORY AM SCHLUSS
 //for (int i = 0; i < state.size(); ++i)
 //{
 //for (int j = 0; j < state[i].size(); ++j)
 //{
 //delete state[i][j];
 //}
 //}
 
 
 return 0;
 }
 */