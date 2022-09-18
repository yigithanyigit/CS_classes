#include "linkedstack.h"

#define MAZE_X 8
#define MAZE_Y 8

typedef struct
{
	int R;
	int C;
} POS_t[1], *POS;

POS check_adjacent(int *M, int R, int C)
{
	// COUNTERCLOCKWISE

	int i;
	POS res = (POS)malloc(sizeof(POS_t));
	POS_t temp[4];
	temp[0]->R = R - 1;
	temp[0]->C = C;
	temp[1]->R = R;
	temp[1]->C = C - 1;
	temp[2]->R = R + 1;
	temp[2]->C = C;
	temp[3]->R = R;
	temp[3]->C = C + 1;

	for (i = 0; i < 4; i++)
	{
		if (M[temp[i]->R * 8 + temp[i]->C] == 1)
		{
			res = temp[i];
			break;
		}
		else
		{
			res = NULL;
		}
	}
	return res;
}

void solve_maze()
{

	int M[8][8] = {
		/* R\C   0  1  2  3  4  5  6  7 */
		/* 0 */ {0, 0, 0, 1, 0, 0, 0, 0},
		/* 1 */ {0, 1, 1, 1, 0, 0, 1, 0},
		/* 2 */ {0, 1, 0, 1, 0, 0, 1, 0},
		/* 3 */ {0, 1, 0, 1, 1, 1, 1, 0},
		/* 4 */ {0, 1, 0, 0, 0, 0, 1, 1},
		/* 5 */ {0, 1, 1, 0, 1, 1, 1, 0},
		/* 6 */ {0, 0, 0, 0, 1, 0, 0, 0},
		/* 7 */ {0, 0, 0, 0, 1, 0, 0, 0},
	};

	int I, J, R = 0, C = 3;
	LINKED_STACK stack;
	POS pos = (POS)malloc(sizeof(POS));
	int flag;
	stack = linked_stack_init();

	do
	{
		POS a = (POS)malloc(sizeof(POS_t));
		a->R = R;
		a->C = C;
		linked_stack_push(stack, a);
		M[R][C] = 2;
		a = check_adjacent(M, R, C);
		if (a != NULL)
		{
			R = a->R;
			C = a->C;
			printf("(%d %d)", R, C);
		}
		else
		{

			POS pop = (POS)linked_stack_pop(stack);
			M[R][C] = -1;
			while (check_adjacent(M, pop->R, pop->C) == NULL)
			{

				pop = (POS)linked_stack_pop(stack);
				printf("(%d %d)", pop->R, pop->C);
				R = pop->R;
				C = pop->C;
			}
		}

	} while (R != 7 && C != 7 && R != 0 && C != 0);

	// PRINT MAZE

	int i, j;
	printf("\n");
	for (i = 0; i < MAZE_X; i++)
	{
		for (j = 0; j < MAZE_Y; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}
