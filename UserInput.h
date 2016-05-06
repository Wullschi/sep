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

//------------------------------------------------------------------------------
// Class for handling all input entered by the user
// incl. command line arguments when calling the programme
//
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
    // Constant for the return value if no error occurs
    //
    static const int OK_ = 0;
    
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
    
    //--------------------------------------------------------------------------
    // Parses the command line arguments given when calling the programme and
    // triggers the requested commands or outputs
    // an error message if the arguments are not valid.
    //
    // @param argc Number of commands given (1 if none)
    // @param argv array of given arguments
    // @param current_game If loading of a game has been requested,
    //        this pointer stores the address of the loaded game.
    //
    // @return Constant indicating:
    //         OK_ if there are no arguments or the arguments are valid,
    //         Command::OUT_OF_MEMORY_ if a bad_alloc exception has occured,
    //         WRONG_USAGE_RETURN_ if the arguments  are not valid.
    //
    static int checkCommandLineOptions(int argc,
        const char* argv[], Game*& current_game);
    
    //--------------------------------------------------------------------------
    // Extracts the command and possible parameters
    // from the string passed to this method.
    // The first word of the string is interpreted as command
    // and stored in entered_command_, the subsequent words are
    // interpreted as parameters and stored in entered_arguments_.
    //
    // @param user_input The input line to be parsed
    //
    static void parseUserInput(std::string user_input);
    
    //--------------------------------------------------------------------------
    // Performs the user interface:
    // It prints the prompt specified by PROMPT_,
    // takes the input text by the user, passes it to parseUserInput,
    // and triggers the appropriate command. It terminates if the user
    // enters the command specified by QUIT_ or if a bad_alloc exception is thrown.
    //
    // @param current_game When a game is loaded, this pointer stores its address.
    //
    // @return Constant indicating why the method has been terminated:
    //         OK_ if by QUIT_ command,
    //         Command::OUT_OF_MEMORY_ if by bad_alloc exception.
    //
    static int commandLine(Game*& current_game);
    
};


#endif
