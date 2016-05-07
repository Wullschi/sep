//------------------------------------------------------------------------------
// UserInput.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "UserInput.h"

#include "Message.h"
#include "Game.h"
#include "Saver.h"
#include "Load.h"
#include "Save.h"
#include "Move.h"
#include "Fastmove.h"
#include "Reset.h"
#include "Show.h"
#include "Quit.h"


using std::string;


const std::string UserInput::PROMPT_ = "sep>";

const std::string UserInput::LOAD_OPTION_ = "-m";
const std::string UserInput::AUTOSAVE_OPTION_ = "-s";
const std::string UserInput::LOAD_ = "load";
const std::string UserInput::SAVE_ = "save";
const std::string UserInput::MOVE_ = "move";
const std::string UserInput::FASTMOVE_ = "fastmove";
const std::string UserInput::RESET_ = "reset";
const std::string UserInput::SHOW_ = "show";
const std::string UserInput::QUIT_ = "quit";

std::string UserInput::entered_command_ = "";
std::vector<std::string> UserInput::entered_arguments_;


//--------------------------------------------------------------------------
int UserInput::checkCommandLineOptions(int argc, const char* argv[],
    Game*& current_game)
{
  
  if ( (argc % 2 == 0) || (argc > 5) )
  {
    return WRONG_USAGE_RETURN_;
  }
  
  bool initial_load = false;
  std::string argument_string = "";
  std::vector<std::string> load_filenames;
  
  for (int argument_no = 1; argument_no < argc - 1; argument_no += 2)
  {
    argument_string = static_cast<std::string>(argv[argument_no]);
    
    if (argument_string == LOAD_OPTION_)
    {
      if ( (initial_load == true)
          || (argv[argument_no + 1] == AUTOSAVE_OPTION_)
          || (argv[argument_no + 1] == LOAD_OPTION_) )
    {
        return WRONG_USAGE_RETURN_;
      }
      initial_load = true;
      load_filenames.push_back( argv[argument_no + 1] );
    }
    else if (argument_string == AUTOSAVE_OPTION_)
    {
      if ( (Saver::isAutosaveActive())
          || (argv[argument_no + 1] == LOAD_OPTION_)
          || (argv[argument_no + 1] == AUTOSAVE_OPTION_) )
      {
        return WRONG_USAGE_RETURN_;
      }
      Saver::enableAutosave(argv[argument_no + 1]);
    }
    else
    {
      return WRONG_USAGE_RETURN_;
    }
    
  }
  
  if (initial_load)
  {
    
    Load initial("initial");
    Command::Status return_status = initial.execute(current_game,
        load_filenames);
    
    if (return_status)
    {
      Message::outputByCode(return_status);
    }
    
    if (return_status == Command::OUT_OF_MEMORY_)
    {
      return return_status;
    }
    
  }
  
  return OK_;
  
}


//--------------------------------------------------------------------------
void UserInput::parseUserInput(std::string user_input)
{
  
  char previous_character = ' ';
  std::string argument = "";
  bool end_of_command = false;
  
  
  for (unsigned int character_position = 0;
      character_position < user_input.length(); character_position++)
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


//--------------------------------------------------------------------------
int UserInput::commandLine(Game*& current_game)
{
  
  
  std::string user_input = "";
  Command::Status return_status = Command::OK_;
  
  
  do
  {
    
    entered_command_ = "";
    entered_arguments_.clear();
    
    
    std::cout << PROMPT_ << " ";
    std::getline(std::cin, user_input);
    
    parseUserInput(user_input);
    
    if (entered_command_ == LOAD_)
    {
      Load load("load");
      return_status = load.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == SAVE_)
    {
      Save save("save");
      return_status = save.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == MOVE_)
    {
      Move move("move");
      return_status = move.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == FASTMOVE_)
    {
      Fastmove fastmove("fastmove");
      return_status = fastmove.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == RESET_)
    {
      Reset reset("reset");
      return_status = reset.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == SHOW_)
    {
      Show show("show");
      return_status = show.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == QUIT_)
    {
      Quit quit("quit");
      return_status = quit.execute(current_game, entered_arguments_);
    }
    
    else if (entered_command_ == "")
    {
      return_status = Command::OK_;
    }
    
    else
    {
      Message::outputUnknownCommand();
      return_status = Command::OK_;
    }
    
    if (return_status)
    {
      Message::outputByCode(return_status);
    }
    
  }
  while ( (return_status != Command::QUIT_) &&
      (return_status != Command::OUT_OF_MEMORY_) );
  
  return (return_status == Command::QUIT_) ? OK_ : return_status;
  
}
