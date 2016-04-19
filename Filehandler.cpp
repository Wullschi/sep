//------------------------------------------------------------------------------
// Filehandler.cpp
//
// Group: Group 13717, study assistant Pascal Nasahl
//
// Authors: <Name> <Matriculum Number>
// <Name> <Matriculum Number>
// <Add one row for every additional group member>
//------------------------------------------------------------------------------
//


#include "Filehandler.h"


Filehandler::Filehandler(std::string filename) : filename_(filename)
{
   
}


const bool Filehandler::filenameIsValid() const
{
  
  for (int character_position = 0; character_position < filename_.length(); character_position++)
  {
    int character_value = static_cast<int>(filename_[character_position]);
    if ( (character_value < 46)
        || ( (character_value > 57) && (character_value < 65) )
        || ( (character_value > 90) && (character_value < 97) )
        || (character_value > 122) )
    {
      return false;
    }
  }

  return true;

}
