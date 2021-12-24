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
typedef enum MazeCell { Empty, Wall, Exit, Outside} MazeCell;














// Define a datatype to represent a Maze
#define MAZESIZE 10
typedef MazeCell Maze[MAZESIZE][MAZESIZE];



#define MEMORYSIZE 2*MAZESIZE
typedef int BotMemory[MEMORYSIZE][MEMORYSIZE];

BotMemory memory;








































// Define a data type to represent Direction
typedef enum Direction { Up= 0, Left= 1, Down=2, Right=3} Direction;


















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


Position finger;


















// Define a (arbitrary) global Maze variable 

Maze maze = {		{1,1,1,1,1,1,1,1,1,1},
					{1,0,1,1,0,0,0,2,0,1},
					{1,0,1,1,1,0,1,1,0,1},
					{1,0,1,1,1,1,1,1,0,1},
					{1,0,0,0,0,0,0,0,0,1},
					{1,0,1,1,1,1,0,1,1,1},
					{1,0,1,1,1,1,0,1,1,1},
					{1,0,0,0,0,0,0,1,1,1},
					{1,1,1,0,1,1,0,0,0,1},
					{1,1,1,1,1,1,1,1,1,1} };


















// Define an arbitrary global variable for the position of the robot
Position robot = { 1,1 };



// Write a function that prints a given maze (printMaze) with a given robot at a given position
void printRobot()
{
	printf(ROBOT);
}


void printMazeCell(MazeCell cell)
{
	if (cell == Wall)
		printf(WALL);
	else if (cell == Empty)
		printf(EMPTY);
	else if (cell == Exit)
		printf(EXIT);

}

void printMemory(BotMemory memory)
{
	for (int r = 0; r < MEMORYSIZE; ++r)
	{
		for (int c = 0; c < MEMORYSIZE; ++c)
		{
			if (memory[r][c] >= 0)
				printf("%2d ", memory[r][c]);
			else printf("   ");
		}
		printf("\n");
	}
	waitForSomeTime();
}

void printMaze(Maze maze, Position robot)
{
	clearScreen();

	for (int row = 0; row < MAZESIZE; ++row)
	{
		for (int col = 0; col < MAZESIZE; ++col)
		{
			if (robot[ROW] == row && robot[COL] == col)
				printRobot();
			else printMazeCell(maze[row][col]);
		}
		printf("\n");
	}

	printMemory(memory);
	waitForSomeTime();
}




















































// Write a function that returns if a given  position is inside the maze or not (isInside)
bool isInside(Position pos)
{
	return (pos[ROW] < MAZESIZE && pos[ROW] >= 0 && pos[COL] < MAZESIZE && pos[COL] >= 0);
}


bool isInsideMemory(Position pos)
{
	return (pos[ROW] < MEMORYSIZE && pos[ROW] >= 0 && pos[COL] < MEMORYSIZE && pos[COL] >= 0);
}







// Write a function that returns the cell at a given Position in a given Maze (getCell)
MazeCell getCell( Maze maze, Position pos)
{
	if (isInside(pos))
		return maze[pos[ROW]][pos[COL]];
	else Outside;
}

#define OUTSIDEMEMORY -3

int getCellMemory(BotMemory memory, Position pos)
{
	if (isInsideMemory(pos))
		return memory[pos[ROW]][pos[COL]];
	else return OUTSIDEMEMORY;
}













// Write a function that returns if a given  position is exit (isExit)
bool isExit(Maze maze, Position pos)
{
	return getCell(maze, pos) == Exit;
}



















































// Write a function that copies a position into another position(copyPosition)
void copyPosition(Position source, Position target)
{
	for (int i = 0; i < DIMENSIONCOUNT; ++i)
	{
		target[i] = source[i];
	}
}




















// Write a function that moves a given position towards a given direction (movePosition)
void movePosition_Poor(Position p, Direction d)
{
	if (d == Up)
	{
		p[ROW] = p[ROW] + - 1;
		p[COL] = p[COL] + 0;
	} else 	if (d == Down)
	{
		p[ROW] = p[ROW] + +1;
		p[COL] = p[COL] + 0;
	}
	else 	if (d == Left)
	{
		p[ROW] = p[ROW] + 0;
		p[COL] = p[COL] + -1;
	}
	else 	if (d == Right)
	{
		p[ROW] = p[ROW] + 0;
		p[COL] = p[COL] + +1;
	}

}





















// Rewrite movePosition function without using if-s or switch
int deltaPosition[4][2] = { {-1,0 }, { 0,-1}, { 1,0}, { 0,1} };
void movePosition(Position p, Direction d)
{
	p[ROW] = p[ROW] + deltaPosition[d][ROW];
	p[COL] = p[COL] + deltaPosition[d][COL];
}






















// Write a function that returns the neighbor cell of the cell at a given position
// in a given Maze towards a given direction (neighborOf)

MazeCell neighborOf(Maze maze, Position pos, Direction d)
{
	Position tmp;
	copyPosition(pos, tmp);
	movePosition(tmp, d);
	return getCell(maze, tmp);
}



int neighborOfMemory(BotMemory memory, Position pos, Direction d)
{
	Position tmp;
	copyPosition(pos, tmp);
	movePosition(tmp, d);
	return getCellMemory(memory, tmp);
}



























// Write a function that returns if It is possible to move at a given Position
// towards a given direction in a given maze (canMove)

bool canMove(Maze maze , Position pos, Direction d)
{
	MazeCell cell = neighborOf(maze, pos, d);
	return (cell  == Exit) || (cell == Empty);
}
























// Write a function that moves a given position towards a given direction if it is possible in a given maze. 
// Returns true if moved,false otherwise (tryMove) 
bool tryMove(Maze maze, Position pos, Direction d)
{
	if (canMove(maze, pos, d))
	{
		movePosition(pos, d);
		return true;
	}
	else return false;
}






















#define DIRECTIONCOUNT 4

// Write a function that randomly moves a robot at a given position in a given maze
// The function should print the maze at each step and stop when the robot moves to exit (moveRandomly)
void moveRandomlyAge1(Maze maze, Position pos)
{
	while (!isExit(maze,pos))
	{
		Direction d = randomBelow(DIRECTIONCOUNT);

		if (tryMove(maze,pos,d))
		{
			printMaze(maze, pos);
		}
	}
}
































// Write a function that randomly moves a robot at a given position in a given maze
// The function should print the maze at each step and stop when the robot moves to exit 
// When the robot choose a random direction he should go in that direction until it hits the wall (moveRandomlyButDetermined)
void moveRandomlyAge3(Maze maze, Position pos)
{

	while (!isExit(maze, pos))
	{
		Direction d = randomBelow(DIRECTIONCOUNT);

		while (tryMove(maze, pos, d) && !isExit(maze, pos))
		{
			printMaze(maze, pos);
		}
	}

	printMaze(maze, pos);
}

#define NONVISITED -2

void clearMemory(BotMemory memory)
{
	for (int r = 0; r < MEMORYSIZE; ++r)
	{
		for (int c = 0; c < MEMORYSIZE; ++c)
		{
			memory[r][c] = NONVISITED;
		}
	}
}

void markMemory(BotMemory memory,Position pos, int val)
{
	memory[pos[ROW]][pos[COL]] = val;
}

void beginJourney()
{
	clearMemory(memory);

	finger[ROW] = MEMORYSIZE / 2;
	finger[COL] = MEMORYSIZE / 2;

	markMemory(memory, finger, 0);


}

bool discoverANewPlace(Maze  maze, Position robot)
{
	for (int d = 0; d < DIRECTIONCOUNT; ++d)
	{
		if (canMove(maze,robot,d) &&  neighborOfMemory(memory,finger,d)== NONVISITED)
		{
			int step = getCellMemory(memory, finger);
			movePosition(robot, d);
			movePosition(finger, d);
			markMemory(memory, finger, step + 1);
			return true;
		}

	}
	return false;
}


bool moveBack(Maze maze,  Position  pos)
{
	int step = getCellMemory(memory, finger);

	for (int d = 0; d < DIRECTIONCOUNT; ++d)
	{
		if (neighborOfMemory(memory,finger,d) == step-1)
		{
			movePosition(pos,d);
			movePosition(finger, d);
			return true;
		}
	}
	return false;
}


// Write a function that moves the robot to one of the exits in a given maze
void findExit(Maze maze , Position pos )
{
	beginJourney();


	while (!isExit(maze, pos))
	{
		while (discoverANewPlace(maze, pos) && !isExit(maze,pos))
		{
			printMaze(maze, pos);
		}
		if (isExit(maze, pos))
		{
			printf("YIII HUU!");
			return;
		}
		if (moveBack(maze, pos))
		{
			printMaze(maze, pos);
		}
		else
		{
			printf("NO WAY!!!\n");
		}
	}

		
}


















void main()
{
	randomize();

	findExit(maze, robot);
	


	return;
}

