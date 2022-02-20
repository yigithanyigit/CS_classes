#include "stdio.h"
#include "stdbool.h"
#include "utils.h"
#include "stdlib.h"


// Necessary Data types and constant definitions for Maze
#define  WALL "\xDB\xDB"   // Full-cursor character
#define  EMPTY "  "
#define  EXIT  "\xDA\xBF"  // Special box-like character
#define  ROBOT "* "





// Define a datatype to represent a cell of a maze MazeCell

typedef enum MazeCell { Empty = 0, Wall= 1, Exit= 2, Outside} MazeCell;













// Define a datatype to represent a Maze
#define MAZESIZE 10
typedef MazeCell Maze[MAZESIZE][MAZESIZE];










































// Define a data type to represent Direction

typedef enum Direction{ Up =0, Left = 1, Down= 2, Right=3} Direction;

















// write a function that returns the opposite of  given Direction without if-s (oppositeOf)

Direction oppositeOf(Direction d)
{
	return (d + 2) % 4;
}


















// Define a data type to represent a Position in a maze
#define DIMENSIONCOUNT 2
typedef int Position[DIMENSIONCOUNT];
#define ROW 0
#define COL 1





















// Define a (arbitrary) global Maze variable 
Maze maze = {	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
				{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
				{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 1 },
				{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
				{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
				{ 1, 0, 0, 0, 1, 0, 1, 0, 1, 1 },
				{ 1, 1, 1, 1, 1, 0, 1, 0, 1, 1 },
				{ 1, 0, 0, 0, 0, 0, 1, 2, 1, 1 },
				{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
				{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }, };


















// Define an arbitrary global variable for the position of the robot
Position robot = { 2,1 };




void printRobot()
{
	printf(ROBOT);
}

void printMazeCell(MazeCell cell)
{
	if (cell == Empty)
		printf(EMPTY);
	else if (cell ==Wall)
			printf(WALL);
	else if (cell == Exit)
		printf(EXIT);
}


// Write a function that prints a given maze (printMaze) with a given robot at a given position
void printMaze(Maze maze, Position robot)
{
	clearScreen();

	for (int row = 0; row < MAZESIZE; ++row)
	{
		for (int col = 0; col < MAZESIZE; ++col)
		{
			if (robot[ROW] == row && robot[COL] == col)
				printRobot();
			else
				printMazeCell(maze[row][col]);
		}
		printf("\n");
	}

	waitForSomeTime();
}




















































// Write a function that returns if a given  position is inside the maze or not (isInside)
bool isInside(Position pos)
{
	return (pos[ROW] >= 0 && pos[ROW] < MAZESIZE && pos[COL] >= 0 && pos[COL] < MAZESIZE);
}









































// Write a function that returns the cell at a given Position in a given Maze (getCell)
MazeCell getCell(Maze maze, Position pos)
{
	if (isInside(pos))
		return maze[pos[ROW]][pos[COL]];
	else return Outside;
}
















// Write a function that returns if a given  position is exit in the given maze(isExit)
bool isExit(Maze maze, Position pos)
{
	return (getCell(maze, pos) == Exit);
}











// Write a function that copies a position into another position(copyPosition)
void copyPosition(Position pos, Position other )
{
	for (int i = 0; i < DIMENSIONCOUNT; ++i)
	{
		other[i] = pos[i];
	}
}




















// Write a function that moves a given position towards a given direction (movePosition)
void movePositionWithIf(Position pos, Direction dir)
{
	if (dir == Up)
		pos[ROW]--;
	else if (dir == Down)
		pos[ROW]++;
	else if (dir == Right)
		pos[COL]++;
	else if (dir == Left)
		pos[COL]--;
}























// Rewrite movePosition function without using if-s or switch


int deltaPosition[][2] = { { -1,0}, {0,-1}, {1,0}, {0,1} };
void movePosition(Position pos, Direction dir)
{
	pos[ROW] = pos[ROW] + deltaPosition[dir][ROW];
	pos[COL] = pos[COL] + deltaPosition[dir][COL];
}




















// Write a function that returns the neighbor cell of the cell at a given position in a given Maze 
// towards a given direction (neighborOf)

MazeCell neighborOf(Maze maze, Position pos, Direction dir)
{
	Position tmp;
	copyPosition(pos, tmp);
	movePosition(tmp, dir);
	return getCell(maze,tmp);
}



























// Write a function that returns if It is possible to move at a given Position
// towards a given direction in a given maze (canMove)

bool canMove(Maze maze, Position pos, Direction dir)
{
	MazeCell neighbor = neighborOf(maze, pos, dir);
	return (neighbor == Empty || neighbor == Exit);
}






















// Write a function that moves a given position towards a given direction if it is possible in a given maze. 
// Returns true if moved,false otherwise (tryMove) 
bool tryMove(Maze maze, Position pos, Direction dir)
{
	if (canMove(maze, pos, dir))
	{
		movePosition(pos, dir);
		return true;
	}
	else return false;
}
























// Write a function that randomly moves a robot at a given position in a given maze
// The function should print the maze at each step and stop when the robot moves to exit (moveRandomly)

#define DIRECTIONCOUNT 4

void moveRandomly(Maze maze, Position robot)
{
	while ( !isExit(maze,robot))
	{
		Direction d = randomBelow(DIRECTIONCOUNT);
		if (tryMove(maze, robot, d))
			printMaze(maze, robot);
	}
}
































// Write a function that randomly moves a robot at a given position in a given maze
// The function should print the maze at each step and stop when the robot moves to exit 
// When the robot choose a random direction he should go in that direction until it hits the wall (moveRandomlyButDetermined)



void moveRandomlyWallE(Maze maze, Position robot)
{
	while (!isExit(maze, robot))
	{
		Direction d = randomBelow(DIRECTIONCOUNT);
		while (tryMove(maze, robot, d) && !isExit(maze, robot))
			printMaze(maze, robot);
	}
}








































// Write a function that moves the robot to one of the exits in a given maze
void findExit(Maze maze, Position robot)
{
	
}


















void main()
{
	randomize();

	moveRandomlyWallE(maze, robot);

	return;
}

