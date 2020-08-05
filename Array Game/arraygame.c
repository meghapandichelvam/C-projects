#include<stdio.h>
#include<conio.h>

/*
1 2 3
4 5 6
7 8 9

Score: 0
*/

int board[3][3];
int i,j, Score = 0;
char Input = '\0';
int Xpos = 0,Ypos = 0;

void PrintBoard();
void GameInit();
void PlayerDir(char Dir);
void PlayerMove(int X, int Y);

int main()
{

	printf("enter the value \n");
	
	for(i = 0; i<3;i++)
	{
		for(j = 0; j<3;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	printf("the value are\n");
	
	for(i = 0; i<3;i++)
	{
		for(j = 0; j<3;j++)
		{
			printf("%d\t",board[i][j]);
		}
			printf("\n");
	}
	
		GameInit();

	
	while(Input != 'q')	{
		PrintBoard();
		Input = getchar();
		PlayerDir(Input);
	}
}

void PrintBoard()
{

	for(i = 0; i<3;i++){
		for(j = 0; j<3;j++){
		printf("%d ",board[i][j]);
	}
	printf("\n");
	}
	printf("\n");
	printf("SCORE %d", Score);
	printf("\n");
}

void GameInit(){
	Xpos = 0;
	Ypos = 0;
	
	Score += board[Xpos][Ypos];
	board[Xpos][Ypos] = 0;	
}


void PlayerMove(int X, int Y){
	
	int tempX = Xpos + X;
	int tempY = Ypos + Y;
	
	if((tempX >= 0 && tempX <= 2) && (tempX >= 0 && tempX <= 2)){
	
		Xpos = tempX;
		Ypos = tempY;
		
		Score += board[Xpos][Ypos];
		board[Xpos][Ypos] = 0;
		
	}
	
}


void PlayerDir(char Dir)
{
	// A - left 
	// D - right
	// S - Down
	// W - Up
	
	switch(Dir){
		
		case 'a':
			//left
			//R,C-1
			PlayerMove(0,-1);			
			break;
		case 'd':
			//right
			//R,C+1
			PlayerMove(0,1);			
			break;
			
		case 's':
			//down
			//R+1,C
			PlayerMove(1,0);			
			break;
		case 'w':
			//up
			//R-1,C
			PlayerMove(-1,0);			
			break;
		case 'q':
			printf("THANK YOU");
			break;
			
			
	}
	
}









