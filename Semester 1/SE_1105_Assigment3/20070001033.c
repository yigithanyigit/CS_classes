#include <stdio.h>

#include "20070001033.h"

void fillRectangle(Screen Screen, int row, int column, int width, int length)
{
    for (int r = row; r < row + length; r++)
    {
        for (int c = column; c < column + width; c++)
        {
            screen[c][r] = Open;
        }
    }
}

void drawRectangle(Screen Screen, int row, int column, int width, int length)
{
    for (int r = row; r < row + length; r++)
    {
        for (int c = column; c < column + width; c++)
        {
            if (r == row || r == row + length - 1 || c == column || c == column + length - 1)
            {
                screen[c][r] = Open;
            }
        }
    }
}

void drawVLine(Screen screen, int row, int column, int length)
{
    for (int l = row; l < row + length; l++)
    {
        screen[column][l] = Open;
    }
}

void drawHLine(Screen screen, int row, int column, int length)
{
    for (int l = column; l < column + length; l++)
    {
        screen[l][row] = Open;
    }
}

void clearScreen(Screen screen)
{
    for (int r = 0; r < MAXSIZE; r++)
    {
        for (int c = 0; c < MAXSIZE; c++)
        {
            screen[c][r] = Close;
        }
    }
}

void printScreen(Screen screen)
{
    for (int r = -1; r < MAXSIZE + 1; r++)
    {
        for (int c = -1; c < MAXSIZE + 1; c++)
        {
            if (r == -1 || r == MAXSIZE)
            {
                printf(HBoundaries);
            }
            else if (c == -1 || c == MAXSIZE)
            {
                printf(VBoundaries);
            }
            else
            {
                if (screen[c][r] == Open)
                {
                    printf(OpenPixel);
                }
                else
                    printf(Empty);
            }
        }
        printf("\n");
    }
}

void printRectangle(Screen screen, int row, int column)
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < column; c++)
        {
            printf("%d ", screen[r][c]);
        }
        printf("\n");
    }
}

void main()
{
    printScreen(screen);
    fillRectangle(screen, 3, 2, 3, 3);
    printScreen(screen);
    drawVLine(screen, 12, 4, 5);
    printScreen(screen);
    drawHLine(screen, 18, 4, 5);
    printScreen(screen);
}