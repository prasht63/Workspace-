#include<stdio.h>
#include<conio.h>

int main()
{
    int a,b,i,j,m1[50][50],m2[50][50],m3[50][50],e,f,g,h,sum;
    sum=0;
    printf("Enter the array size of array 1 mXn separated by spaces");
    scanf("%d%d",&e,&f);
    printf("Enter the size of 2nd Matrix same way");
    scanf("%d%d",&g,&h);
    if(f==g)
    {
            printf("Enter the elements of matrix 1");
            for(i=0;i<e;i++)
            {
                            for(j=0;j<f;j++)
                            {
                                            scanf("%d",&m1[i][j]);
                                            }}
            printf("Enter the elements of matrix 2");
            for(i=0;i<g;i++)
            {
                            for(j=0;j<h;j++)
                            {
                                            scanf("%d",&m2[i][j]);
                                            }}
                                            for(a=0;a<e;a++)
                                            {
                                                            for(b=0;b<h;b++)
                                                            { 
                                                                       m3[a][b]=sum;     for(i=0;i<e;i++)
                                                                            { sum=0;
                                                                                            for(j=0;j<f;j++)
                                                                                            {
                                                                                                            sum=sum+(m1[i][j]*m2[j][i]);
                                                                                                            }}}}}
                                                                                                            
                                                                                                            
                                                                                                            printf("The array is\n ");
                                                                                                             for(i=0;i<f;i++)
            {
                            for(j=0;j<g;j++)
                            {
                                            printf("%d\t",m3[i][j]);
                                            }printf("\n");}
                                            getch();
                                            return 0;
                                            }
