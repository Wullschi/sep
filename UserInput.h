//------------------------------------------------------------------------------
// UserInput.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Christopher Kopel 0730613
//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>


class Game;
class UserInput
{
  
  private:
    static std::string entered_command_;
    static std::vector<std::string> entered_arguments_;
    
    UserInput();
    
    
  public:
    static const std::string PROMPT_;
    
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
