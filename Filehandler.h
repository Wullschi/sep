//------------------------------------------------------------------------------
// Filehandler.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED


#include <string>


class Filehandler
{
  
  private:
    Filehandler(const Filehandler &);
  
  protected:
    std::string filename_;
    
    
  public:
    Filehandler(std::string filename);
    const bool filenameIsValid() const;
    
};


#endif
