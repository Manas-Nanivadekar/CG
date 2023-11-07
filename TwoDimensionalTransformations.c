
void main()
{
    int x1, x2, x3, y1, y2, y3, nx1, nx2, nx3, ny1, ny2, ny3, sx, sy, tx, ty, c;
    float r, t;
    int gd = "DETECT", gm = 0;
    printf("Program for 2D transformation");
    setcolor(1);
    scanf("%d%d%d%d%d%d", &x1, &x2, &x3, &y1, &y2, &y3);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    printf("Enter a choice: ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("Enter scaling factors: ");
        scanf("%d%d", &sx, &sy);
        nx1 = x1 * sx;
        nx2 = x2 * sx;
        nx3 = x3 * sx;
        ny1 = y1 * sy;
        break;
    case 2:
        printf("Enter translation factors: ");
        scanf("%d%d", &tx, &ty);
        nx1 = x1 + tx;
    case 3:
        print("Enter the angle: ");
        scanf("%f", &r);
        t = (3.14 / 180) * r;
        nx1 = abs(x1 * cos(t) - y1 * sin(t));
        ny1 = abs(x1 * sin(t) + y1 * cos(t));
    default:
        break;
    }
}