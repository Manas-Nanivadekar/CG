#include <stdio.h>

void drawCirclePixels(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, "RED");
    putpixel(xc + y, yc + x, "RED");
    putpixel(xc + y, yc - x, "RED");
    putpixel(xc + x, yc - y, "RED");
    putpixel(xc - x, yc - y, "RED");
    putpixel(xc - y, yc - x, "RED");
    putpixel(xc - y, yc + x, "RED");
    putpixel(xc - x, yc + y, "RED");
}

void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    drawCirclePixels(xc, yc, x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        drawCirclePixels(xc, yc, x, y);
    }
}