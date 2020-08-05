#include<stdio.h>
#include<conio.h>

#define R 4
#define C 4

int i,j,val[16][16],row,col,value,flag =0,cr,cc,cq,r,c,cs;
int fillno=0 ,notfilled;

int getquestion();
void printquestion();
int checkrow(int row,int value);
int checkcol(int col,int value);
int checksquare(int row,int col,int value);

void main()
{
	getquestion();
	printquestion();
	
	notfilled = 16-fillno;
	
	//game play
	while(flag ==0)
	{
		printf("enter the row , column and number");
		scanf("%d%d%d",&row,&col,&value);
		if((0<=row && row<4) && (0<=col && col<4) && (1<=value && value<=4) && (val[row][col] == 0))
		{
			cr =checkrow(row,value);
			cc = checkcol(col,value);
			cs = checksquare(row,col,value);
			//checkwin();
			if(cr == 1 && cc == 1 && cs ==1)
			{
				val[row][col]=value;
				notfilled++;
			}
		}
		else
		{
			printf("\ninvalid row or col or value.please \nenter the row and col value from 0 to 3 and value from 1 to 4\n");
		}
		printquestion();
		if(notfilled == 16)
		{break;}
	}
}
	
	
int getquestion()
{
	printf("\nenter the value for question");
	printf("\nthe value should be 1 to 4 and for empty spaces give value 0\n");
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{ 
			scanf("%d",&val[i][j]);
			if(val[i][j]>4)
			{
				printf("invalid value\n");
				j--;
			}
			fillno++;
		}
	}
	return fillno;
}

void printquestion()
{
	printf("\nthe value are\n");
	printf("\n  ||| 0 | 1 || 2 | 3 |\n");
	printf("----------------------\n");
	for(i=0;i<R;i++)
	{
		printf(" %d |",i);
		for(j=0;j<C;j++)
		{ 
			if(j==1)
			{printf("| %d |",val[i][j]);}
			else if(j==3)
			{printf("| %d |",val[i][j]);}
			else 
			{printf("| %d ",val[i][j]);}
		}
		if(i==1)
		{printf("\n----------------------");}
		printf("\n----------------------\n");
	}
	
}

//row check
int checkrow(int row,int value)
{
	i=row;
		for(j=0;j<C;j++)
		{
			if(val[i][j]==value)
			{
				printf("THE NUMBER IS ALREADY PRESENT IN ROW");	
				value =0;
				return 0;
			}
		}
		return  1;
}

//col check
int checkcol(int col,int value)
{
	i=col;
		for(j=0;j<R;j++)
		{
			if(val[j][i]==value)
			{
				printf("THE NUMBER IS ALREADY PRESENT IN COlUMN");	
				value =0;
				return 0;
			}
		}
		return  1;
}

//check square
int checksquare(int row,int col,int value)
{
	if(row<2)
	 	r=0;
	else
		r=2;
	
	if(col<2)
	 	c=0;
	else
		c=2;
		
	for(i=r;i<=r+2;i++)
	{
		for(j=c;j<=c+2;j++)
		{
			if(val[i][j]==value)
			{
				printf("the value is present in the square");
				return 0;
			}
		}
	}
	
	return 1;
}
