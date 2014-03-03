#include<graphics.h>

#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
void main()
{
int v,s;
int gd= DETECT,gm;
initgraph(&gd,&gm," ");
line(0,290,634,290);

for(int i=10;i<=634;i++)
{
cleardevice();
line(130+i,200,180+i,150);
line(180+i,150,250+i,150);
line(250+i,150,300+i,200);

circle(300+i,275,15);
circle(150+i,275,15);
rectangle(120+i,200,350+i,260);
//line(0,275,634,275);
line(0,290,634,290);
delay(10);
}
