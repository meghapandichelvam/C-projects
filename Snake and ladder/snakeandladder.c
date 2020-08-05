#include<stdio.h>
#include<conio.h>
#include<time.h>

char fname1[10],lname1[10],fname2[10],lname2[10],ch;
int box[30],i,player;

void print(int place1,int place2,char mark1,char mark2);
int check_SandL(int place);
char UserName(char *fname1,char *lname1,char *fname2,char *lname2);
int choice();

void main()
{
	system("cls");
	char mark,mark1,mark2;
	int ply1,ply2,place1=0,place2=0,n=0,newplace1=0,newplace2=0,flag=0;
	
	time_t t;
	
	
	UserName(fname1,lname1,fname2,lname2);
	system("cls");
	system("color 31");
	// enter the value in boxes
	for(i=0;i<30;i++)
	{
		box[i]=i+1;
	}
	
	printf("welcome to the snake and ladder game");
	printf("%s %s and %s %s",fname1,lname1,fname2,lname2);
	printf("\n player 1 'O'");
	printf("\n player 2 'X'");
	
	player = choice();
	while(flag == 0)
	{
		mark = (player%2!=0)?'O':'X';
		printf("\nmark:%c",mark);
		printf("\nRoll the dice Pressing enter");
		toupper(getch());
		srand((unsigned)time(&t));
		if(mark == 'O')
		{
			mark1 ='O';
			ply1 = (rand()%6)+1;
			printf("%d",ply1);
			
			if(ply1 != 0)
			{
				place1= place1+ply1;
				printf("\tplace:%d\n",place1);
				newplace1=check_SandL(place1);
				if(newplace1>place1)
				{
					printf("\ncongrats %s %s have placed in ladder\n",fname1,lname1);
					place1=newplace1;
				}
				if(newplace1<place1)
				{
					printf("\nalas %s %s are placed in snake\n",fname1,lname1);
					place1=newplace1;
				}
				if(place1==30)
				{
					printf("congrats %s %s have won",fname1,lname1);
					flag=1;
					sleep(5);
					break;
				}
				if(place1>30)
				{
					place1=place1-ply1;
					printf("the number is bigger you need only %d to win\n",30-place1);
				}
				ply1 =0;
			}
		}
		if(mark == 'X')
		{
			mark2 ='X';
			ply2= (rand()%6)+1;
			printf("%d",ply2);
			if(ply2 != 0)
			{
				place2 = place2+ply2;
				printf("\tplace:%d\n",place2);
				newplace2=check_SandL(place2);
				if(newplace2>place2)
				{
					printf("\ncongrats %s %s have placed in ladder\n",fname2,lname2);
					place2=newplace2;
				}
				if(newplace2<place2)
				{
					printf("\nalas %s %s are placed in snake\n",fname2,lname2);
					place2=newplace2;
				}
				if(place2==30)
				{
					printf("congrats %s %s have won",fname2,lname2);
					flag =1;
					sleep(5);
					break;
				}
				if(place2 > 30)
				{
					place2=place2-ply2;
					printf("the number is bigger you need only %d to win\n",30-place2);
				}
				ply2 =0;
			}
		}
			
			player++;
			if(n==30){
			printf("the game is draw");
			flag = -1;}
			n++;
			print(place1,place2,mark1,mark2);
	}

}

void print(int place1,int place2,char mark1,char mark2)
{
	printf("\n SNAKE AND LADDER GAME\n");
 	printf("\nSNAKE\t17->4\t19->7\t21->9\t27->1");
 	printf("\nLADDER\t3->22\t5->8\t11->26\t20->29\n");
 	
	//printing value
	for(i=29;i>=0;i--)
	{
			if(box[i]==place1 && place1==place2)
			{
				printf("|%c%c",mark1,mark2);
			}
			else if(box[i]==place1)
			{
				if(box[i]<=9)
				{
					printf("| %c ",mark1);
				}
				else
				{
					printf("| %c ",mark1);
				}
				
			}
			else if(box[i]==place2)
			{
				printf("|%c",mark2);
			}
			else
				printf("|%d",box[i]);
			
			if(i==20||i==10||i==0)
			{
				printf("\n");
				printf("-------------------------------\n");
			}
			
	}
}
int check_SandL(int place)
{
	switch(place)
	{
		case 3:
 			return 22;
 			break;
 		case 5:
 			return 8;
 			break;
 		case 11:
 			return 26;
 			break;
 		case 20:
 			return 29;
 			break;
 		case 17:
 			return 4;
 			break;
 		case 19:
 			return 7;
 			break;
 		case 21:
 			return 9;
 			break;
 		case 27:
 			return 1;
 			break;
 		default:
 			return place;
	}
}
char UserName(char *fname1,char *lname1,char *fname2,char *lname2){
	
	system("color 31");
 	printf("\nfirstname of player1:");
	scanf("%s",&*fname1);
	printf("\nlastname of player1:");
	scanf("%s",&*lname1);
	printf("\nfirstname of player2:");
	scanf("%s",&*fname2);
	printf("\nlastname of player 2:");
	scanf("%s",&*lname2);
	
	*fname1=toupper(*fname1);
	*lname1=toupper(*lname1);
	*fname2=toupper(*fname2);
	*lname2=toupper(*lname2);
	
}

int choice()
{
	
	printf("\ndo you want to play first?");
	printf("\n Yes: Y or y\tNo: N or n");
	printf("\nenter the choice");
	getchar();
	scanf("%c",&ch);
	
	
	if(ch =='Y'|| ch == 'y')
		{
		return 1;
		}
	if(ch =='N' || ch == 'n' )
		{
		return 2;
		}
}

