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

Loader::Loader()
{
  
}

Loader::~Loader()
{
  
}


/*Loading function*/
int Loader::load(Game*& game, const std::string filename)
{
  const char* LOADFILE = filename.c_str();
  Coordinates* start_point = 0;
  /*Initialisierungen*/
  std::ifstream cur_file;
  char cur_char = '\0';
  bool valid_char;
  std::string str = "";
  bool found_start = false;
  bool found_end = false;
  bool checking_board = false;
  int field_length = 0;
  int field_height = 0;
  bool field_length_switch = false;
  cur_file.open(LOADFILE);
  std::vector<char> teleportList;
  if(cur_file.is_open())
  {
    //std::cout << "db: opened loadfile" << std::endl;
    /*Reading the file*/
    std::vector<Field*> Row;
    int i = 0;
    int j = 0;
    
    while(!cur_file.eof())
    {
      //cur_char = '\t';
      cur_file.get(cur_char);
      
      if(cur_file.eof())
      {
        break;
      }
      
      if(checking_board == true)
      {
        valid_char = false;
        /*New line found*/
        if(cur_char == '\n')
        {
          //end of line
          j++;
          if(field_length_switch == false)
          {
            field_length = i;
            field_length_switch = true;
          }
          //std::cout << "db: value of i: " << i << std::endl;
          i = -1; //to avoid one off error
          loaded_board_.push_back(Row);
          valid_char = true;
          Row.clear();
        }
        /*Generating the Field*/
        if(cur_char == '#')
        {
          Row.push_back(new Wall(i,j));
          valid_char = true;
          //std::cout << "db: # at (" << i << "," << j << ")" <<std::endl;
        }
        if(cur_char == ' ')
        {
          Row.push_back(new Path(i,j));
          valid_char = true;
          //std::cout << "db: ' ' at (" << i << "," << j << ")" <<std::endl;
        }
        if(cur_char == 'o')
        {
          if(found_start == false)
          {
            Row.push_back(new Start(i,j));
            start_point = new Coordinates(i,j);
            valid_char = true;
            found_start = true;
            //std::cout << "db: o at (" << i << "," << j << ")" <<std::endl;
          }else
          {
            std::cout << "db: ERR found second start tile." << std::endl;
            return 5;
          }
          
        }
        if(cur_char == '+')
        {
          Row.push_back(new Ice(i,j));
          valid_char = true;
          //std::cout << "db: + at (" << i << "," << j << ")" <<std::endl;
        }
        if(cur_char == 'x')
        {
          if(found_end == false)
          {
            Row.push_back(new Finish(i,j));
            valid_char = true;
            found_end = true;
            //std::cout << "db: x at (" << i << "," << j << ")" <<std::endl;
          }else
          {
            std::cout << "db: ERR found second end tile" << std::endl;
          }
          
        }
        if((cur_char >= 65 ) && (cur_char <= 90))
        {
          str.push_back(cur_char);
          Row.push_back(new Teleport(i,j,str));
          teleportList.push_back(cur_char);
          valid_char = true;
          //std::cout << "db: "<< str <<" at (" << i << "," << j << ")" <<std::endl;
          str.clear();
        }
        if((cur_char == '<')||(cur_char == '>')||(cur_char == 'v')
           ||(cur_char == '^'))
        {
          str.push_back(cur_char);
          Row.push_back(new OneWay(i,j,str));
          valid_char = true;
          //std::cout << "db: "<< str <<" at (" << i << "," << j << ")" <<std::endl;
          str.clear();
        }
        if((cur_char >= 97 ) && (cur_char <= 106))
        {
          str.push_back(cur_char);
          Row.push_back(new Bonus(i,j,str));
          valid_char = true;
          //std::cout << "db: "<< str <<" at (" << i << "," << j << ")" <<std::endl;
          str.clear();
        }
        if(valid_char == false)
        {
          std::cout << "db: illigal input." << std::endl;
        }
        i++; //counter horizontal.
      }
      else
      /*Noch nicht im Feld, Schritte und bisheriger Pfad*/
      {
        /* Bisheriger Pfad + mögliche schritte hierher */
        if(cur_char == '#')
        {
          i = 0;
          j = 0;
          Row.push_back(new Wall(i,j));
          checking_board = true;
        }
      }
      
    }
    if(cur_file.eof())
    {
      j++;
      loaded_board_.push_back(Row);
    }
    
    /*Start und End tile existieren*/
    if((found_start)&&(found_end))
    {
      field_height = j;
      //std::cout << "db: i: " << field_length << " j: " << field_height << std::endl;
      //std::cout << "db: Found start and end tile." << std::endl;
      
      /*Check for valid field*/
      Field *fptr = 0;
      //Check ob das Feld die richtige größe hat
      for(int i = 0; i < field_height-1; i++)
      {
        Row = loaded_board_.at(i);
        //std::cout << Row.size() << std::endl;
        //std::cout << fptr->getFieldSymbol() << std::endl;
        if( Row.size() != field_length+1)
        {
          std::cout << "db: illigeal input. Field is to short or long." << std::endl;
          //exception hierher
          break;
        }
      }
      /*Check ob alle Symbole gültig sind*/
      Row = loaded_board_.at(0);
      for(int k = 0; k <= field_length; k++)
      {
        fptr = Row.at(k);
        if(fptr->getFieldSymbol() != "#")
        {
          std::cout << "db: ERR invalid field" << std::endl;
        }
      }
      for(int k = 1; k < field_height-2; k++)
      {
        Row = loaded_board_.at(k);
        fptr = Row.front();
        if(fptr->getFieldSymbol() != "#")
        {
          std::cout << "db: ERR invalid field" << std::endl;
        }
        fptr = Row.back();
        if(fptr->getFieldSymbol() != "#")
        {
          std::cout << "db: ERR invalid field" << std::endl;
          break;
        }
      }
      //std::cout << "db: size of loaded board: " << loaded_board_.size() << std::endl;
      Row = loaded_board_.at(field_height-2);
      for(int k = 0; k <= field_length; k++)
      {
        fptr = Row.at(k);
        if(fptr->getFieldSymbol() != "#")
        {
          std::cout << "db: ERR invalid field 1  " << field_height <<std::endl;
          break;
        }
      }
      /*Check for valid Teleporter*/
      //std::cout << "db: teleportList.size() = " << teleportList.size() << std::endl;
      int teleport_amount;
      for(int l = 65; l <= 90; l++)
      {
        teleport_amount = 0;
        for(int k = 0; k < teleportList.size(); k++)
        {
          if(teleportList.at(k) == l)
          {
            teleport_amount++;
          }
        }
        if(!((teleport_amount == 0) || (teleport_amount == 2)))
        {
          std::cout << "db: invalid teleport." << std::endl;
        }
      }
    }else
    {
      /*Start und End tile existieren nicht*/
      std::cout << "db: ERR no valid start or end tile." << std::endl;
    }
  }else
  {
    std::cout << "db: can't find "<< filename << std::endl;
    return 4;
  }
  
  game = new Game(loaded_board_, "", 10, start_point);
  
  return 0;
}