#include <stdio.h>
#include <math.h>
// #include <graphics.h>

void drawBresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx, dy, p, x, y, twoDyDx, twoDy, xEnd;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    p = 2 * dy - dx;
    twoDy = 2 * dy;
    twoDyDx = 2 * (dy - dx);

    if (x1 > x2)
    {
        x = x2;
        y = y2;
        xEnd = x1;
    }
    else
    {
        x = x1;
        y = y1;
        xEnd = x2;
    }

    putpixel(x, y, "WHITE");

    while (x < xEnd)
    {
        x++;
        if (p < 0)
        {
            p += twoDy;
        }
        else
        {
            y++;
            p += twoDyDx;
        }
        putpixel(x, y, "WHITE");
    }
}

int main()
{
    drawBresenhamLine(100, 100, 200, 200);
    return 0;
}