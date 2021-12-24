#include <stdio.h>


void printShape3()
{
	for (int x = 0; x <= 10; x++)
	{
		for (int y = 0; y <= 10; y++)
		{
			if ( ( x<5 && ( y == 5-x || y == 5+x ) ))
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}



int main(){
    printShape3();
    return 0;
};