
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Function Prototypes
void draw_circle(int, int, int);
void symmetry(int, int, int, int);

int main() {
    int xc, yc, R;
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    printf("Enter the center of the circle:\n");
    printf("Xc = ");
    scanf("%d", &xc);
    printf("Yc = ");
    scanf("%d", &yc);
    printf("Enter the radius of the circle: ");
    scanf("%d", &R);

    draw_circle(xc, yc, R);

    getch();
    closegraph();
    return 0;
}

void draw_circle(int xc, int yc, int rad) {
    int x = 0;
    int y = rad;
    int p = 1 - rad;

    // Plot initial points
    symmetry(x, y, xc, yc);

    for (x = 0; x < y; x++) {
        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        symmetry(x, y, xc, yc);
        delay(50);
    }
}



void symmetry(int x, int y, int xc, int yc) {
    // This function exploits the 8-way symmetry of a circle
    putpixel(xc + x, yc - y, GREEN); // Octant 1
    delay(50);
    putpixel(xc + y, yc - x, GREEN); // Octant 2
    delay(50);
    putpixel(xc + y, yc + x, GREEN); // Octant 3
    delay(50);
    putpixel(xc + x, yc + y, GREEN); // Octant 4
    delay(50);
    putpixel(xc - x, yc + y, GREEN); // Octant 5
    delay(50);
    putpixel(xc - y, yc + x, GREEN); // Octant 6
    delay(50);
    putpixel(xc - y, yc - x, GREEN); // Octant 7
    delay(50);
    putpixel(xc - x, yc - y, GREEN); // Octant 8
    delay(50);
}