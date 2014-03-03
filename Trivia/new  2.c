#include<stdio.h>
#include<conio.h>
int main()
{
int a,b,c,i,d=80,e;
printf("Enter ur age");
 scanf("%d",&a);
 printf("enter the age when u started smoking");
 scanf("%d",&b);
 c=a-b;
 i=c;
 e=65-(5*c)+(d/(4*c));
 switch(i)
 {
 case 1:
 printf("u will live:%d",e); break;
 case 2:

  printf("u will live :%d",e); break;
  case 3:
   printf("u will live :%d",e); break;
   case 4:
    printf("u will live :%d)",e); break;
	case 5:
	 printf("u will live :%d",e); break;
	 case 6:
	  printf("u will live :(%d)",e); break;

   }
   getch();
   return e;

   }
