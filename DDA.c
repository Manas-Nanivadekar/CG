#include <stdio.h>
#include <graphics.h>

// Function to implement DDA line drawing algorithm
void drawLineDDA(int x1, int y1, int x2, int y2)
{
    // Calculate the difference in x and y coordinates
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate the number of steps required
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increment in x and y for each step
    float xInc = (float)dx / steps;
    float yInc = (float)dy / steps;

    // Initialize starting coordinates
    float x = x1;
    float y = y1;

    // Open a graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Plot the starting point
    putpixel(x, y, WHITE);

    // Iterate through each step and plot the points
    for (int i = 1; i <= steps; i++)
    {
        x += xInc;
        y += yInc;
        putpixel(round(x), round(y), WHITE);
    }

    // Close the graphics window
    delay(5000);
    closegraph();
}

int main()
{
    int x1, y1, x2, y2;

    // Input the coordinates of the two points
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    // Call the DDA line drawing function
    drawLineDDA(x1, y1, x2, y2);

    return 0;
}
