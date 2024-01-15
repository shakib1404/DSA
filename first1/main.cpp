#include <graphics.h>
#include<iostream>
#include<conio.h>
using namespace std;
int main() {

     cout << "hello";
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(100, 100, 300, 200);



    closegraph();
    getch();

}
