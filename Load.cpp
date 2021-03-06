//------------------------------------------------------------------------------
// Load.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Load.h"

#include "Game.h"
#include "Loader.h"
#include "Saver.h"
#include "Save.h"
#include "Show.h"
#include "Message.h"

//------------------------------------------------------------------------------
Load::Load(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
Load::~Load() throw()
{
}


//------------------------------------------------------------------------------
Command::Status Load::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    return WRONG_PARAMETER_COUNT_;
  }
  
  Loader gameloader(params.front());
  
  if (!gameloader.filenameIsValid())
  {
    return WRONG_PARAMETER_;
  }
  
  Game* new_board = 0;
  
  Command::Status return_status = gameloader.load(new_board);
  
  if (return_status > 0)
  {
    return return_status;
  }
    
  if (board)
  {
    delete board;
  }
  
  board = new_board;
  
  if (Saver::isAutosaveActive())
  {
    
    std::vector<std::string> autosave_params = Saver::getAutosaveParams();
    Save autosave("autosave");
    Command::Status autosave_status =
        autosave.execute(board, autosave_params);
    
    if (autosave_status)
    {
      Message::outputByCode(autosave_status);
    }
    
  }
  
  Show implicit_show("implicit_show");
  std::vector<std::string> show_params;
  implicit_show.execute(board, show_params);
  
  return return_status;
  
}
