//
//  load.cpp
//  sep_basis
//
//  Created by Stefan Maier on 05.04.16.
//  Copyright (c) 2016 Stefan Maier. All rights reserved.
//


#include "Loader.h"
#include "Coordinates.h"
#include "Field.h"
#include "Bonus.h"
#include "Teleport.h"
#include "Ice.h"
#include "Wall.h"
#include "Path.h"
#include "Oneway.h"
#include "Start.h"
#include "Finish.h"
#include "Game.h"

using std::vector;
using std::string;
using std::ifstream;

Loader::Loader(const std::string filename) : Filehandler(filename)
{
  
}

Loader::~Loader()
{
  
}



/*Loading function*/
int Loader::load(Game*& game)
{
  const char* LOADFILE = filename_.c_str();
  Coordinates* start_point = 0;
  /*Initialisierungen*/
  std::ifstream cur_file;
  bool found_start = false;
  bool found_end = false;
  int row_count = 0;
  cur_file.open(LOADFILE);
  
  std::vector<char> teleport_list;
  std::string turns_string = "";
  std::string total_turns_string = "";
  std::string fastmove_string = "";

  unsigned int total_turns = 0;
  

  if(cur_file.is_open())
  {
    //std::cout << "db: opened loadfile" << std::endl;
    /*Reading the file*/
    std::vector<Field*> row;
    
    // read fastmove string and check if it is valid
    getline(cur_file, fastmove_string);
    if(fastmove_string.find_first_not_of("ldru")!=std::string::npos)
    {
      std::cout << "db: ERR invalid fastmove" << std::endl;
      return 1;
    }
    
    // read max amount of turns and check if it is a valid number
    getline(cur_file, total_turns_string);
    if(total_turns_string.find_first_not_of("0123456789")!=std::string::npos)
    {
      std::cout << "db: ERR invalid turns" << std::endl;
      return 1;
    }
    total_turns = std::stoi(total_turns_string);
    
    
    // start reading the board if fastmove string and max turns are valid
    while(!cur_file.eof())
    {

      if(cur_file.eof())
      {
        break;
      }
      
      bool correct_row = readOneRow(cur_file, teleport_list, found_start, found_end, row_count, start_point);
      
      if (correct_row == false)
      {
        return 1;
      }

      row.clear();
      row_count = row_count + 1;
    }

    //check board validity
    bool start_and_finish = checkStartAndFinish(found_start, found_end);
    bool shape = checkShape();
    bool wall = checkWall();
    bool teleport = checkTeleport(&teleport_list);
    
    // if any error has been detected, stop loading
    if ((start_and_finish == false) || (shape == false) || (wall == false) || (teleport == false))
    {
      return 1;
    }
    
    game = new Game(loaded_board_, "", total_turns, start_point);
    if(fastmove_string != "")
    {
      game->fastMove(fastmove_string);
    }
    
  }else
  {
    std::cout << "db: can't find "<< filename_ << std::endl;
    return 4;
  }


  
  return 0;
}

































bool Loader::checkStartAndFinish(bool start, bool finish)
{
  if ((start == true) && (finish == true))
  {
    return true;
  }
  else
  {
    /*Start und End tile existieren nicht*/
    std::cout << "db: ERR no valid start or end tile." << std::endl;
    return false;
  }
}

bool Loader::checkShape()
{
  unsigned long int field_height = loaded_board_.size();
  unsigned long int field_length = loaded_board_.at(0).size();
  for(int i = 0; i < field_height; i++)
  {
    unsigned long int row_length = loaded_board_.at(i).size();
    //std::cout << Row.size() << std::endl;
    //std::cout << fptr->getFieldSymbol() << std::endl;
    if(row_length != field_length)
    {
      std::cout << "db: illigeal input. Field is not a rectangle." << std::endl;
      //exception hierher
      return false;
    }
  }
  return true;
}

bool Loader::checkWall()
{
  std::vector<Field*> Row;
  unsigned long int field_height = loaded_board_.size();
  unsigned long int field_length = loaded_board_.at(0).size();
  
  /*Check if all fields in first line are walls*/
  for(int k = 0; k < field_length; k++)
  {
    string field_symbol = loaded_board_.at(0).at(k)->getFieldSymbol();
    if(field_symbol != "#")
    {
      std::cout << "db: ERR invalid field in first row" << std::endl;
      return false;
    }
  }
  
  /*Check if all fields at left and right side are walls*/
  for(int k = 1; k < field_height-1; k++)
  {
    Row = loaded_board_.at(k);
    string field_symbol = loaded_board_.at(k).front()->getFieldSymbol();
    if(field_symbol != "#")
    {
      std::cout << "db: ERR invalid field on left wall" << std::endl;
      return false;
    }
    field_symbol = loaded_board_.at(k).back()->getFieldSymbol();
    if(field_symbol != "#")
    {
      std::cout << "db: ERR invalid field on wall" << std::endl;
      return false;
    }
  }
  
  /*Check if all fields in last line are walls*/
  for(int k = 0; k < field_length; k++)
  {
    string field_symbol = loaded_board_.at(field_height-1).at(k)->getFieldSymbol();
    if(field_symbol != "#")
    {
      std::cout << "db: ERR invalid field in last row" << std::endl;
      return false;
    }
  }
  
  return true;
}

bool Loader::checkTeleport(vector<char>* teleport_list)
{
  /*Check for valid Teleporter*/
  int teleport_amount;
  for(int asci = 65; asci <= 90; asci++)
  {
    teleport_amount = 0;
    for(int k = 0; k < teleport_list->size(); k++)
    {
      if(teleport_list->at(k) == asci)
      {
        teleport_amount++;
      }
    }
    
    // if 0 or 2 teleport fields for every letter exist, teleporters are valid
    if(!((teleport_amount == 0) || (teleport_amount == 2)))
    {
      std::cout << "db: invalid teleport." << std::endl;
      return false;
    }
  }
  return true;
}










bool Loader::readOneRow(ifstream& cur_file, vector<char>& teleport_list,
                        bool& found_start, bool& found_end, int row_count, Coordinates*& start_point)
{
  int y = row_count;
  vector<Field*> row;
  string row_string = "";
  unsigned long int nr_of_fields;
  
  getline(cur_file, row_string);
  nr_of_fields = row_string.size();
  for (int x = 0; x < nr_of_fields; x++)
  {
    bool valid_char = false;
    char symbol = row_string[x];
    
    
    /*Generating the Field*/
    if(symbol == '#')
    {
      row.push_back(new Wall(x, y));
      valid_char = true;
    }
    
    if(symbol == ' ')
    {
      row.push_back(new Path(x,y));
      valid_char = true;
    }
    
    if((symbol == 'o') && (found_start == false))
    {
      row.push_back(new Start(x,y));
      start_point = new Coordinates(x,y);
      valid_char = true;
      found_start = true;
    }
    else if ((symbol == 'o') && (found_start == true))
    {
      std::cout << "db: ERR found second start tile." << std::endl;
      return false;
    }
    
    if(symbol == '+')
    {
      row.push_back(new Ice(x,y));
      valid_char = true;
      //std::cout << "db: + at (" << i << "," << j << ")" <<std::endl;
    }
    
    if((symbol == 'x') && (found_end == false))
    {
      
      row.push_back(new Finish(x,y));
      valid_char = true;
      found_end = true;
      //std::cout << "db: x at (" << i << "," << j << ")" <<std::endl;
    }
    else if((symbol == 'x') && (found_end == true))
    {
      std::cout << "db: ERR found second end tile" << std::endl;
      return false;
    }

    if((symbol >= 65 ) && (symbol <= 90))
    {
      string str;
      str.push_back(symbol);
      row.push_back(new Teleport(x, y, str));
      teleport_list.push_back(symbol);
      valid_char = true;
      str.clear();
    }
    
    if((symbol == '<') || (symbol == '>') || (symbol == 'v')
       ||(symbol == '^'))
    {
      string str;
      str.push_back(symbol);
      row.push_back(new OneWay(x,y,str));
      valid_char = true;
      str.clear();
    }
    
    if((symbol >= 97 ) && (symbol <= 106))
    {
      string str;
      str.push_back(symbol);
      row.push_back(new Bonus(x, y, str));
      valid_char = true;
      str.clear();
    }
    
    if(valid_char == false)
    {
      std::cout << "db: illigal input." << std::endl;
      return false;
    }
  }
  loaded_board_.push_back(row);
  return true;
}


