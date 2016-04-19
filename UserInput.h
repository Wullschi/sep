//
//  UserInput.hpp
//  SEP Basisbeispiel
//
//  Created by Benjamin on 28.03.16.
//  Copyright © 2016 Benjamin. All rights reserved.
//


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
    static const std::string QUIT_MESSAGE_;
    static int checkCommandLineOptions(int argc, const char* argv[], Game*& current_game);
    static void parseUserInput(std::string user_input);
    static void commandLine(Game*& current_game);
    
};
