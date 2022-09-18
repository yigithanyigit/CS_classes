#include <stdio.h>

#define GAME_ZONE 5

void drawTable(int *data);
void dataGen(int *data);
void printer(int *data);
void game(int *data, int player);
void getIntput(int *data);
int isFinished(int *data);

int main()
{
    int *data = (int *)malloc((GAME_ZONE * GAME_ZONE) * sizeof(int));
    dataGen(&data);
    printer(&data);
    // drawTable(&data);
    game(&data, 2);
    return 1;
}

void printer(int *data)
{
    int i;
    for (i = 0; i < GAME_ZONE * GAME_ZONE; i++)
    {
        printf("%d ", data[i]);
    }
    printf("%d ", i);
}

void getInput(int *data, int *character)
{
    int cell;
    if (*character == 0)
    {
        int cha;
        fflush(stdin);
        printf("What is your character X = 1, O = -1\n");
        scanf("%d", &cha);
        *character = cha;
        if (*character != 1 && *character != -1)
        {
            printf("Please Type Valid character %d\n", *character);
            fflush(stdin);
            getInput(data, character);
        }
    }

    fflush(stdin);
    if (*character == 1)
        printf("Your Character is %c, Which Cell do you want to put?\n", 'X');
    else
        printf("Your Character is %c, Which Cell do you want to put?\n", 'O');
    scanf("%d", &cell);
    if (data[cell] != 0 || cell > GAME_ZONE * GAME_ZONE)
    {
        printf("Please Type Valid Cell\n");
        fflush(stdin);
        getInput(data, character);
    }
    else
    {
        data[cell] = *character;
    }

    
}

i

void dataGen(int *data)
{
    int i;
    for (i = 0; i < GAME_ZONE * GAME_ZONE; i++)
    {
        data[i] = 0;
    }
}

void drawTable(int *data)
{
    int vertical_line = GAME_ZONE;
    int horizontal_line = GAME_ZONE;
    int i, j, q = 1;
    int x = 1;
    int o = -1;
    for (i = 1; i <= horizontal_line; i++)
    {
        printf("|");
        for (j = 1; j <= vertical_line; j++, q++)
        {
            switch (data[q])
            {
            case -1:
                printf("O|");
                break;
            case 1:
                printf("X|");
                break;
            default:
                printf("_|");
                break;
            }
        }
        q -= 5;
        printf("    |");
        for (j = 1; j <= vertical_line; j++, q++)
        {
            switch ((q - 1) < 10)
            {
            case 1:
                printf(" %d|", q - 1);
                break;

            default:
                printf("%d|", q - 1);
                break;
            }
        }
        printf("\n");
    }
}

void game(int *data, int player)
{
    if (player == 1)
    {
        /* code */
    }
    else
    {
        int *character1 = 0;
        int *character2 = 0;
        int finished = 0;
        while (!finished)
        {
            printf("1: %d  2: %d", character1, character2);
            printf("Player 1 Turn\n");
            drawTable(data);
            getInput(data, &character1);
            printf("Player 2 Turn\n");
            drawTable(data);
            getInput(data, &character2);
            printer(data);
            // finished = 1;
        }
    }
}