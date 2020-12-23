/*** Brandon Harrell, main.cpp, October 19, 2020, Main File ***/

#include <iostream>
#include <string>
#include "Executive.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "You have failed to pass in the correct amount of arguments." << std::endl;
		std::cout << "Valid Example: './Maze MazeFile.txt'." << std::endl;
	}
	else
	{
		std::string argument = argv[1];
		Executive exec(argument);
		exec.run();
	}
	return(0);
}