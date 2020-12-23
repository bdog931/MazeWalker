/*** Brandon Harrell, Executive.cpp, October 19, 2020, Executive Class File Implementation ***/

#include "Executive.h"

Executive::Executive(std::string& argument)
{
	m_string = argument;
}

void Executive::run()
{
	Maze myMaze(m_string);
	myMaze.run();
}