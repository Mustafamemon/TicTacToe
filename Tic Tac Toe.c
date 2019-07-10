#include<stdio.h>
void dis(char mat[3][3],int s)
{
	int i, j ;
	printf("\t\tTic Tac Toe\n\n");
	if (s==1)
  	printf("\tPlayer 1 (X) Vs Player 2 (O)\n\n");
  	else
  	printf("\tPlayer 1 (X) Vs Computer (O)\n\n");
	printf("\n");
	for (i=0;i<3;i++)
	{
		printf("  %c |  %c |  %c ",mat[i][0],mat[i][1],mat[i][2]);
		if (i!=2)
		printf("\n----|----|----\n");
	}
	printf("\n\n");
}
void play1(char mat[3][3],int play)
{
	int x, y;
	printf("Player %d\n",play);
	scanf("%d",&y);
   	if (y<=3) x=0;
  	else if (y<=6)
	{  
		x=1; y=y-3;
	}
  	else if (y<=9)
	{  
		x=2; y=y-6;
	}
 	y--;
  	if (mat[x][y]!=' ')
  	{
  		printf("Invalid Entry\n");
		play1(mat,play);	
	}
  	else if (play==1)
  	mat[x][y]='X';	
  	else if (play==2)
  	mat[x][y]='O';	
  	system("cls");
}
void com(char mat[3][3])
{
	int i,j ,l=0;
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			if (mat[i][j]==' ')	
			{
				mat[i][j]='O'; l=1; break;
			}		
		}
		if (l==1) break;
	}	
  	system("cls");
}
char check (char mat[3][3])
{
	int i  ;
	for (i=0;i<3;i++)
	if (mat[i][0]==mat[i][1] &&mat[i][1]==mat[i][2])
	return mat[i][0];
	for (i=0;i<3;i++)
	if (mat[0][i]==mat[1][i] && mat[1][i]==mat[2][i])
	return mat[0][i];
	if (mat[0][0]==mat[1][1]&&mat[1][1]==mat[2][2])
	return mat[0][0];
	if (mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0])
	return mat[0][2];
	return ' ';
}
void main ()
{
	char ch=' ',mat [3][3],c; int i,j,s;
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		mat[j][i]=' ';
	}
	printf("Enter\n1:Double Player\n2:Single Player\n");	scanf("%d",&s);
	dis(mat,s);
	for (i=0;i<=4;i++)
	{
		play1(mat,1); ch=check(mat);  dis(mat,s);
		if (ch!=' ') break;
		if (i!=4)
		{
			if (s==1)
			play1(mat,2);
			else
			com(mat);
			ch=check(mat);	dis(mat,s);
			if (ch!=' ') break;
		}
	}
	if (ch=='X') printf("==>Player One WIN\n");
	else if (ch=='O')
	{
		if(s==1) printf("==>Player Two WIN\n");
		else printf("==>Compter WIN\n");		
	}
	else printf("==>TIE");
	printf("\n\t\tIf You want to Play Again :\nEnter Y or N "); fflush(stdin); scanf("%c",&c);
	if (c=='Y' || c=='y')
	{
		system("cls"); main();	
	}	
}
