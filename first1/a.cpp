#include <graphics.h>
#include <conio.h>

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	printf("Hello world\n");
	circle(200,200,100);
	getch();
	closegraph();
}
