#include <stdio.h>

void floodFill(int x, int y, int oldColour, int newColour)
{
    if (getpixel(x, y) == oldColour)
    {
        putpixel(x, y, newColour);
        floodFill(x + 1, y, oldColour, newColour);
        floodFill(x, y + 1, oldColour, newColour);
        floodFill(x - 1, y, oldColour, newColour);
        floodFill(x, y - 1, oldColour, newColour);
    }
}

int main()
{
    int gm, gd = "DETECT", radius;
    int x, y;
}