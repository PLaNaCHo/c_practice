#include<stdio.h>
#include <stdlib.h>
void clear();

struct ball {
    int a_x;
    int a_y;
    int v_x;
    int v_y;
    int x;
    int y;
};
//-----------main----------------------------------------------
int main(){
struct ball ball1 = {0,-10,10,30,0,0};
printf("first");
clear();
printf("sec");

return 0;
}
//-------function--------------------------------------------------------------
void clear(){
printf("\n");
system("clear");
};