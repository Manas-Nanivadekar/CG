#include <stdio.h>
#include <graphics.h>

// Region codes for the 9 regions outside/inside the clipping window
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define the clipping window boundaries
const int xMin = 100;
const int yMin = 100;
const int xMax = 200;
const int yMax = 200;

// Function to compute the region code of a point (x, y)
int computeRegionCode(double x, double y)
{
    int code = INSIDE;

    if (x < xMin)
    {
        code |= LEFT;
    }
    else if (x > xMax)
    {
        code |= RIGHT;
    }
    if (y < yMin)
    {
        code |= BOTTOM;
    }
    else if (y > yMax)
    {
        code |= TOP;
    }

    return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
    // Compute region codes for P1, P2
    int code1 = computeRegionCode(x1, y1);
    int code2 = computeRegionCode(x2, y2);
    int accept = 0;

    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // Trivially accepted
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            // Trivially rejected
            break;
        }
        else
        {
            // Line needs clipping
            int codeOut;
            double x, y;

            // At least one endpoint is outside the clipping window
            // Choose the one outside
            if (code1 != 0)
            {
                codeOut = code1;
            }
            else
            {
                codeOut = code2;
            }

            // Find intersection point using formula y = y1 + slope * (x - x1), x = x1 + (1 / slope) * (y - y1)
            if (codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            }
            else if (codeOut & LEFT)
            {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            // Replace the point outside the window with the intersection point
            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeRegionCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        // Draw rectangle for clipping window
        rectangle(xMin, yMin, xMax, yMax);

        // Draw the line after clipping
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;

    // Initialize graphics function
    initgraph(&gd, &gm, "");

    double x1 = 120, y1 = 150, x2 = 300, y2 = 300;

    // Line before clipping
    line(x1, y1, x2, y2);

    // Perform clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    // Close the graphics mode
    getch();
    closegraph();
    return 0;
}
