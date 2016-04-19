//------------------------------------------------------------------------------
// Filehandler.h
//
// Group: Group 13717, study assistant Pascal Nasahl
//
// Authors: <Name> <Matriculum Number>
// <Name> <Matriculum Number>
// <Add one row for every additional group member>
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
