#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // House outline color
    setcolor(WHITE);

    // Ground line
    line(20, 260, 620, 260);

    // House body
    rectangle(180, 120, 420, 260);

    // Roof
    line(160, 120, 300, 40);
    line(300, 40, 440, 120);
    line(160, 120, 440, 120);

    // Chimney
    rectangle(350, 60, 385, 115);

    // Door
    rectangle(275, 180, 330, 260);
    circle(320, 220, 2); // door knob

    // Left window
    rectangle(210, 150, 255, 195);
    line(232, 150, 232, 195);
    line(210, 172, 255, 172);

    // Right window
    rectangle(345, 150, 390, 195);
    line(367, 150, 367, 195);
    line(345, 172, 390, 172);

    // Path to door
    line(285, 260, 255, 320);
    line(320, 260, 350, 320);
    line(255, 320, 350, 320);

    // Sun
    circle(520, 70, 30);
    line(520, 25, 520, 5);
    line(520, 115, 520, 135);
    line(475, 70, 455, 70);
    line(565, 70, 585, 70);
    line(490, 40, 475, 25);
    line(550, 40, 565, 25);
    line(490, 100, 475, 115);
    line(550, 100, 565, 115);

    // Tree
    rectangle(80, 200, 100, 260);  // trunk
    circle(90, 170, 30);           // foliage
    circle(70, 190, 22);
    circle(110, 190, 22);

    getch();
    closegraph();
    return 0;
}
