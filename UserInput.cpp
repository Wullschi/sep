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
#include "Save.h"
#include "Move.h"
#include "Fastmove.h"
#include "Reset.h"
#include "Show.h"



using std::string;
using std::cout;
using std::endl;

const string UserInput::QUIT_MESSAGE_ = "Bye!\n";
const string UserInput::PROMPT_ = "sep>";

string UserInput::entered_command_ = "";
std::vector<std::string> UserInput::entered_arguments_;


int UserInput::checkCommandLineOptions(int argc, const char* argv[], Game*& current_game)
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
        entered_command_ += tolower(user_input[character_position]);
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
        entered_arguments_.push_back(argument);
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
    entered_arguments_.push_back(argument);
    argument = "";
  }


}
  
  
  
void UserInput::commandLine(Game*& current_game)
{
  
  
  std::string user_input = "";
  
  
  do
  {
    
    entered_command_ = "";
    entered_arguments_.clear();
    
    
    std::cout << PROMPT_ << " ";
    std::getline(std::cin, user_input);
    
    parseUserInput(user_input);
    
    if (entered_command_ == "load")
    {
      Load load("load");
      load.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == "save")
    {
      Save save("save");
      save.execute(current_game, entered_arguments_);
    }
        
    else if (entered_command_ == "move")
    {
      Move move("move");
      move.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == "fastmove")
    {
      Fastmove fastmove("fastmove");
      fastmove.execute(current_game, entered_arguments_);
    }
        
    else if (entered_command_ == "reset")
    {
      Reset reset("reset");
      reset.execute(current_game, entered_arguments_);
    }
        
    else if (entered_command_ == "show")
    {
      Show show("show");
      show.execute(current_game, entered_arguments_);
    }
        
    else if (entered_command_ == "quit")
    {
      std::cout << QUIT_MESSAGE_ << std::endl;
    }
    
    else if (entered_command_ == "")
    {
      
    }
    
    else
    {
      cout << "Wrong command!" << endl;
    }
    
  } while (entered_command_ != "quit");
     
     
      
}
