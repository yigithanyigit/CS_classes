
#ifndef __UTILS__
#define __UTILS__

#include "time.h"
#include "stdlib.h"
#include "windows.h"



void randomize()
{
	srand(time(NULL));
}

int randomBelow(int n)
{
	return rand() % n;
}



void waitForSomeTime()
{
	//Sleep(1);
}


void clearScreen()
{
	system("CLS");
}

#endif
