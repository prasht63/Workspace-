#include<stdio.h>
int main(){

  int s,temp,i,j,a[20];

  printf("Enter total numbers of elements: ");
  scanf("%d",&s);

  printf("Enter %d elements: ",s);
  for(i=0;i<s;i++)
      scanf("%d",&a[i]);

  //Bubble sorting algorithm
  {
      for(j=0;j<=3;j++){
           if(a[j]>a[j+1]){
               temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
           }
      }
  }

  printf("After sorting: ");
  for(i=0;i<s ;i++)
      printf(" %d",a[i]);
getch();
  return 0;
}
