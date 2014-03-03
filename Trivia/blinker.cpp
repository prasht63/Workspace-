#include <stdio.h>

#include<windows.h>
#include <graphics.h>
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void blink(char w[])

{
   int i,g;
  
   i=2;
 do
   { gotoxy(1,1);Sleep(200);
      printf("%s",w);
      Sleep(200);gotoxy(1,1);
      printf("                    ");
      
     
}while(!kbhit());}
int main(){
    char name[12];
    printf("Enter the word you want to blink");
    scanf("%s",name);
    blink(name);
    return 0;
}
