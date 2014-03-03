/*
Developed by: Fahad Mohammad Shaon
http://fahadshaon.wordpress.com
	
	
For those who want to copy source, take it call it urs.
 but u know if u take everything from me then u r nothing.
 u have brain use it in good purpose.

For those who want to develop this project, i am very happy and u r
 someone i am looking for. still there is  lots of bugs in my project.
 and i am not that much interested to solved this bugs. and in developers
 point of view there are lots of thing could be developed.

For those who want to develop this project but don’t have sufficient knowledge 
of C or not understanding the code, don’t hesitate contact with me. may help u out.

To compile this u have to keep the Pacman and BGI folder in TC\BIN folder
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<string.h>

#define MAX 32
#define INFINITE 200
#define _L 20	//in graphics mode padding form left
#define _T 20	//in graphics mode padding form top
#define NUM_ENEMY 4

void show_record();

typedef struct record {
	char name[30];
	long score;
}record;
record rec[15];

typedef struct loc{
	int x;
	int y;
}loc;
int length=20;
loc board;			//size of board
loc cur;			//current location of player
loc enemy[NUM_ENEMY];
void initialize_array();	//especial function to initialize arryas for better output

//begining of bfs related funciton proto type and variable
	int cost[MAX][MAX];		//ary that contains cost of every point
	loc ary_bfs[MAX*MAX]={0};	//location ary for bfs
	int count_b=0;
	int b[MAX][MAX]={0};	//ary contains temporary block
	void bfs();			//function to calculate shortest path
	int not_include(loc,int);       //function that return 1 if curnt loc not in bfsary
//end

//begining of board, player,enemy and graphics related funciton proto type and variable

	int a[MAX][MAX]={0};	//ary contains the board
	int color[10];		//ary contains the color of current board
	char mazename[50];		//string that contains name of the maze
	int cur_maze=1;		//intizer for the current number of the maze
	int total_maze=5;		//intizer for the total number of the maze

	void new_maze();
	void board_input();	//function to take the borad from a file
	void board_print();	//to print the board
	void print_board_name();//to print board's name
	void player_print();	//prints the player
	void enemy_print();	//prints enemys
	void player_erase();	//erase players
	void enemy_erase();	//erase enemys
	void init_enemy();	//initialize enemys position
	void init_graph();	//initialize graph
	void print_block(int,int,int);//to print a block of a board
	void print_seed(int,int);	//reprinting a seeded block when enemy moves over it
	void print_general_seed(int,int);//to print general seed
	void print_time();
	void print_life();
	void print_score();

	void music(int t);	//for playing music
//end

//game play related function proto type and variable
	float delay_factor;		//amount of time after that enemy will move
	int life=0;			//number of lifes
	int phase_player;          	//for current phase of the player
	struct dostime_t phase_player_last,phase_player_cur;//calculating the phase time
	int phase_enemy[NUM_ENEMY];	//for current phase of enemy
	struct dostime_t phase_enemy_last[NUM_ENEMY],player_phase_cur[NUM_ENEMY];//calculating the phase time
	struct dostime_t cur_time,last_time;//variables for caculating time duration from last move
	struct dostime_t lst_t,cur_t,str_t;	//time variables to calculate playing time

	long score=0;			//variable for score of player
	int general_seed=2;
	int general_seed_point=2;	//variable for point of general_seed
	int total_general_seed;
	int cur_mode=1;
	void not_kbhit_in_play();

	void mode(int);			//for determination of mode of game
	void welcome();			//splash screen
	void play();			//main function for playing the game
	void player_move(int);          //for moving player one place
	void move();			//checks duration then call move_enemy()
	void move_enemy();		//for moving the enemy
	int isenemy(int,int);
	void game_over();		//to check if player and enemy cought player
	void check_phase();		//to check the phase duration
	void game_over_screen();	//after game over
//end

void init_graph()
{
//initializing the graphic mode

/* request auto detection */
int gdriver = DETECT, gmode, errorcode;

/*initialize graphics and local variables */
initgraph(&gdriver, &gmode, "");

/* read result of initialization */
errorcode = graphresult();
if (errorcode != grOk)  /* an error occurred */
{
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1); /* terminate with an error code */
}

}
void print_block(int i,int j)
{
	//to print each block of the board
	int left,right,top,bottom;

	left=_L+i*length;
	top=_T+j*length;
	right=_L+(i+1.0)*length;
	bottom=_T+(j+1.0)*length;

	setfillstyle(color[0],color[1]);	//as color[0] for fill style color[1] for board color
	bar(left,top,right,bottom);

	if(a[i][j-1]!=1)
	{
		setfillstyle(1, LIGHTGRAY);	//top bar
		bar(left,top,right,top+2);
	}
	if(a[i-1][j]!=1)
	{
		setfillstyle(1, LIGHTGRAY);     //left bar
		bar(left,top,left+2,bottom);
	}
	if(a[i][j+1]!=1)
	{
		setfillstyle(1,DARKGRAY); 	//bottom bar
		bar(left,bottom-3,right,bottom);
	}

	if(a[i+1][j]!=1)
	{
		setfillstyle(1,DARKGRAY);       //right bar
		bar(right-3,top,right,bottom);
	}

}
void print_seed(int i,int j)
{
	if(a[i][j]==2)
		print_general_seed(i,j);
}


void print_general_seed(int i,int j)
{
	int left,right,top,bottom;

	left=_L+i*length;
	top=_T+j*length;
	right=_L+(i+1.0)*length;
	bottom=_T+(j+1.0)*length;

	setfillstyle(1,BLACK);
	bar(left,top,right-1,bottom-1);

	int radius=2;

	setcolor(color[8]);
	circle(_L+(i+.5)*length,_T+(j+.5)*length, radius);

	setfillstyle(SOLID_FILL,color[9]);
	floodfill(_L+(i+.5)*length,_T+(j+.5)*length,color[8]);
}

void print_board_name()
{
	cleardevice();

	struct textsettingstype textinfo;	//structure to retrive the text settings
	char ch;
	float duration;
	struct dostime_t name_last_time,name_cur_time;
	gettextsettings(&textinfo);
	setcolor(color[1]);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(2,HORIZ_DIR,8);
	outtextxy(getmaxx()/2,getmaxy()/2,mazename);

	_dos_gettime(&name_last_time);

	do
	{
	while(!kbhit())
	{
		_dos_gettime(&name_cur_time);
		duration=(name_cur_time.hsecond-name_last_time.hsecond)*.01+(float)(name_cur_time.second-name_last_time.second);
		if(duration>2.0)
		{
			//resetting text style before return
			settextstyle(textinfo.font,textinfo.direction,textinfo.charsize);
			settextjustify(textinfo.horiz,textinfo.vert);
			return;
		}
	}

	ch=getch();
	_dos_gettime(&name_cur_time);
	duration=(name_cur_time.hsecond-name_last_time.hsecond)*.01+(float)(name_cur_time.second-name_last_time.second);
	if(duration>2.0)
	{
		//resetting text style before return
		settextstyle(textinfo.font,textinfo.direction,textinfo.charsize);
		settextjustify(textinfo.horiz,textinfo.vert);
		return;
	}
	}while(ch!=27);

	//for reseting text style
	settextstyle(textinfo.font,textinfo.direction,textinfo.charsize);
	settextjustify(textinfo.horiz,textinfo.vert);
}

void board_print()
{
	//printing the board
//	print_time();
	print_board_name();
	print_life();
	print_score();

	int i,j;
	for(i=0;i<board.x;i++)
	{
		for(j=0;j<board.y;j++)
		{
			if(a[i][j]==1)		//if block exists
			{
				print_block(i,j);
			}
			else if(a[i][j]==0)	//if empty
			{
				setfillstyle(0,BLACK);
				bar(_L+i*length,_T+ j*length,_L+(i+1.0)*length,_T+(j+1.0)*length);
			}
			else if(a[i][j]==2)	//for general seed
			{
				print_general_seed(i,j);
			}
		}
	}
}

void player_erase()
{
	//for erasing player.
	setfillstyle(8,BLACK);
	bar(_L+cur.x*length,_T+cur.y*length,_L+(cur.x+1)*length-1,_T+(cur.y+1)*length-1);
}

void enemy_erase()
{
	//for erasing the enemy
	int i;
	for(i=0;i<NUM_ENEMY;i++)
	{
		setfillstyle(8,BLACK);
		bar(_L+enemy[i].x*length,_T+ enemy[i].y*length,_L+(enemy[i].x+1)*length-1,_T+(enemy[i].y+1)*length-1);
		print_seed(enemy[i].x,enemy[i].y);
	}
}

void player_print()
{
	//for printing player
	int radius=length/2-2;

	loc center;
	center.x=(cur.x+.5)*length-2;
	center.y=(cur.y+.5)*length;
	setcolor(color[2]);
	circle(_L+center.x,_T+center.y, radius);

	if(phase_player==1)	//if player is normal
		setfillstyle(SOLID_FILL, color[3]);
	else if(phase_player==0)	//if player is newly boarn
		setfillstyle(SOLID_FILL,color[4]);

	floodfill(_L+center.x,_T+center.y,color[2]);
}

void enemy_print()
{
	//printin enemy
	int i;
	int radius=length/2-2;
	loc center;

	for(i=0;i<NUM_ENEMY;i++)
	{

		center.x=(enemy[i].x+.5)*length-2;
		center.y=(enemy[i].y+.5)*length;
		setcolor(color[5]);
		circle(_L+center.x,_T+center.y, radius);
		setfillstyle(SOLID_FILL,color[6]);
		floodfill(_L+center.x,_T+center.y,color[5]);
	}
}

int isenemy(int ene_X,int ene_Y)
{
	//for checking is this place contins an enemy
	int i;
	for(i=0;i<NUM_ENEMY;i++)
	{
	    if(enemy[i].x==ene_X && enemy[i].y==ene_Y)
		return 1;
	}
	return 0;
}


void move_enemy()
{
	//for moving enemy
	int i,j;
	int p[4],c,min;
	for(i=0;i<NUM_ENEMY;i++)
	{
		c=cost[enemy[i].x][enemy[i].y];		//current position
		p[0]=cost[enemy[i].x+1][enemy[i].y];	//right position
		p[1]=cost[enemy[i].x][enemy[i].y+1];	//down
		p[2]=cost[enemy[i].x-1][enemy[i].y];	//left
		p[3]=cost[enemy[i].x][enemy[i].y-1];	//top
		if(c>p[0] || c>p[1] || c>p[2] || c>p[3])
		{
			min=0;
			for(j=0;j<4;j++)
			{
				if(p[j]<p[min])		//to check the lowest cost place
				{
					min=j;
				}
			}


			switch(min)
			{
			case 0:
				if(!isenemy(enemy[i].x+1,enemy[i].y))
				{
					b[enemy[i].x][enemy[i].y]=1;
					cost[enemy[i].x][enemy[i].y]=INFINITE;
					count_b++;
					bfs();
					enemy[i].x++;
				}
			break;
			case 1:
				if(!isenemy(enemy[i].x,enemy[i].y+1))
				{
				b[enemy[i].x][enemy[i].y]=1;
				cost[enemy[i].x][enemy[i].y]=INFINITE;
				count_b++;
				bfs();
				enemy[i].y++;
				}
			break;
			case 2:
				if(!isenemy(enemy[i].x-1,enemy[i].y))
				{
				b[enemy[i].x][enemy[i].y]=1;
				cost[enemy[i].x][enemy[i].y]=INFINITE;
				count_b++;
				bfs();
				enemy[i].x--;
				}
			break;
			case 3:
				if(!isenemy(enemy[i].x,enemy[i].y-1))
				{
				b[enemy[i].x][enemy[i].y]=1;
				cost[enemy[i].x][enemy[i].y]=INFINITE;
				count_b++;
				bfs();
				enemy[i].y--;
				}
			break;
			}
		}
	}
}

void game_over()
{
	int i;
	for(i=0;i<NUM_ENEMY;i++)
	{
		if(cur.x==enemy[i].x && cur.y==enemy[i].y)
		{
			if(phase_player==1)
			{
				music(2);
				delay(500);
				life--;
				print_life();
				cur.x=board.x/2;
				cur.y=board.y/2;
				phase_player=0;
				player_print();
				_dos_gettime(&phase_player_last);
			}
			else if(phase_player==0)
			{
				enemy_print();
				player_print();
			}
		}
	}
	if(total_general_seed<=0)
	{
		cur_maze++;
		new_maze();
	}
	if(life<0)
	{
		cur_maze=total_maze+1;
		new_maze();
	}
}

void check_phase()
{
	float duration=0;

	_dos_gettime(&phase_player_cur);

	duration=(phase_player_cur.hsecond-phase_player_last.hsecond)*.01+(float)(phase_player_cur.second-phase_player_last.second)+(phase_player_cur.minute-phase_player_last.minute)*60.0;
	if(duration>8.0)
	{
		if(phase_player==0)	//if newly boarn
		{
			phase_player=1;	//making it normal
			_dos_gettime(&phase_player_last);
			player_print();
		}
	}

}

void move()
{
	//funciton the cheks the time an allow enemy to move
	float duration=0;
	int i,j;
	if(count_b>15)
	{
	for(i=0;i<board.x;i++)
	{
		for(j=0;j<board.y;j++)
		{
			b[i][j]=0;
		}
	}
	count_b=0;
	}
	_dos_gettime(&cur_time);
	duration=(cur_time.hsecond-last_time.hsecond)*.01+(float)(cur_time.second-last_time.second)+(cur_time.minute-last_time.minute)*60.0;
	if(duration>delay_factor)
	{
		enemy_erase();
		move_enemy();
		enemy_print();
		game_over();
		_dos_gettime(&last_time);
	}
}

void player_move(int dirct)
{
	loc direction[4]={{0,-1},{1,0},{0,1},{-1,0}};	//up right down left

	player_erase();
	if(a[cur.x][cur.y]==2)
	{
		a[cur.x][cur.y]=0;
		score += general_seed_point;
		print_score();
		music(3);
		total_general_seed--;
	}
	cur.x += direction[dirct].x;
	cur.y += direction[dirct].y;
	game_over();
	player_print();
	bfs();
}

void print_time()
{
	long duration;
	char str[100];
	duration=(cur_t.second-str_t.second)+(cur_t.minute-str_t.minute)*60;
	setcolor(6);
	setfillstyle(1,BLACK);
	settextjustify(RIGHT_TEXT,CENTER_TEXT);
	settextstyle(0,HORIZ_DIR,1);

	bar(450,0,getmaxx(),5+textheight("W"));

	sprintf(str,"Playing time : %02d:%02d",(int)duration/60,(int)duration%60);

	outtextxy(getmaxx(),5,str);
}
void print_life()
{
	char str[50];
	setfillstyle(1,BLACK);
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	settextstyle(0,HORIZ_DIR,1);
	sprintf(str,"Life(s): %d",life);
	bar(0,_T+board.y*length+10,textwidth(str)+50,_T+board.y*length+30+textheight("W"));
	setcolor(2);
	outtextxy(0,_T+board.y*length+30,str);

}
void print_score()
{
	char str[50];
	setfillstyle(1,BLACK);
	settextjustify(RIGHT_TEXT,CENTER_TEXT);
	settextstyle(0,HORIZ_DIR,1);

	bar(450,_T+board.y*length+20,getmaxx(),_T+board.y*length+30+textheight("W"));

	setcolor(9);
	sprintf(str,"Score: %3ld",score);
	outtextxy(getmaxx(),_T+board.y*length+30,str);
}

void not_kbhit_in_play()
{
	char str[100];

	_dos_gettime(&cur_t);
	if(cur_t.second>lst_t.second || cur_t.minute >lst_t.minute)
	{
		print_time();
//		print_life();
//		print_score();
		_dos_gettime(&lst_t);
	}
	move();
	game_over();
	check_phase();
}

void play()
{
//main game play function

init_enemy();
board_print();
player_print();
enemy_print();
bfs();

char c1,c2;

_dos_gettime(&last_time);

_dos_gettime(&str_t);
_dos_gettime(&lst_t);
_dos_gettime(&cur_t);
do
{

while(!kbhit())
{
	not_kbhit_in_play();
}
do
{
	while(!kbhit())
	{
		not_kbhit_in_play();
	}
	c1=getch();
}while(c1!=0);

c2=getch();

switch(c2)
{
case 'H':     //up arrow key
	if(a[cur.x][cur.y-1]!=1)
		player_move(0);
break;
case 'M':	//right arrow key
	if(a[cur.x+1][cur.y]!=1)
		player_move(1);
break;
case 'P': 	//down arrow key
	if(a[cur.x][cur.y+1]!=1)
		player_move(2);
break;
case 'K':	//left arrow key
	if(a[cur.x-1][cur.y]!=1)
		player_move(3);
break;
case 94:	//ctrl+F1
case 'h':    	//alt+F1
case 31:      	//alt+s
	cur_maze++;
	new_maze();
break;
case 23:	//alt+i
	score+=500;
	print_score();
break;
case 45:	//atl+x
	cur_maze = total_maze+1;
	new_maze();
break;
}
	move();
	check_phase();
	game_over();
}while(cur_mode==2);

}

void board_input()
{
	//to read the maze form a file
	total_general_seed=0;
	FILE *fr;
	char str[100];
	sprintf(str,"pacman\\%d.txt",cur_maze);
	fr=fopen(str,"r");
	int i,j,c;

	fscanf(fr,"%[^\n]",mazename);
	fscanf(fr,"%d%d",&board.x,&board.y);

	for(j=0;j<board.y;j++)
	{
		for(i=0;i<board.x;)
		{
			fscanf(fr,"%d",&c);
			if(c==0)
			{
				c=general_seed;
				total_general_seed++;
			}
			a[i++][j]=c;
		}
	}
	for(i=0;i<10;i++)
	{
		fscanf(fr,"%d",&color[i]);
	}
	fscanf(fr,"%f",&delay_factor);
fclose(fr);
}
void init_enemy()
{
	phase_player=1;
	int i;
	for(i=0;i<NUM_ENEMY;i++)
		phase_enemy[i]=1;


	cur.x=board.x/2;
	cur.y=board.y/2;

	enemy[0].x=1;
	enemy[0].y=1;

	enemy[1].x=board.x-2;
	enemy[1].y=1;

	enemy[2].x=1;
	enemy[2].y=board.y-2;

	enemy[3].x=board.x-2;
	enemy[3].y=board.y-2;
}

void music(int type)
{
int n,i;
double base,tempo;
double ratio=9.0/8.0;//major tone

switch(type)
{
	case 1:
		base=130.81;
		tempo=4;
		n=random(6);
		sound(base*pow(ratio,n)*tempo);
		delay(50);
	break;
	case 2:
		base=80.0;
		for(i=7;i>=0;i--)
		{
			sound(base*pow(ratio,i));
			delay(50);
		}
		nosound();
	break;
	case 3:
		sound(800);	//for click sound
		delay(20);
		nosound();
	break;
}
}

void game_over_screen()
{
	cleardevice();
	char str[100],name[30];
	FILE *fp;
	fp=fopen("pacman\\Height.txt","r");
	fread(rec,sizeof(rec[0]),15,fp);
	fclose(fp);
	int i;
//	int i,j,k;
//	record t;
	int cpx=getmaxx()/2,cpy=getmaxy()/4,h;
	char ch;
	//selection sort

/*	for(i=0;i<15-1;i++)
	{
		j=i;
		for(k=i+1;k<15;k++)
		{
			if(rec[k].score>rec[j].score)
			j=k;
		}
		t=rec[i];
		rec[i]=rec[j];
		rec[j]=t;
	}
*/

	setcolor(4);
	settextstyle(7,HORIZ_DIR,5);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	h=textheight("W");
	outtextxy(cpx,cpy,"GAME OVER");

	cpy+=h;
	setcolor(5);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);


	h=textheight("W");
	if(score>rec[14].score)
		outtextxy(cpx,cpy,"Congratulation!");
	cpy+=h;
	setcolor(9);
	settextstyle(2,HORIZ_DIR,5);
	h=textheight("W");
	h++;
	sprintf(str,"Your score %ld",score);
	outtextxy(cpx,cpy,str);

	delay(1000);
	fflush(stdin);
	fflush(stdout);
	getch();
	if(score<rec[14].score)
	{
		cpy+=h;
		outtextxy(cpx,cpy,"This is not a heigh score but butter try next time.");
		//delay(1000);
		getche();

	}
	else if(score>rec[14].score)
	{

		cpy+=h;
		outtextxy(cpx,cpy,"This is one of height scores.");
		cpy+=h;

		//getch();
		outtextxy(cpx,cpy,"Please Enter your name:");
		cpy+=h;
		setfillstyle(11,RED);
		bar(cpx-150,cpy-h+3,cpx+150,cpy+3);
		i=0;
		do
		{
			ch=getche();

			if(ch=='\b'&&i>=0)
				name[i--]='\0';
//			else if(ch==13)
//				break;
			else if(ch==27)
			{
				strcpy(name,"the pacman");
				break;
			}
			else if(i<30)
				name[i++]=ch;

			name[i]='\0';
			if(i<=0)
				setfillstyle(11,RED);
			else
				setfillstyle(1,RED);
			bar(cpx-150,cpy-h+3,cpx+150,cpy+3);
			outtextxy(cpx,cpy,name);
		}while(ch!=13);
		name[i]='\0';


		int j;
		record temp;
		for(i=0;i<15;i++)
		{
			if(score>rec[i].score)
			{
			temp=rec[i];
			rec[i].score=score;
			strcpy(rec[i].name,name);
			for(j=14;j>i;j--)
			{
				rec[j]=rec[j-1];
			}
			rec[i+1]=temp;
			i=15;
			}
		}
		fp=fopen("pacman\\Height.txt","w");
		fwrite(rec,sizeof(rec[0]),15,fp);
		fclose(fp);
	}
	show_record();
	char chr;
	do
	{
	chr=getch();
	}while(chr!=27);

	closegraph();
	exit(1);
}
void show_record()
{
	int i;
	int cpx=getmaxx()/2,cpy=getmaxy()/4,h;
	char string[60];
	cleardevice();

	setcolor(4);
	settextstyle(8,HORIZ_DIR,5);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	h=textheight("W");
	outtextxy(cpx,cpy,"HALL OF FAME");
	cpy+=h;

	setcolor(9);
	settextstyle(2,HORIZ_DIR,5);
	h=textheight("W");
	h++;

	for(i=0;i<15;i++)
	{
		sprintf(string,"%2d %20s %5ld",i+1,rec[i].name,rec[i].score);
		cpy+=h;
		outtextxy(cpx,cpy,string);
	}
	outtextxy(getmaxx()-200,getmaxy()-30,"Press ESC to Exit");

}

void welcome()
{
	int count=20;
	double duration;
	char ch,str[100];
	struct dostime_t music_cur_time,music_last_time;
	struct textsettingstype textinfo;
	_dos_gettime(&music_last_time);
	int midx=getmaxx()/2,midy=getmaxy()/2;

	gettextsettings(&textinfo);
	setcolor(6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(1, HORIZ_DIR, 8);
	outtextxy(midx, midy, "The PacMan");
	setcolor(LIGHTGRAY);
	settextstyle(0,HORIZ_DIR,1);
	settextjustify(RIGHT_TEXT,TOP_TEXT);
	outtextxy(getmaxx(),getmaxy()-10,"Press ESC to continue");
	do
	{
	while(!kbhit())
	{
		_dos_gettime(&music_cur_time);
		duration=(music_cur_time.hsecond-music_last_time.hsecond)*.01+(float)(music_cur_time.second-music_last_time.second);
		if(duration>0.15)
		{
			music(1);
			count--;
			_dos_gettime(&music_last_time);
			setcolor(count%15+1);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			settextstyle(1, HORIZ_DIR, 8);
			outtextxy(midx, midy, "The PacMan");

		}
		if(count<0)
		{
			nosound();
			break;
		}
	}
	if(count<0) break;
	ch=getch();
	}while(ch!=27 && cur_mode==1);
	nosound();
	//for reseting text style
	settextstyle(textinfo.font,textinfo.direction,textinfo.charsize);
	settextjustify(textinfo.horiz,textinfo.vert);
}

void mode(int m)
{
switch(m)
{
case 1:
	cur_mode=1;
	welcome();
break;
case 2:
	cur_mode=2;
	play();
break;
case 3:
	cur_mode=3;
	game_over_screen();
break;
}

}
void new_maze()
{
	if(cur_maze>total_maze)
	{
		mode(3);
		return;
	}
	initialize_array();
	board_input();
	mode(2);
}

int main()
{
	init_graph();
	mode(1);
	new_maze();
	closegraph();
	return 0;
}

void initialize_array()
{
	//for initializing the cost array
	int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			cost[i][j]=INFINITE;
		}
	}
}

int not_include(loc c,int to)
{
	//returns 0 if c location is in the que
	//returns 1 if c location is not in the que
	int i;
	for(i=0;i<to;i++)
	{
		if(c.x==ary_bfs[i].x && c.y==ary_bfs[i].y)
			return 0;
	}
	return 1;
}

void bfs()
{
	loc bfs_cur,temp;

	temp.x=cur.x;
	temp.y=cur.y;

	bfs_cur.x=temp.x;
	bfs_cur.y=temp.y;

	int head=0,tail=0;

	ary_bfs[tail].x=bfs_cur.x;
	ary_bfs[tail].y=bfs_cur.y;
	tail++;
	cost[bfs_cur.x][bfs_cur.y]=0;

	while(tail<board.x*board.y && head<tail )
	{

		temp.x=bfs_cur.x+1;
		temp.y=bfs_cur.y;
		if((temp.x<board.x) && (not_include(temp,tail)))
		{
			if(a[temp.x][temp.y]!=1 && b[temp.x][temp.y]!=1)
			{
				ary_bfs[tail].x=temp.x;
				ary_bfs[tail].y=temp.y;
				cost[temp.x][temp.y]=cost[bfs_cur.x][bfs_cur.y]+1;
				tail++;
			}
		}

		temp.x=bfs_cur.x;
		temp.y=bfs_cur.y+1;
		if((temp.y<board.y) && (not_include(temp,tail)))
		{
			if(a[temp.x][temp.y]!=1 && b[temp.x][temp.y]!=1)
			{
				ary_bfs[tail].x=temp.x;
				ary_bfs[tail].y=temp.y;
				cost[temp.x][temp.y]=cost[bfs_cur.x][bfs_cur.y]+1;
				tail++;
			}
		}
		temp.x=bfs_cur.x-1;
		temp.y=bfs_cur.y;
		if((temp.x>=0) && (not_include(temp,tail)))
		{
			if(a[temp.x][temp.y]!=1 && b[temp.x][temp.y]!=1)
			{
				ary_bfs[tail].x=temp.x;
				ary_bfs[tail].y=temp.y;
				cost[temp.x][temp.y]=cost[bfs_cur.x][bfs_cur.y]+1;
				tail++;
			}
		}

		temp.x=bfs_cur.x;
		temp.y=bfs_cur.y-1;
		if((temp.y>=0) && (not_include(temp,tail)))
		{
			if(a[temp.x][temp.y]!=1 && b[temp.x][temp.y]!=1)
			{
				ary_bfs[tail].x=temp.x;
				ary_bfs[tail].y=temp.y;
				cost[temp.x][temp.y]=cost[bfs_cur.x][bfs_cur.y]+1;
				tail++;
			}
		}

		head++;
		bfs_cur.x=ary_bfs[head].x;
		bfs_cur.y=ary_bfs[head].y;
	}
}