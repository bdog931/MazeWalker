/*** Brandon Harrell, Maze.cpp, October 19, 2020, Maze Class Implementation ***/

#include "Maze.h"

Maze::Maze(std::string& execString)
{
	m_FileToOpen = execString;
	m_counter = 0;
	m_maze = nullptr;
	m_visited = nullptr;
}

void Maze::run()
{
	//Reading in Maze from the Input File
	read(m_FileToOpen);
	if (startPositionIsValid())
	{
		std::cout << "Starting position at coordinates: " << m_startingRow << ", " << m_startingCol << std::endl;
		std::cout << "Size: " << m_numRows << " by " << m_numCols << std::endl;
		//Checking to see if maze is traversible
		if (recursive(m_startingRow, m_startingCol))
		{
			for (int i = 0; i < m_numRows; i++)
			{
				for (int j = 0; j < m_numCols; j++)
				{
					std::cout << m_visited[i][j];
					//Spacing to make it pretty
					//Should be pretty as long as thing are smaller than 100 steps
					if (m_visited[i][j] < 10)
					{
						std::cout << "       ";
					}
					else
					{
						std::cout << "      ";
					}
				}
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << "The maze is intraversible. " << std::endl;
		}
	}
	else
	{
		std::cout << "Invalid start position." << std::endl;
	}
	deAllocateMaze();
}

bool Maze::recursive(int row, int col)
{
	mark(row, col);
	//Is this itself the exit?
	if (m_maze[row][col] == 'E')
	{
		return(true);
	}
	//Looking Up, Right, Down, Left
	if (isValid(row - 1, col))
	{
		//Want to return true if it leads to an exit
		if (recursive(row - 1, col) == true)
		{
			return(true);
		}
	}
	if (isValid(row, col + 1))
	{
		if (recursive(row, col + 1))
		{
			return(true);
		}
	}
	if (isValid(row + 1, col))
	{
		if (recursive(row + 1, col))
		{
			return(true);
		}
	}
	if (isValid(row, col - 1))
	{
		if (recursive(row, col - 1))
		{
			return(true);
		}
	}
	unMark(row, col);
	return(false);
}

void Maze::read(std::string& m_FileToOpen)
{
	//Creating then Opening InFile Object
	std::ifstream InFileObject;
	InFileObject.open(m_FileToOpen);
	if (InFileObject.is_open())
	{
		//Initialize Number of Rows and Cols, starting rows and cols
		m_numRows = 0;
		m_numCols = 0;
		m_startingRow = 0;
		m_startingCol = 0;

		//Reading in Values
		InFileObject >> m_numRows;
		InFileObject >> m_numCols;
		InFileObject >> m_startingRow;
		InFileObject >> m_startingCol;

		//Creating 2D array from the input file
		//m_arrays points to character pointers, each of which will have its own array
		m_maze = new char* [m_numRows];
		for (int i = 0; i < m_numRows; i++)
		{
			m_maze[i] = new char[m_numCols];
		}
		for (int i = 0; i < m_numRows; i++)
		{
			for (int j = 0; j < m_numCols; j++)
			{
				InFileObject >> m_maze[i][j];
			}
		}
		//Constructing Visited Array
		m_visited = new int* [m_numRows];
		for (int i = 0; i < m_numRows; i++)
		{
			m_visited[i] = new int[m_numCols];
		}
		for (int i = 0; i < m_numRows; i++)
		{
			for (int j = 0; j < m_numCols; j++)
			{
				m_visited[i][j] = 0;
			}
		}
		InFileObject.close();
	}
	else
	{
		std::cout << "Infile Object has failed to open." << std::endl;
	}
}
void Maze::deAllocateMaze()
{
	//Deallocating the Maze
	for (int i = 0; i < m_numRows; i++)
	{
		delete[] m_maze[i];
	}
	delete[] m_maze;

	//Deallocating the Visited Array
	for (int i = 0; i < m_numRows; i++)
	{
		delete[] m_visited[i];
	}
	delete[] m_visited;
}
bool Maze::startPositionIsValid()
{
	//Make sure for if invalid because this will cause seg fault
	if (m_maze[m_startingRow][m_startingCol] == 'P' || m_maze[m_startingRow][m_startingCol] == 'E')
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
void Maze::mark(int row, int col)
{
	m_counter = m_counter + 1;
	m_visited[row][col] = m_counter;
}
void Maze::unMark(int row, int col)
{
	m_counter = m_counter - 1;
	m_visited[row][col] = 0;
}
bool Maze::isValid(int row, int col)
{
	if (row >= 0 && row < m_numRows && col >= 0 && col < m_numCols)
	{
		if ((m_maze[row][col] == 'P' || m_maze[row][col] == 'E') && m_visited[row][col] == 0)
		{
			return(true);
		}
	}
	return(false);
}
