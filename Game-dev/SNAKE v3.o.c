#include<stdio.h>
#include<conio.h>
#include<strings.h>
#include<windows.h>
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
                  int i,checker,counter=1;

        char name[20];
        int snake[10];
        int a,b,c;
        int snakex,snakey;
       
        

                int blankx,blanky;
                int foodx,foody;
                char blank[10];
                
 void limitcheck()
 
 {
      if (snakex>=60 || snakex==0){snakex=1;}
      if(snakey>=30||snakey<=0){snakey=1;}
      if(foodx>=50||foody>=30){foodx=foodx-snakex;foody=foody-snakey;}
      }
 void assigner()
 {
      for(i=0;i<10;i++)
      {snake[i]=0;
                       blank[i]=' ';
                       }
                            
 }                          
 void atecheck()
 { 
      if(snakex==foodx && snakey==foody)
      {                
                       counter=counter+1;
                       snake[counter]=0;
                       foody=foody;
                       foodx=foodx+blanky+5;
                       gotoxy(foodx,foody);
                       printf("*");
      }                
 }
 

void left()
{
     while(!kbhit())
     {
     limitcheck(); assigner();
     atecheck();
    
  
     if(a==1){
              printf("GAME OVER");
              }
     else
     { Sleep(500);  blankx=snakex;
         blanky=snakey;
         snakex=snakex-1;
         snakey=snakey;
         gotoxy(snakex,snakey);
         for(i=0;i<counter;i++)
         {
             printf("%d",snake[i]);
         }
             gotoxy(blankx,blanky);
        for(i=0;i<counter;i++)
        {
             printf("%c",blank[i]);
        }
     }
   }
}
 void right()
 {
      while(!kbhit())
      {
       limitcheck();
       assigner();
       atecheck();
       checker=0;
       if(checker==1){
                printf("GAME OVER");
                }
                else
                { Sleep(500);
                    blankx=snakex;
                    blanky=snakey;
                    snakex=snakex+1;
                    snakey=snakey;
                    gotoxy(snakex,snakey);
                    for(i=0;i<counter;i++)
                    {
                      printf("%d",snake[i]);
                    }
                    gotoxy(blankx,blanky);
                    for(i=0;i<counter;i++)
                    {
                     printf("%c",blank[i]);
                    }
                }   
       }
}
void  up()
{
       while(!kbhit())
      { 
       limitcheck();
       assigner();
       atecheck();
      checker=0;
       if(checker==1){
                printf("GAME OVER");
                }
                else
                {}
                }
                }
void down()
{
     while(!kbhit())
     { atecheck();
       limitcheck();
       assigner();
       
      checker=0;
      if(checker==1)
      {
              printf("GAMEOVER");
              }
              else
              {
                
                  }
                  }
                  }

 int main()
 { 
     for(i=0;i<10;i++)
     {
                      snake[i]=0;}foodx=10;foody=1;gotoxy(foodx,foody);printf("8");
     pop:
     a=getch();
while(a=='a'||a=='s'||a=='w'||a=='d'){gotoxy(70,1);printf("counter:%d",counter);
if(a=='a'){left();goto pop;}
if(a=='s'){down();goto pop;}
if(a=='w'){up();goto pop;}
if(a=='d'){right();goto pop;}
return 0;
}
}

