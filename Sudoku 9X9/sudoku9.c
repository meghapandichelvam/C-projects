#include<stdio.h>
#include<conio.h>

#define R 9
#define C 9

int i,j,val[81][81],row,col,value,flag =0,flagq =0,cr,cc,cq,r,c;
int fillno=0 ,notfilled;
char choice;

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
		if((0<=row && row<8) && (0<=col && col<8) && (1<=value && value<=9) && (val[row][col] == 0))
		{
			cr =checkrow(row,value);
			cc = checkcol(col,value);
			cq = checksquare(row,col,value);
			//checkwin();
			if(cr == 1 && cc == 1 && cq ==1)
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
		if(notfilled == 81)
		{break;}
	}
}
	
	
int getquestion()
{
	printf("\nenter the value for question");
	printf("\nthe value should be 1 to 9 ,row and column from 0 to 3 \n");
	
	while(flagq==0)
	{
		
		printf(" enter the row ,column and the value");
		scanf("%d%d%d",&row,&col,&value);
		printf("press 'E' to exit or anyalphabet to continue");
		getchar();
		scanf("%c",&choice);
		
		if(choice == 'E' || choice =='e')
		{
			
			flagq=1;
		}
		else
		{
			flagq=0;
		}
		
		if((0<=row && row<8) && (0<=col && col<8) && (1<=value && value<=9) && (val[row][col] == 0))
		{
			val[row][col] =value;
			fillno++;
		}
		else
		{
			printf("invalid value\n");
		}
		
	}
	return fillno;
}

void printquestion()
{
	printf("\nthe value are\n");
	printf("\n   || 0 | 1 | 2 || 3 | 4 | 5 || 6 | 7 | 8 |\n");
	printf("-------------------------------------------------\n");
	for(i=0;i<R;i++)
	{
		printf(" %d |",i);
		for(j=0;j<C;j++)
		{ 
			if(j==0 || j==3 || j==6)
			{printf("| %d |",val[i][j]);}
			else 
			{printf(" %d |",val[i][j]);}
		}
		if(i==2 ||i ==5 )
		{printf("\n-------------------------------------------");}
		printf("\n--------------------------------------------\n");
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
		for(j=0;j<C;j++)
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
	if(row<3)
	 	r=0;
	else if(row<6)
		r=3;
	else
		r=6;
		
	if(col<2)
	 	c=0;
	else if(col<6)
		c=3;
	else
		c=6;
		
	for(i=r;i<=r+3;i++)
	{
		for(j=c;j<=c+3;j++)
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
