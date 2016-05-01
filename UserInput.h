//------------------------------------------------------------------------------
// UserInput.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef USER_INPUT_H_INCLUDED
#define USER_INPUT_H_INCLUDED


#include <string>
#include <vector>


class Game;
class UserInput
{
  private:
    
    //--------------------------------------------------------------------------
    // Attribute for the command entered by the user
    //
    static std::string entered_command_;
    //--------------------------------------------------------------------------
    // Attribute for the command parameters entered by the user
    //
    static std::vector<std::string> entered_arguments_;
    
    //--------------------------------------------------------------------------
    // Private constructor (because this is a singleton class)
    //
    UserInput();
    
  public:
    
    //--------------------------------------------------------------------------
    // Constant for the value returned to the OS in case of wrong
    // command line parameters when calling the main programme
    //
    static const int WRONG_USAGE_RETURN_ = 2;
    
    //--------------------------------------------------------------------------
    // Constant for the prompt displayed when waiting for user input
    //
    static const std::string PROMPT_;
    
    //--------------------------------------------------------------------------
    // Constants for the command line options when calling the main programme
    //
    static const std::string LOAD_OPTION_;
    static const std::string AUTOSAVE_OPTION_;
    
    //--------------------------------------------------------------------------
    // Constants for each of all possible commands
    //
    static const std::string LOAD_;
    static const std::string SAVE_;
    static const std::string MOVE_;
    static const std::string FASTMOVE_;
    static const std::string RESET_;
    static const std::string SHOW_;
    static const std::string QUIT_;
    
    static int checkCommandLineOptions(int argc,
        const char* argv[], Game*& current_game);
    static void parseUserInput(std::string user_input);
    static int commandLine(Game*& current_game);
    
};


#endif
