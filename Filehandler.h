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


//------------------------------------------------------------------------------
// Base class for loading and saving
// It takes the filename and checks if it is valid.
//
class Filehandler
{
  private:
    
    //------------------------------------------------------------------------------
    // Private copy constructor
    //
    Filehandler(const Filehandler& original);
    //------------------------------------------------------------------------------
    // Private assignment operator
    //
    Filehandler& operator=(const Filehandler& original);
  
  protected:
    
    //------------------------------------------------------------------------------
    // Attribute for the name of the file to load or to save in
    //
    std::string filename_;
    
  public:
    
    //------------------------------------------------------------------------------
    // Constructor
    //
    Filehandler(std::string filename);
    //------------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Filehandler() throw();
    
    const bool filenameIsValid() const;
    
};


#endif
