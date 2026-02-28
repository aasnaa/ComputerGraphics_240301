#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Original line coordinates
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 150;

    // Translation values
    int tx = 150; // shift along x-axis
    int ty = 50;  // shift along y-axis

    // Draw original line in WHITE
    line(x1, y1, x2, y2);

    // Draw translated line in RED
    line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);

    // Optional: Show text labels
    outtextxy(x1, y1 - 20, "Original Line");
    outtextxy(x1 + tx, y1 + ty + 10, "Translated Line");

    getch();
    closegraph();
    return 0;
}
