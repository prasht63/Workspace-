#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
void filer();
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
   for(i = 0; i < 100; i++)
   { gotoxy(1,1);Sleep(200);
      printf("%s",w);
      Sleep(200);gotoxy(1,1);
      printf("                    ");
      
     
}}
char viewname[16],Another,date[10],gh[10],tres[10],fad[6];
int em,ey,vb,y,o,vl;
float tot;
char change[10],huh[15],duck;
int pol,vjx;
typedef struct{
        char issuename[15];
        char issuecode[6];
        char issueexp[10];
        float issuemrp;
        float issuequantity;
        int issuereorder;}bill;
long int recsize;
int p=0,x;
bill biller;
FILE *invent;
FILE *day;
char editname[15],issued[10];
typedef struct{
        char name[15];
        char code[6];
        float quantity;
        float minquantity;
        float mrp;
        int d,m,y;
        char exp[10];
        }med;
        med med1;
       
          int a,b,c,e,f,g,i,j,k,h,another,l,n,my,s;
          float t,sum,fileday,totinv;
        char password[25],username[10];
        int main()
       
        
        { HANDLE monkey;
        monkey=GetStdHandle(STD_OUTPUT_HANDLE);
        
        
            
            
            
            
            
            FILE *tresspass;
tresspass=fopen ("trespass.dat","a+") ;
            invent= fopen ( "posik.xls", "rb+" ) ;
if ( invent== NULL )
{
invent = fopen ( "posik.xls", "wb+" ) ;}
            
            
         recsize=sizeof(med1);
         fp:system("cls");
         int color;
        
        
         gotoxy(20,1);printf("\tWelcome to Prashant Medical Hall\n\n");
          
           printf("\n1.For Administrator\n2.For User\n");
           scanf("\n%d",&a);
           switch(a){
           case 1:
               { 
                     char change[25];
                                printf("Please enter your name:");
                
                                scanf("%s",username);strupr(username);
                                printf("\nEnter Password:");
                                scanf("%s",password);
                                
                               
                               
                               if(strcmp("jack",password)==0)
                                
                              { printf("\n\n\n\n\t\tAccess Granted\n\n\t\tWelcome %s!",username);getch();
                                                         printf("\nEnter current month ");
                                               scanf("%d",&em);
                                               printf("\t\t\nEnter current year ");
                                               scanf("%d",&ey);
                                               rewind(invent);printf("Following Items are near Expiry");
                                              while(fread(&med1,recsize,1,invent)==1)
                                              { 
                                              
                                             
                                              if(((12*med1.y)+med1.m)-(em+(12*ey))<=3){strupr(med1.name);SetConsoleTextAttribute(monkey, 172);printf("\n\t%s     Expiry date:%d/%d",med1.name,med1.m,med1.y); }
                                                                                                              } getch();SetConsoleTextAttribute(monkey, 15);system("cls");      
                                                             pass:
                                                                  system("cls");printf("\t              Welcome to Prashant Medical Hall\t\tHello! %s\n\n",username);
                                                             printf("\n1.Add Item\n2.View Item\n3.Edit Item\n4.View Items near expiry\n5.View Items to Reorder\n6.Item name help\n7.Exit and backup\n");
                                scanf("%d",&b);
                               switch(b)
                                {
                                case 1:
                                  {
                                                                      system("cls");printf("\t              Welcome to Prashant Medical Hall\t\tHello! %s\n\n",username);
                                                                      fseek(invent,0,SEEK_END);
                                                                      Another='y';
                                                                      while(Another=='y'){
                                                                                          printf("\n\nEnter Itemname   ");
                                                                                          scanf("%s",med1.name);
                                                                                          printf("Enter Item Code      ");
                                                                                          scanf("%s",med1.code); 
                                                                                          printf("Enter Quantity       ");
                                                                                          scanf("%f",&med1.quantity);
                                                                                          printf("MRP                  ");
                                                                                          scanf("%f",&med1.mrp);
                                                                                          printf("Date of Expiry(mm)   ");
                                                                                          scanf("%d",&med1.m);
                                                                                           printf("Date of Expiry(yy)  ");
                                                                                           scanf("%d",&med1.y);
                                                                                          printf("Enter reorder level  ");
                                                                                          scanf("%f",&med1.minquantity);
                                                                                          fwrite(&med1,recsize,1,invent);
                                                                                          fflush(stdin);
                                                                                          printf("Do you want to enter more item y/n ");
                                                                                         Another=getch();
                                                                                          if(Another=='n'){goto pass;}}
                                                                                 }
                                                                                 
                                                                                 
                                                                                 break;
                                     case 2:
                                           {   system("cls");
                                           totinv=0; printf("\t              Welcome to Prashant Medical Hall\t\tHello! %s\n\n",username);;
                                                                                          rewind(invent);vl=2;
                                                                                                   {gotoxy(0,1); printf("Item name");gotoxy(18,1);printf("Item code");gotoxy(30,1);printf("Quantity");gotoxy(42,1);printf("MRP");gotoxy(52,1);printf("DOE");gotoxy(62,1);printf("Reorder Level");     
                                                                                                   while(fread(&med1,recsize,1,invent)==1)
                                                                                                   {tot=med1.quantity*med1.mrp;
                                                                                                   totinv=totinv+tot;
                                                                                                             strupr(med1.name);strupr(med1.code);vl=vl+1;
                                                                                                           gotoxy(0,vl);  if(((12*med1.y)+med1.m)-(em+(12*ey))<=3){SetConsoleTextAttribute(monkey, 172);printf("%s",med1.name);gotoxy(18,vl);printf("%s",med1.code);gotoxy(30,vl);printf("%.0f",med1.quantity);gotoxy(42,vl);printf("%.2f",med1.mrp);gotoxy(52,vl);printf("%d/%d",med1.m,med1.y);gotoxy(62,vl);printf("%.0f\n",med1.minquantity);}
                                                                                                           else{SetConsoleTextAttribute(monkey, 15); printf("%s",med1.name);gotoxy(18,vl);printf("%s",med1.code);gotoxy(30,vl);printf("%.0f",med1.quantity);gotoxy(42,vl);printf("%.2f",med1.mrp);gotoxy(52,vl);printf("%d/%d",med1.m,med1.y);gotoxy(62,vl);printf("%.0f",med1.minquantity);}}SetConsoleTextAttribute(monkey, 15); printf("\n\nTotal investement isRs.%.2f",totinv);
                                                                                                printf("\n\n\nTo go to main menu press 1");
                                                                                                   scanf("%d",&s);
                                                                                                   if(s==1){goto pass;}}

                                                                                                    
                                                                                                         
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                   }break;
                                                                                                   
                                          case 3:
                                               {system("cls");printf("\t              Welcome to Prashant Medical Hall\t\tHello! %s\n\n",username);
                                              here: printf("\nEnter Item Name to Modify   ");
                                          scanf("%s",editname);
                                          rewind(invent);
                                          
                                        
                                          
                                          while(fread(&med1,recsize,1,invent)==1)
                                          {if(stricmp(med1.name,editname)==0)
                                                  {
                                                                             printf("\nDo you want to edit item name y/n");
                                                                             duck=getch();
                                                                             if(duck=='n'){goto pol;}
                                                                             printf("\nEnter New Itemname ");
                                                  scanf("%s",med1.name);pol:
                                           printf("\nDo you want to edit quantity y/n");
                                                                             duck=getch();
                                                                             if(duck=='n'){goto bol;}
                                                  printf("\nEnter New Quantity    ");
                                                  scanf("%f",&med1.quantity);
                                               bol:   printf("\nDo you want to edit mrp y/n");
                                                                             duck=getch();
                                                                             if(duck=='n'){goto col;} printf("\nEnter New MRP         ");
                                                  scanf("%f",&med1.mrp);
                                               col: printf("\nDo you want to edit expiry y/n");
                                                                             duck=getch();
                                                                             if(duck=='n'){goto gol;}   printf("\nEnter new DOE(mm)     ");
                                                  scanf("%d",&med1.m);
                                                  printf("\nEnter new DOE(yy)     ");
                                                  scanf("%s",&med1.y);
                                                gol:
                                                  fseek(invent,-recsize,SEEK_CUR);
                                                  fwrite(&med1,recsize,1,invent);break; 
                                                  
                                                  }  }printf("\n\n\nWant to modify other 1for yes/0 to go to main menu");
                                               scanf("%d",&my);
                                               if(my==1)
                                               {goto here;}
                                               else if(my==0){goto pass;}
                                               
                                                  fflush(stdin);}                           
                                                                                 
                                                                                 
                                                                                 
                                            
                                                                                       
                                                                       
                                                                      
                                                                     
                                                              
                                               break;
                                               case 4:system("cls");
                                               rewind(invent);printf("Following Items are near Expiry");
                                              while(fread(&med1,recsize,1,invent)==1)
                                              { 
                                              
                                             
                                              if(((12*med1.y)+med1.m)-(em+(12*ey))<=3){strupr(med1.name);printf("\n%s\tExpiry date:%d/%d",med1.name,med1.m,med1.y); }
                                                                                                              } getch();goto pass;                             
                                                   break;
                                                    case 5:pswd:system("cls");
                                                        printf("Itemnear reorder are:\n");
                                                        rewind(invent);
                                                       gotoxy(0,1); printf("Item name"); gotoxy(15,1);printf("Quantity");vjx=2;
                                                     vb=1; while(fread(&med1,recsize,1,invent)==1)
                                                     {
                                                                                            if(med1.quantity<=med1.minquantity)
                                                                                            {gotoxy(1,vjx);printf("%d.%s",vb,med1.name);gotoxy(15,vjx);printf("%.0f",med1.quantity);vjx=vjx+1;vb=vb+1;}}
                                                                                          printf("\nNo  other items near reorder level");getch();goto pass;
                                                         

                                                         break;case 6:printf("Enter item name Three letters");
                                                         scanf("%s",fad);
                                                         rewind(invent);
                                                         while(fread(&med1,recsize,1,invent)==1)
                                              { if(strnicmp(fad,med1.name,3)==0){printf("\n%s\t%.1f",med1.name,med1.quantity);}printf("Press Any key to go to main menu");getch();goto pass;}break;
                                                        case 7:
{
filer();
  FILE *fback;
  fback=fopen("Backup.xls","w");
  rewind(invent);
  while(fread(&med1,recsize,1,invent)==1)
    fwrite(&med1,recsize,1,fback);
  fclose(fback);
  
}goto fp;break;
                                                              }
                                                              }else{system("cls");
                                                              strcpy(username,tres);
                                                              tresspass=fopen("trespass.dat","a+");
                                                              fprintf(tresspass,"%s\n",tres);
                                                              fclose(tresspass);
                                                              while(p<18){printf("\n\n\n\n\n\tPASSWORD MISMATCH!!! Press any key to go back to the welcome screen\t");Beep(900,500);Beep(900,500);getch();goto fp;
               p=p+1;}}}break;
                case 2:system("cls");printf("\t              Welcome to Prashant Medical Hall\n\n");passer: system("cls");
                
                
                printf("\t              Welcome to Prashant Medical Hall\n\n");
                printf("\n1.To Issue Items from Stock\n2.To exit and Backup\n");
                scanf("%d",&e);
                switch(e)
                {case 1:sum=0;   up: printf("\t              Welcome to Prashant Medical Hall"); system("cls");printf("\t              Welcome to Prashant Medical Hall\n\n\n"); 
                printf("\nEnter item name to issue    ");
                scanf("   %s",issued);
               
                rewind(invent);
                while(fread(&med1,recsize,1,invent)==1)
               {if(strcmp(issued,med1.name)==0) 
                 
                                                       
                                                       { strcpy(issued,biller.issuename);
                                                       
                                                       
                                                      
                                                       strcpy(biller.issueexp,med1.exp);
                                                                                       printf("Item to be issued    %s",med1.name);
                                                                                       printf("\nItem code to be issued  %s",med1.code);
                                                                                       printf("\nItems in stock    %.1f",med1.quantity);list: 
                                                                                        printf("\nEnter quantity to issue   ");
                                                                                        scanf("%f",&biller.issuequantity);
                                                                                        if(biller.issuequantity>med1.quantity){
                                                                                                                               printf("Not Enough Item in Stock\nYou can only issue     %.2f\nPress any key to issue.",med1.quantity);Beep(900,500);Beep(900,500);Beep(900,500);getch();goto list;}
                                                                                        printf("\nItem expiry date   %d/%d",med1.m,med1.y);
                                                                                        t=((biller.issuequantity)*(med1.mrp));
                                                                                        sum=sum+t;
                                                                                        
                                                                                        
                                                                                        med1.quantity=med1.quantity-biller.issuequantity;
                                                                                        printf("\n\n\nThe amount to be paid=  %.2f\n\n",sum);
                                                                                       fileday=(sum+fileday); printf("\nitem left    %.1f\n",med1.quantity);
                                                                                         fseek(invent,-recsize,SEEK_CUR);
                                                  fwrite(&med1,recsize,1,invent);
                                                  printf("Do you want to issue more items 1 for yes/0.for no");
                                                  scanf("%d",&f);
                                                  if(f==1)
                                                  {goto up;}
                                                  else if(f==0){goto passer;}break;}}case 2:goto fp;}
                                                  
                     
                     
                                                  
                                                              
                                                                                                     
                                                                                                     
                                                                                                     
                                                                                                     
                                                                                                     
                                                                                                     
                                                                                                     
                                                                                                                                                                                                          }                                         
                                                                                                     
                                                                                                    
                                                                                 getch();}
                                                                                 
void filer()
{ FILE *filler;
     rewind(invent);
     filler=fopen("Inventory.xls","w+");
    while(fread(&med1,recsize,1,invent)==1)
    { printf("%s",med1.name);
                                           fprintf(filler,"%s\t%s\t%.0f\t%.2f\t%d//%d\n",med1.name,med1.code,med1.quantity,med1.mrp,med1.m,med1.y);
}fclose(filler);                                                                                                             }                               
                                                              
                                                              
