#include<stdio.h>
#include<conio.h>
int main()
{ int i,j,a,b,c,d;
char name[20];
printf("Welcome to Buddh Bhavan Table Tennis Federation\t\n");
printf("Enter your name");
gets(name);
 puts("Hello!\n");
    puts(name);
    
    sos:
 printf("To see the rankings put the rank\n");
    scanf("%d",&a);
    switch(a)
    {
             case 1:
                  printf("Manas Lohani 2781");break;
                  case 2:
                       printf("Rohit Upreti 2567");break;
                       case 3:
                              printf("Shubham Agrawal 1879");break;
                              case 4:
                                     printf("Raghav Gupta 1731");break;
                                     case 5:
                                            printf("Arvind Malhotra");break;
                                            case 6:
                                                 printf("Abhishek kanodia");break;
                                                 default:
                                                         printf("Thank You Only top 6");break;
                                                         }
                                                         
                                                          printf("\n\ndo you want to see other ranks 1/0");
                  scanf("%d",&b);
                  if(b==1)
                  goto sos;
                  
                  getch();
                  return 0;
                  }





