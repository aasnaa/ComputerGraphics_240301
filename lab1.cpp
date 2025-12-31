#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	
	setcolor(BLUE);
	line(200,0,100,200);
	line(100,200,300,200);
	line(300,200,200,0);
	getch();
	closegraph();
	return 0;
	
}
