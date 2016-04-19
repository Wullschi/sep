//
//  UserInput.cpp
//  SEP Basisbeispiel
//
//  Created by Benjamin on 28.03.16.
//  Copyright © 2016 Benjamin. All rights reserved.
//


#include "UserInput.h"

#include "Game.h"
#include "Saver.h"
#include "Load.h"
#include "Move.h"



using std::string;
using std::cout;
using std::endl;

const string UserInput::QUIT_MESSAGE_ = "Bye!\n";
string UserInput::entered_command;
std::vector<std::string> UserInput::entered_arguments;
const string UserInput::PROMPT_ = "sep>";


int UserInput::checkCommandLineOptions(int argc, const char* argv[], Game* current_game)
{
  
  if ( (argc == 2) || (argc == 4) || (argc > 5) )
  {
    cout << "Wrong number of arguments!" << endl;
    return 2;
  }
  
  std::string argument_string;

  for (int argument_no = 1; argument_no < argc - 1; argument_no += 2)
  {  
    argument_string = static_cast<std::string>(argv[argument_no]);
    if (argument_string.compare("-m") == 0)
    {
      Load initial_load("initial");
      std::vector<std::string> filenames;
      filenames.push_back( argv[argument_no + 1] );
      initial_load.execute(current_game, filenames);
    }
    else if (argument_string.compare("-s") == 0)
    {
      Saver::enableAutosave(argv[argument_no + 1]);
    }
    else
    {
      cout << "Wrong arguments!" << endl;
      return 2;
    }
  
  }

  return 0;
  
  }


void UserInput::parseUserInput(std::string user_input)
{

  char previous_character = ' ';
  std::string argument = "";
  bool end_of_command = false;
  
  
  for (unsigned int character_position = 0; character_position < user_input.length(); character_position++)
  {
    
    if (user_input[character_position] != ' ')
    {
      if (!end_of_command)
      {
        entered_command += tolower(user_input[character_position]);
      }
      else
      {
        argument += user_input[character_position];
      }
    }
    else if (previous_character != ' ')
    {
      if (end_of_command)
      {
        entered_arguments.push_back(argument);
        argument = "";
      }
      else
      {
        end_of_command = true;
      }
    }
    
    previous_character = user_input[character_position];
    
  }
  
  if (argument != "")
  {
    entered_arguments.push_back(argument);
    argument = "";
  }


}
  
  
  
void UserInput::commandLine(Game*& current_game)
{
  
  
  std::string user_input = "";
  
  
  do
  {
    
    entered_command = "";
    entered_arguments.clear();
    
    
    std::cout << PROMPT_ << " ";
    std::getline(std::cin, user_input);
    
    parseUserInput(user_input);
    
    if (entered_command == "load")
    {
      Load load("load");
      load.execute(current_game, entered_arguments);
    }
    
    else if (entered_command == "save")
    {
      
    }
        
    else if (entered_command == "move")
    {
      Move move("move");
      move.execute(current_game, entered_arguments);
    }
    
    else if (entered_command == "fastmove")
    {
      
    }
        
    else if (entered_command == "reset")
    {
      
    }
        
    else if (entered_command == "show")
    {
      
    }
        
    else if (entered_command == "quit")
    {
      std::cout << QUIT_MESSAGE_ << std::endl;
    }
    
    else if (entered_command == "")
    {
      
    }
    
    else
    {
      cout << "Wrong command!" << endl;
    }
    
  } while (entered_command != "quit");
     
     
      
}
