#include<stdio.h>
#include<conio.h>
int main()
{
   
    int a,b,i,j,n,temp;
    int array[5];
    for(i=0;i<=4;i++)
    {
                      scanf("%d",&array[i]);
                     
                      
                      }
                       for(i=0;i<4;i++)
                     
                     {
                                                 for(j=i+1;j<=4;j++)
                                                 {                     
                     if (array[i]<array[j])
                     {
                                           temp=array[i];
                     array[i]=array[j];
                     array[j]=temp;}}}
                      printf("After sorting is: \n");
  for(i=0;i<5;i++)
      printf(" %d",array[i]);
                                       
                                       getch();
                                       return 0;
                                       }
                                       
    
