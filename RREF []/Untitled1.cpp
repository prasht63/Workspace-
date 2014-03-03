#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>


int main()
{float a[3][3];
    int b,c,d,e,f,g,h,i,j,k,l,q;
    printf("\t\tWelcome to RREF generator by coding_freak and co. \n\n\n\nDISCLAIMER:This programme functions only for 3X3 matrix.\n\n\n");entry:

    printf("Enter the numbers of matrices row wise\n");
     
    for(i=1;i<=3;i++)
    {
                     for(j=1;j<=3;j++)
                     {
                                      scanf("%f",&a[i][j]);}
                                      }printf("The matrice you have entered is \n%.0f\t%.0f\t%.0f\n%.0f\t%.0f\t%.0f\n%.0f\t%.0f\t%.0f\n\n\nIf correct press 1 or 0 to reenter",a[1][1],a[1][2],a[1][3],a[2][1],a[2][2],a[2][3],a[3][1],a[3][2],a[3][3]);scanf("%d",&g);
     if(g==1){goto mine;}else{goto entry;}mine:
                                      if(a[1][1]!=1){a[1][2]=a[1][2]/a[1][1];a[1][3]=a[1][3]/a[1][1]; a[1][1]=1;}
                                      if(a[2][1]!=0){a[2][2]=(-a[1][2]*a[2][1])+a[2][2];a[2][3]=(-a[1][3]*a[2][1])+a[2][3]; a[2][1]=0;}
                                      if(a[3][1]!=0){a[3][2]=(-a[3][1]*a[1][2])+(a[3][2]);a[3][3]=(-a[3][1]*a[1][3])+(a[3][3]);a[3][1]=0;}
                                      if(a[2][2]!=1){a[2][3]=a[2][3]/a[2][2];a[2][2]=1;}
                                      if(a[3][2]!=0 ){a[3][2]=0;a[3][3]=-1/a[3][2]+a[2][3];if(a[3][3]!=0 || a[3][3]!=1){a[3][3]=1;}}
                                      printf("\n\nThank you please wait for 5 seconds while we give you the REF form of you matrix");
                                      system("cls");
                                      printf("\n\n");
                                      printf("%.1f\t%.1f\t%.1f\n%.1f\t%.1f\t%.1f\n%.1f\t%.1f\t%.1f\n\nPress Enter to get RREF",a[1][1],a[1][2],a[1][3],a[2][1],a[2][2],a[2][3],a[3][1],a[3][2],a[3][3]);
                                      if(a[1][2]!=0){a[1][3]=-1*a[1][3]/a[1][2]+a[2][3];a[1][2]=-1+a[2][2];}
                                      if(a[1][3]!=0){a[1][3]=-1+a[3][3];}if(a[2][3]!=0){a[2][3]=0;}getch();
                                       printf("\n\nThe RREF of the above matrix is:\n\n%.1f\t%.1f\t%.1f\n%.1f\t%.1f\t%.1f\n%.1f\t%.1f\t%.1f\n\n",a[1][1],a[1][2],a[1][3],a[2][1],a[2][2],a[2][3],a[3][1],a[3][2],a[3][3]);
                                      getch();
                                      
                                      
                                      return 0;}
                                      
                                      
                                      
                                      
