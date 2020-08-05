#include<stdio.h>
#include<conio.h>
#include<time.h>

#define NUM 5 

char bingo[6]={'$','B','I','N','G','O'},checkval;
int i,j,k=1,l=1,n,qarray[26][26],array1[26][26],array2[26][26],temp,random1,random2,randomq,player,qno,flag;
int array[26][26];
int row,col,value,w=0;


void board(int player);
void questions();
void execute(int player);
int win(int array[26][26],int player);

void main()
{
	execute(1);
	board(1);
	execute(2);
	board(2);
	questions();
	player =1;
	k=1;
	l=1;
	while(flag ==0)
	{
		player=(player%2)?1:2;
		if(player == 1)
		{
			if(l==6)
			{
				k++;
				l=1;
			}
			if(k<=5)
			{
				if(l<=5)
				{
				qno = qarray[k][l];
				l++;
				}
			}
		}
		else 
		{
			qno =value;
		}
		
		printf("\nquestion :%d",qno);
		sleep(2);
		system("cls");
		printf("\nit is player %d with mark ",player);
		board(player);
		printf("\nplease enter the row ,column(1-5) and value(1-25)");
		scanf("%d%d%d",&row,&col,&value);
		
		if(player ==1)
		{
		
			if(qno == value && (0<=row && row<=5) && (0<=col && col<=5))
			{
				printf("\nthe entered value is correct");
				array1[row][col]=88;
				w=win(array1,1);
				if(w>0)
				printf("\nthe stage reached is %c",bingo[w]);
				if(w>=5)
				{
				printf("\ncongrats the player %d is the winner",player);
				flag =1;
				}
				player++;
			}
			else
			{
				printf("\nthe entered value is incorrect");
			}
			
		}
		else if(player ==2)
		{
		
			if(qno == value && (0<=row && row<=5) && (0<=col && col<=5))
			{
				printf("\nthe entered value is correct");
				array2[row][col]=89;
				
				w=win(array2,2);
				if(w>0)
				printf("\nthe stage reached is %c",bingo[w]);
				if(w>=5)
				{
				printf("\ncongrats the player %d is the winner",player);
				flag =1;
				}
				player++;
			}
			else
			{
				printf("\nthe entered value is incorrect");
			}
			
		}
		else
		{
			printf("\nrow col or value is invalid");
		}
	}
}

void board(int player)
{
	if(player == 1)
	{ 
		printf("\nthe board of player 1 is\n");
		for(i=1;i<=NUM;i++)
		{
			for(j=1;j<=NUM;j++)
			{
				if(array1[i][j]==88)
				{
				printf("%c\t",88);
				}
				else
				{
				printf("%d\t",array1[i][j]);
				}
			}
			printf("\n");
		}
	}
	else if(player == 2)
	{ 
		printf("\nthe board of player 2 is\n");
		for(i=1;i<=NUM;i++)
		{
			for(j=1;j<=NUM;j++)
			{
				if(array2[i][j]==89)
				{
				printf("%c\t",89);
				}
				else
				{
				printf("%d\t",array2[i][j]);
				}
			}
			printf("\n");
		}
	}
	else
	{printf("\nno such player");
	}
}

void questions()
{
	k=-1;
	for(i=1;i<=NUM;i++)
	{
		for(j=1;j<=NUM;j++)
		{
			qarray[i][j]=k+2;
			k++;
		}
		
	}
	time_t t;
	srand(time(&t));
	for(i=1;i<=NUM;i++)
	{
		for(j=1;j<=NUM;j++)
		{
			temp=qarray[i][j];
			randomq =rand()%5+1;
			qarray[i][j]=qarray[randomq][random1];
			qarray[randomq][random1]=temp;
		}
	}
	printf("\nthe board  is\n");
	for(i=1;i<=NUM;i++)
	{
		for(j=1;j<=NUM;j++)
		{
			printf("%d\t",qarray[i][j]);
		}
		printf("\n");
	}
}
void execute(int player)
{
	time_t t;
	srand(time(&t));
	if(player==1)
	{
		k=25;
		for(i=NUM;i>0;i--)
		{
			for(j=NUM;j>0;j--)
			{
				array1[i][j]=k;
				k--;
			}
			
		}
		for(i=1;i<=NUM;i++)
		{
			for(j=1;j<=NUM;j++)
			{
			temp=array1[i][j];
			random1 =rand()%5+1;
			random2 =rand()%5 +1;
			array1[i][j]=array1[random1][random2];
			array1[random1][random2]=temp;
			}
		
		}
	}
	else if(player ==2)
	{
		k=1;
		for(i=1;i<=NUM;i++)
		{
			for(j=1;j<=NUM;j++)
			{
			array2[i][j]=k;
			k++;
			}
			
		}
		
		for(i=1;i<=NUM;i++)
		{
			for(j=1;j<=NUM;j++)
			{
			temp=array2[i][j];
			random1 = rand()%5+1;
			random2 =rand()%5+1;
			array2[i][j]=array2[random2][random1];
			array2[random2][random1]=temp;
			}
		}
	}
	else
	{
		printf("\nno such player");
	}
}

int win(int array[26][26],int player)
{
	w=0; 
	if(player==1)
	{ checkval='X';}
	else if(player ==2)
	{checkval =='Y';}
	else
	{printf("\ninvalid");	}
	
	//for row
	n=0;
	
	for(i=1;i<=5;i++)
	{		j=1;
			if(array[i][j]==checkval && array[i][j+1]==checkval && array[i][j+2]==checkval && array[i][j+3]==checkval && array[i][j+4]==checkval)
			{
			w=w+1;	
			}
	}
	//for column
		for(j=1;j<5;j++)
		{ 
			i=1;
			if(array[i][j]==checkval && array[i+1][j]==checkval && array[i+2][j]==checkval && array[i+3][j]==checkval && array[i+4][j]==checkval)
			{
			w=w+1;
			}
		}
	//for diagonal1
	i=1;
			if(array[i][i]==checkval && array[i+1][i+1]==checkval && array[i+2][i+2]==checkval && array[i+3][i+3]==checkval && array[i+4][i+4]==checkval )
			{
			w=w+1;
			}
	//for diagonal 2  
	j=6;  
	i=1; 
		if(array[i][j-1]==checkval && array[i+1][j-2]==checkval && array[i+2][j-3]==checkval && array[i+3][j-4]==checkval && array[i+4][j-5]==checkval )
		{			
			w=w+1;			
		}   
		return w;
}




