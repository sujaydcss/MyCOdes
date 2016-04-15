#include<stdio.h>
#include<stdlib.h>
char m[3][3];
char check(void);
void init_matrix(void);
void get_player_move(void);
void get_second(void);
void disp_matrix(void);
main(){
	char done;
	printf("this is a game of tic tac toe\n");
	printf("you will play against computer\n");
	done=' ';
	init_matrix();
	do{
		disp_matrix();
		get_player_move();
		done=check();
		if(done!=' ')
			break;
			disp_matrix();
			get_second();
			done=check();
	}while(done==' ');
	if(done=='X')
		printf("first person won\n");
		else
			printf("second person  won\n");
			disp_matrix();
}
void init_matrix(void){
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m[i][j]=' ';
}
void get_player_move(void){
	int x,y;
	printf("first person\n");
	printf("enter x,y co-ordinates for your move:");
	scanf("%d%d",&x,&y);
	x--;
	y--;
	if(m[x][y]!=' '){
		printf("invalid move,try again\n");
		get_player_move();
	}
	else
		m[x][y]='X';
}
void get_second(void){
	int x,y,i,j;
	printf("second person:\n");
	printf("enter the x,y co_ordinates for your move:");
	scanf("%d%d",&x,&y);
	x--;
	y--;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			if(m[i][j]==' ')
				break;
				if(m[i][j]==' ')
					break;
	}
	if(i*j==9)
		printf("draw\n");
		else if(i*j!=9&&m[x][y]!=' ')
		{
			printf("invalid move,try again\n");
			get_second();
		}
		else
			m[x][y]='O';

/*	if(m[x][y]!=' ')
	{
		printf("invalid move,try again\n");
		get_second();
	}
	else {
		for(i=0;i<3;i++){
			for(j=0;j<3;j++)
				if(m[i][j]==' ')
					break;
					if(m[i][j]==' ')
						break;
		}
		if(i*j==9)
			printf("draw\n");
			else
				m[x][y]='O';
	}*/
}


void disp_matrix(void)
{
/*	char d[MAX] = { "   |   |   \n
		        ---|---|---\n
		           |   |   \n
		        ---|---|---\n
		           |   |   \n"};*/
			  
	int t;
	for(t=0;t<3;t++)
	{		printf("%c|%c|%c",m[t][0],m[t][1],m[t][2]);
		if(t!=2)
			printf("\n---|---|---\n");
	}
	printf("\n");
}
char check(void){
	int i;
	for(i=0;i<3;i++)
		if(m[i][0]==m[i][1]&&m[i][0]==m[i][2])
			return m[i][0];
			for(i=0;i<3;i++)
				if(m[0][i]==m[1][i]&&m[0][i]==m[2][i])
					return m[0][i];
					if(m[0][0]==m[1][1]&&m[1][1]==m[2][2])
						return m[0][0];
						if(m[0][2]==m[1][1]&&m[1][1]==m[2][0])
							return m[0][2];
							return ' ';
}
