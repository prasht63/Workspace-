//Snake game project with some added effects My first game;
#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
char name[15];
int fg,t;
char game1[]="SNAKE 2.0";

char game[]="GAMEOVER",win[]="YOUWIN";
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
   for(i = 0; i < 10; i++)
   {Beep(6000,50); gotoxy(20,10);Sleep(200);
      printf("%s",w);
      Sleep(200);gotoxy(20,10);
      printf("         ");


}
}
void level()
{ int gh;PlaySound("C:/WINDOWS/Media/ding.wav", NULL, SND_FILENAME);
     gotoxy(30,0);printf("SNAKE 2.O");for(gh=0;gh<=100;gh++){if(gh>=99){Beep(2400,100);Sleep(500+gh);}Sleep(100);gotoxy(10,10);printf("LOADING:%d %",gh);gotoxy(9,10);printf(" ");}getch();system("cls");gotoxy(0,10);printf("Enter your name: ");
       scanf("%s",name);
       system("cls");
       gotoxy(1,1);blink(game1);gotoxy(0,5);printf("Choose level");gotoxy(0,12);printf("1.Beginner\n2.Amateur\n3.Pro\n4.Legendary\t");scanf("%d",&fg);if(fg==1){t=60;}if(fg==2){t=50;}if(fg==3){t=40;}if(fg==4){t=34;}}

int a,b,c,slength,d,e,f,i,j,k,l,n=10,m=10,z,counter=0,lefty,righty,downy,upy;

   void left()
{while(!kbhit()){Beep(4000,t);gotoxy(70,1);printf("Score:%d",counter);
  { m=m-1;
   n=n;if(m>=80){gotoxy(m,n);printf(" ");m=1;}if(m==0){gotoxy(m,n);printf(" ");m=70;}if(n>=30){gotoxy(m,n);printf(" ");n=2;}if(n==0){gotoxy(m,n);printf(" ");n=29;}
   gotoxy(m,n);
printf("O");
gotoxy(m+1,n);
printf(" ");}lefty++;
   if(z-m==0&&d-n==0)
   {counter=counter+1;z=z+4;d=d-8;
   if(d>=30||z>=60)
      {z=z-6; d=d-4;gotoxy(z,d);printf("*");gotoxy(z+6,d+4);printf(" ");}else{gotoxy(z,d);printf("*");gotoxy(z-1,(d-6));printf(" ");}}


     }}
   void right()
{while(!kbhit()){Beep(4000,t);gotoxy(70,1);printf("Score:%d",counter); {
   m=m+1;
   n=n;if(m>=80){gotoxy(m,n);printf(" ");m=1;}if(m==0){gotoxy(m,n);printf(" ");m=70;}if(n>=30){gotoxy(m,n);printf(" ");n=2;}if(n==0){gotoxy(m,n);printf(" ");n=29;}
   gotoxy(m,n);
printf("O");
gotoxy(m-1,n);
printf(" ");    }righty++; if(z-m==0&&d-n==0)
   {counter=counter+1;z=z+7;d=d-3;
   if(d>=20||z>=60)
   {z=z-6; d=d-4;gotoxy(z,d);printf("*");gotoxy(z+6,d+4);printf(" ");}gotoxy(z,d);printf("*");gotoxy(z-1,(d-(n-6)));printf(" ");}}
   }
   void down()
{while(!kbhit()){Beep(2000,t);gotoxy(70,1);printf("Score:%d",counter);
   m=m;
   n=n+1;if(m>=80){m=1;gotoxy(m,n);printf(" ");}if(m==0){m=70;gotoxy(m,n);printf(" ");}if(n>=30){n=2;gotoxy(m,n);printf(" ");}if(n==0){n=29;gotoxy(m,n);printf(" ");}
   gotoxy(m,n);downy++;
printf("O");
gotoxy(m,n-1);
printf(" "); if(z-m==0&&d-n==0)
   {counter=counter+1;z=z-2;d=d+6;
   if(d>=20||z>=60)
   {z=z-6; d=d-4;gotoxy(z,d);printf("*");gotoxy(z+6,d+4);printf(" ");}gotoxy(z,d);printf("*");gotoxy(z-1,(d-(n-6)));printf(" ");}}
   }
void up()
{while(!kbhit()){Beep(2400,t);gotoxy(70,1);printf("Score:%d",counter);
   m=m;
   n=n-1;if(m>=80){gotoxy(m,n);printf(" ");m=1;}if(m==0){gotoxy(m,n);printf(" ");m=70;}if(n>=30){gotoxy(m,n);printf(" ");n=2;}if(n==0){gotoxy(m,n);printf(" ");n=29;}
   gotoxy(m,n);upy++;
printf("O");
gotoxy(m,n+1);
printf(" "); if(z-m==0&&d-n==0)
   {counter=counter+1;z=z-10;d=d-2;
   if(d>=20||z>=60)
   {z=z-6; d=d-4;gotoxy(z,d);printf("*");gotoxy(z+6,d+4);printf(" ");}gotoxy(z,d);printf("*");gotoxy(z-1,(d-(n-6)));printf(" ");}}
   }
int main()
{ level();
     gotoxy(70,1);printf("Score:%d",counter);
start:
system("cls");top:
z=m+10;d=n+5;
gotoxy(z,d);
printf("*");

pop:PlaySound("C:/WINDOWS/Media/notify.wav", NULL, SND_FILENAME);

    if(righty>=20||lefty>=20||upy>=20||downy>=20){Beep(300,100);Beep(300,100);Beep(300,100);lefty=0;upy=0;righty=0;downy=0;counter--;}






a=getch();if(counter==10){gotoxy(40,10);blink(win);goto LEVEL2;}
while(a=='a'||a=='s'||a=='w'||a=='d'){gotoxy(70,1);printf("Score:%d",counter);if(counter%2==0){system("cls");}}
if(a=='a'){righty=0;upy=0;downy=0;left();goto pop;}
if(a=='s'){lefty=0;upy=0;righty=0;down();goto pop;}
if(a=='w'){downy=0;lefty=0;righty=0;up();goto pop;}
if(a=='d'){upy=0;lefty=0;downy=0;right();goto pop;}


if(counter==10){
    LEVEL2:counter=0;printf("WELCOME TO LEVEL 2");getch(); gotoxy(70,1);printf("Score:%d",counter);
start2:
system("cls");
z=m+10;d=n;gotoxy(z,d);printf("*");if(counter%2!=0){z=z-6;d=d-6;}
pop1:
    if(righty>=20||lefty>=20||upy>=20||downy>=20){lefty=0;upy=0;righty=0;downy=0;counter--;}
    if(m>=80||n>=27||m<=0||n<=0){system("cls");gotoxy(40,10);blink(game);m=10;n=10;Sleep(2000);gotoxy(40,10);printf("Any key to play again");getch();goto start2;}
    if(z-1==0&&d-n==0){counter=counter+1;z=z+m;d=d+(n-6);
    if(d>=30){d=n-4;}
    if(z>=60){z=m-6;}
    gotoxy(z,d);printf("*");gotoxy(z-10,d-4);
    printf(" ");}
a=getch();if(counter==10){gotoxy(40,10);blink(win);}
while(a=='a'||a=='s'||a=='w'||a=='d'){gotoxy(70,1);printf("Score:%d",counter);
if(a=='a'){righty=0;upy=0;left();goto pop1;}
if(a=='s'){lefty=0;upy=0;righty=0;down();goto pop1;}
if(a=='w'){downy=0;lefty=0;righty=0;up();goto pop1;}
if(a=='d'){upy=0;lefty=0;downy=0;right();goto pop1;}

}
}

bottom:


return 0;
}













