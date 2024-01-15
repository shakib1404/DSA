#include <graphics.h>
#include<iostream>
using namespace std;
int main() {

     cout << "hello";
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(100, 100, 300, 200);



    closegraph();
    getch();

}
