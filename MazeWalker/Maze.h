#pragma once
/*** Brandon Harrell, Maze.h, October 19, 2020, Maze Class Declaration ***/

#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <fstream>
#include <iostream>

class Maze
{
private:
	std::string m_FileToOpen;
	int m_numRows;
	int m_numCols;
	int m_startingRow;
	int m_startingCol;
	int m_counter;
	char** m_maze;
	int** m_visited;

public:

	/***
	pre: None
	post: Member variables initialized if need be
	exceptions: None
	parameters: string by reference
	***/

	Maze(std::string& execString);

	/***
	pre: Maze Object Exist
	post: All needed methods called as needed
	exceptions: None
	parameters: None
	***/

	void run();

	/***
	pre: Maze Exist and has been read
	post: returns true if it has found the path
	exceptions: None
	parameters: row and column values
	***/

	bool recursive(int row, int col);

	/***
	pre: Maze Object has been created
	post: Maze and Visited Maze are initialized
	exceptions: None
	parameters: string by reference
	***/

	void read(std::string& m_FileToOpen);

	/***
	pre: Maze and Visited have been allocated
	post: Dynamically Allocated variables have been deallocated
	exceptions: None
	parameters: None
	***/

	void deAllocateMaze();

	/***
	pre: Start Position Exist
	post: Returns true or false
	exceptions: None
	parameters: None
	***/

	bool startPositionIsValid();

	/***
	pre: Visited Maze Exist and Counter has been initialized
	post: Visited Maze Updated and Counter Incremented
	exceptions: None
	parameters: row and column position
	***/

	void mark(int row, int col);

	/***
	pre: None
	post: Returns true or false
	exceptions: None
	parameters: row and column position
	***/

	bool isValid(int row, int col);

	/***
	pre: Visited Maze must exist and counter initialized
	post: Changes row col value in Visited Maze to 0 and decrements counter
	exceptions: None
	parameters: row and column position
	***/

	void unMark(int row, int col);
};

#endif