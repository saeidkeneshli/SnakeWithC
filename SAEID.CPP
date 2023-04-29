# include <stdlib.h>
# include <stdio.h>
# include <iostream.h>
# include <conio.h>
# include <dos.h>

# define MAX_X 80
# define MAX_Y 25
# define UP    72
# define DOWN  80
# define LEFT  75
# define RIGHT 77

int snake[24][2]; //mar
char Nfood[2];    //qaza
int dom = 2;      //andazeye awalieye mar
int shekl;        //sheklake mar k b sorat random entekhab mishavad
int divar[2];
int neveshte[2];
int speed = 1;    //taeine sorate harkate mar
int x = 0;        //baraye barkhord ha




void kadr ();     //kadr dor
void mane ();     //manehaye bazi
void mar ();      //shekle awalieye mar
int ascii_code ();//baraye dadane ascii code jahat ha
void food();      //tabe qaza
void play ();     //tabe bazi
void win();       //tabe piroozi
void lose();      //tabe tamam shodane bazi
int BAR();        //Barkhord Az Rast
int BAC();        //Barkhord Az Chap
int BAB();        //Barkhord Az Bala
int BAP();        //Barkhord Az Paeiin




void main ()
{

clrscr ();

randomize ();

shekl = random(3)+4; //entekhabe tasadofie shekle mar


cout << dom << " ";
cprintf("%c",3);    //namayeshe score dar samte rast-balla
gotoxy(72,1);
printf("SPEED 10"); //namayeshe speed dar samte chap-balla


kadr ();
mane ();
food ();
mar  ();
play ();


getch();
}


//-------------------------------kadr bandi va mane gozari---------------------------------------
void kadr ()
{

neveshte[0]=30;
neveshte[1]=1;

gotoxy (neveshte[0],neveshte[1]);
cout << "   *** SNAKE ***   " ;    //neveshteye balaye safhe

divar[0]=1;
divar[1]=2;
gotoxy (divar[0],divar[1]);
for (int x=0;x!=80;x++)
	cprintf("%c",1) ;         //kadr bala

for (int j=0;j!=22;j++)
	{
	cprintf("%c",1);
	cout << "\n" ;
	}                        // kadr chap

divar[0]=1;
divar[1]=24;
gotoxy (divar[0],divar[1]);
for (int i=0;i!=80;i++)
	cprintf("%c",1) ;       // kadr paein

divar[0]=80;
divar[1]=2;
gotoxy (divar[0],divar[1]);
for (int q=2;q!=24;q++)
	{
	divar[1]=q;
	gotoxy (80,divar[1]) ;
	cprintf("%c",1);
	cout << "\n" ;         // kadr rast
	}

divar[0]=55;
divar[1]=25;
gotoxy(divar[0],divar[1]);
cout << "Produce By SAEID KENESHLI"; //neveshteye paein

}

void mane ()
{
divar[0]=20;
divar[1]=8;


gotoxy (divar[0],divar[1]);
for (int i=8;i!=15;i++)
	{
	divar[1]=i;
	gotoxy (20,divar[1]);
	cprintf("%c",1);
	cout << "\n" ;
	}                     //khat amodie awal

divar[0]=40;
divar[1]=8;
gotoxy (divar[0],divar[1]);
for (int j=8;j!=15;j++)
    {
    divar[1]=j;
    gotoxy (40,divar[1]);
    cprintf("%c",1);
    cout << "\n" ;
    }				//khate amodie dowom

divar[0]=60;
divar[1]=8;
gotoxy (divar[0],divar[1]);
for (int q=8;q!=15;q++)
	{
	divar[1]=q;
	gotoxy(60,divar[1]);
	cprintf("%c",1);
	cout << "\n" ;
	}			 //khate amodie sewom

divar[0]=20;
divar[1]=18;
gotoxy (divar[0],divar[1]);
for (int z=20;z!=35;z++)
	cprintf("%c",1);	//khate ofoqie awal

divar[0]=45;
divar[1]=18;
gotoxy (divar[0],divar[1]);
for (int r=45;r!=61;r++)
	cprintf("%c",1);	//khate ofoqie dowom

}
//--------------------------------tashkile mar---------------------------------------------------------
void mar ()
{
int x,y;
x = random(65)+5; // mar roye kadr nemiofte
y = random(10)+5; // jaye awalieye mar random entekhab mishavad

for(int i=8;i!=15;i++)
	for(int j=20;j!=35;j++)
		for(int k=45;k!=60;k++)
			if(x==20 && y==i  //mane amodi awal
			|| x==40 && y==i  //mane amodi dowom
			|| x==60 && y==i  //mane amodi sewom
			|| x==j  && y==18 //mane ofoqi awal
			|| x==k  && y==18)//mane ofoqi dowom
				{
				x = random(65)+5;
				y = random(10)+5;
				}   // mar roye mane ha nemiofte

snake[0][0] = x; // mokhtasate awalieye mar
snake[0][1] = y;
snake[1][0] = x;
snake[1][1] = y+1;
snake[2][0] = x;
snake[2][1] = y+2;

for (int z=0;z<3;z++)
	{
	gotoxy(snake[z][0] , snake[z][1]);
	cprintf("%c",shekl);
	gotoxy(1,1);
	}            //namayeshe mar

}



void food() //qaza
{
Nfood[0] = random(76)+2; //jaye food random ast
Nfood[1] = random(20)+3; //food roye kadr nemiofte

for(int i=8;i!=15;i++)
	for(int j=20;j!=35;j++)
		for(int k=45;k!=60;k++)
			if(Nfood[0]==20 && Nfood[1]==i  //mane amodi awal
			|| Nfood[0]==40 && Nfood[1]==i  //mane amodi dowom
			|| Nfood[0]==60 && Nfood[1]==i  //mane amodi sewom
			|| Nfood[0]==j  && Nfood[1]==18 //mane ofoqi awal
			|| Nfood[0]==k  && Nfood[1]==18)//mane ofoqi dowom
				{
				Nfood[0] = random(76)+2;
				Nfood[1] = random(20)+3;
				} //food roye mane ha nemiofte

for (int t=dom;t>0;t--)  // food roye mar nemiofte
	if (Nfood[0] == snake[t][0] && Nfood[1] == snake[t][1])
		{
		Nfood[0] = random(76)+2;
		Nfood[1] = random(20)+3;
		}
gotoxy (Nfood[0] , Nfood[1]);
cprintf ("%c",3);           //namayeshe food

}

//--------------------------------bazi shoro mishavad---------------------------------------

int ascii_code()
{
char ch;
int x=0;
ch = getch();
x=ch;
if (x==0)
	{
	ch=getch();
	x=ch;
	}
return x;
}


void play ()
{//key = kelid baraye taqire jahat migirad,def = harkate mar dar awal b balla ast
//d = sorate awalie(meqdare delay)
char key , def=UP ; int D=300 , speed=1;
	while(1)
	{
		if(kbhit()) //komak az aqaye azizi
		{
			key = ascii_code();
			if(key == 27)
				break;
		}

		gotoxy(snake[dom][0],snake[dom][1]);
		printf(" ");//entehaye mar ra pak mikonad

		for(int i=dom;i>0;i--)
		{
			snake[i][0] = snake[i-1][0];
			snake[i][1] = snake[i-1][1];
		} //ja be ja kardane teke mar

		switch(key)
		{
		case UP   : snake[0][1]--; if(BAP()==1)
						{
						key = RIGHT;
						x=0;
						}
					   if(BAP()==2)
						{
						key = LEFT;
						x=0;
						}
						gotoxy(1,1);
			   break;
		case DOWN : snake[0][1]++; if(BAB()==1)
						{
						key = RIGHT;
						x=0;
						}
					   if(BAB()==2)
						{
						key = LEFT;
						x=0;
						}
						gotoxy(1,1);
			   break;
		case LEFT : snake[0][0]--; if(BAR()==1)
						{
						key = UP;
						x=0;
						}
					    if(BAR()==2)
						{
						key = DOWN;
						x=0;
						}
						gotoxy(1,1);
			   break;
		case RIGHT: snake[0][0]++; if(BAC()==1)
						{
						key = UP;
						x=0;
						}
					    if(BAC()==2)
						{
						key = DOWN;
						x=0;
						}
			   break;
		default: key = def;
		}
		if(snake[0][0] == Nfood[0] && snake[0][1] == Nfood[1])
			{
			dom ++ ;
			gotoxy(1,1);
			cout << dom << " " ; cprintf("%c",3);
			snake[dom][0] = snake [dom-1][0];
			snake[dom][1] = snake [dom-1][1];
			food ();
			if (dom==23)
				win();
			D = D - 10 ;
			gotoxy(72,1);
			speed++;
			cout << "SPEED " << speed*10 ;
			}//afzayeshe emtiaz
	gotoxy (snake[0][0],snake[0][1]);
	cprintf ("%c",shekl);
	delay(D);

	}
}

//-------------akhare bazi va namayeshe barande ya bazande bodan----------------------------------------------------
void win()    //barande
{

clrscr();

kadr();

textcolor(CYAN); //range neveshte b nili tabdil shawad

gotoxy (37,12);
cprintf("%s","W"); delay(150);
cprintf("%s","I"); delay(150);
cprintf("%s","N"); delay(150);
cprintf("%s","N"); delay(150);
cprintf("%s","E"); delay(150);
cprintf("%s","R"); delay(150);

textcolor(WHITE);

getch();
}

void lose() //bazande
{
clrscr();

kadr();

textcolor(RED);  // range neveshte germez shawad

gotoxy (37,12);
cprintf("%s","L"); delay(160);
cprintf("%s","O"); delay(160);
cprintf("%s","O"); delay(160);
cprintf("%s","S"); delay(160);
cprintf("%s","E"); delay(160);
cprintf("%s","R"); delay(160);

textcolor(WHITE);

getch();
}


//----------------------------nahveye barkhordha-------------------------------------------------------------------


int BAR()//Barkhord Az Rast
{
for (int i=8;i!=15;i++)

	for(int j=12;j!=25;j++)

		if(   snake[0][0]==20 && snake[0][1]==i //mane amodi awal
		   || snake[0][0]==40 && snake[0][1]==i //mane amodi dowom
		   || snake[0][0]==60 && snake[0][1]==i //mane amodi sewom
		   || snake[0][0]==1  && snake[0][1]==j //kadre samte chap
		   || snake[0][0]==60 && snake[0][1]==18)//mane ofoqi dowom
			{
			snake[0][0]++;
			snake[0][1]--;
			dom--;
			gotoxy(snake[dom+1][0],snake[dom+1][1]);
			printf(" ");
			gotoxy(1,1);
			cout << dom << " ";
			x = 1;
			if (dom==0)
				lose();
			}// bad az barkhord balla bere
	for(j=3;j<12;j++)
		if(   snake[0][0]==1 && snake[0][1]==j //divare chap
		   || snake[0][0]==34 &&snake[0][1]==18)//mane ofoqi awal
			{
			snake[0][0]++;
			snake[0][1]++;
			dom--;
			gotoxy(snake[dom+1][0],snake[dom+1][1]);
			printf(" ");
			gotoxy(1,1);
			cout << dom << " ";
			x = 2;
			if (dom==0)
				lose();
			}// bad az barkhord bere paein

	gotoxy(snake[dom][0],snake[dom][1]);
	printf(" ");

return x;
}
int BAC() //Barkhord Az Chap
{
for (int j=12;j!=24;j++)

	for (int i=8;i!=15;i++)

		if(   snake[0][0]==20 && snake[0][1]==i //mane amodi awal
		   || snake[0][0]==40 && snake[0][1]==i //mane amodi dowom
		   || snake[0][0]==60 && snake[0][1]==i //mane amodi sewom
		   || snake[0][0]==80 && snake[0][1]==j  //divar rast
		   || snake[0][0]==20 && snake[0][1]==18)//mane ofoqi awal
			{
			snake[0][0]--;
			snake[0][1]--;
			dom--;
			gotoxy(snake[dom+1][0],snake[dom+1][1]);
			printf(" ");
			gotoxy(1,1);
			cout << dom << " ";
			x=1;
			if (dom==0)
				lose();
			} //bad az barkhord b balla bere
for (j=1;j!=12;j++)

	if(snake[0][0]==80 && snake[0][1]==j
	|| snake[0][0]==45 && snake[0][1]==18)
		{
		snake[0][0]--;
		snake[0][1]++;
		dom--;gotoxy(snake[dom+1][0],snake[dom+1][1]);
			printf(" ");
			gotoxy(1,1);
			cout << dom << " ";
			x=2;
			if (dom==0)
				lose();
		}          //baad az barkhord b paeein bere

	gotoxy(snake[dom][0],snake[dom][1]);
	printf(" ");
return x;
}
int BAB() //Barkhord Az Bala
{
for (int i=0;i!=40;i++)

	for(int j=20;j!=35;j++)

			if(snake[0][0]==i && snake[0][1]==24  //divare paein
			|| snake[0][0]==j && snake[0][1]==18 //mane ofoqi awal
			|| snake[0][0]==20&& snake[0][1]==8) //mane amodi awal
				{
				snake[0][0]++;
				snake[0][1]--;
				dom--;
				gotoxy(snake[dom+1][0],snake[dom+1][1]);
				printf(" ");
				gotoxy(1,1);
				cout << dom << " ";
				x=1;
				if (dom==0)
					lose();
				}  //bere b samte rast
for (i=40;i!=80;i++)

	for(int k=45;k!=60;k++)

		if(snake[0][0]==i && snake[0][1]==24 //divar paein
		|| snake[0][0]==k && snake[0][1]==18 //mane ofoqi dowom
		|| snake[0][0]==40&& snake[0][1]==8  //mane amodi dowom
		|| snake[0][0]==60&& snake[0][1]==8) //mane amodi sewom
			{
			snake[0][0]--;
			snake[0][1]--;
			dom--;
			gotoxy(snake[dom+1][0],snake[dom+1][1]);
			printf(" ");
			gotoxy(1,1);
			cout << dom << " ";
			x=2;
			if (dom==0)
				lose();
			}		//bere b chap
	gotoxy(snake[dom][0],snake[dom][1]);
	printf(" ");
return x;
}
int BAP()
{
for (int i=0;i!=40;i++)

	for (int j=20;j!=35;j++)

		if(snake[0][0]==i && snake[0][1]==2  //divar balla
		|| snake[0][0]==j && snake[0][1]==18 //mane ofoqi awali
		|| snake[0][0]==20&& snake[0][1]==14 //mane amodi awal
		|| snake[0][0]==40&& snake[0][1]==14)//mane amodi dowom
			{
			snake[0][0]++;
			snake[0][1]++;
			dom--;
			gotoxy(snake[dom+1][0],snake[dom+1][1]);
			printf(" ");
			gotoxy(1,1);
			cout << dom << " ";
			x=1;
			if (dom==0)
				lose();
			}	 //bere b rast

for(i=40;i!=80;i++)

	for(j=45;j!=61;j++)

		if(snake[0][0]==i && snake[0][1]==2  //divar balla
		|| snake[0][0]==j && snake[0][1]==18 //mane ofoqi dowom
		|| snake[0][0]==60&& snake[0][1]==14) //mane amodi sewom
			{
			snake[0][0]--;
			snake[0][1]++;
			dom--;
			gotoxy(snake[dom+1][0],snake[dom+1][1]);
			printf(" ");
			gotoxy(1,1);
			cout << dom << " ";
			x=2;
			if (dom==0)
				lose();
			} 		//bere b chap
	gotoxy(snake[dom][0],snake[dom][1]);
	printf(" ");
return x;
}

