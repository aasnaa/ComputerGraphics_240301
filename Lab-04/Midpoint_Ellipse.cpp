#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void drawEllipsePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midpointEllipse(int xc, int yc, int a, int b)
{
    int x = 0, y = b;
    long a2 = a * a;
    long b2 = b * b;

    long dx = 2 * b2 * x;
    long dy = 2 * a2 * y;

    // Decision parameter for Region 1
    long d1 = b2 - (a2 * b) + (a2 / 4);

    // Region 1
    while (dx < dy)
    {
        drawEllipsePoints(xc, yc, x, y);

        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * b2);
            d1 = d1 + dx + b2;
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * b2);
            dy = dy - (2 * a2);
            d1 = d1 + dx - dy + b2;
        }
    }

    // Decision parameter for Region 2
    long d2 = (b2 * (x + 0.5) * (x + 0.5)) +
              (a2 * (y - 1) * (y - 1)) -
              (a2 * b2);

    // Region 2
    while (y >= 0)
    {
        drawEllipsePoints(xc, yc, x, y);

        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * a2);
            d2 = d2 + a2 - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * b2);
            dy = dy - (2 * a2);
            d2 = d2 + dx - dy + a2;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int xc = 320, yc = 240;
    int a = 150, b = 100;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    midpointEllipse(xc, yc, a, b);

    getch();
    closegraph();
    return 0;
}
