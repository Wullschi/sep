//------------------------------------------------------------------------------
// Filehandler.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Filehandler.h"


//------------------------------------------------------------------------------
Filehandler::Filehandler(std::string filename) : filename_(filename)
{
}

//------------------------------------------------------------------------------
Filehandler::~Filehandler() throw()
{
}


//------------------------------------------------------------------------------
const bool Filehandler::filenameIsValid() const
{
  
  if (filename_.length() > 255)
  {
    return false;
  }
  
  for (std::size_t character_position = 0;
       character_position < filename_.length(); character_position++)
  {
    char filename_character = filename_[character_position];
    if ( (filename_character < '.')
        || ( (filename_character > '9') && (filename_character < 'A') )
        || ( (filename_character > 'Z') && (filename_character < 'a') )
        || (filename_character > 'z') )
    {
      return false;
    }
  }
  
  return true;
  
}
