#include <stdio.h>
#include <string.h>

char matr[102][102];
int length;
int rear,front;
int list[102*102];
int maxcell = 102*102;

int function(int x,int y,char cell);
int push(int num)
{
	rear++;
	list[rear]=num;
	return 1;
}

int pop()
{
	int numl;
	numl = list[front];
	front++;
//	return matr[numl/102][numl%102];
	return numl;
}

int getcell()
{
	int num;
	int x,y;
	while(front<=rear&&rear<maxcell)
	{
		num = pop();
		y = num / 102;
		x = num %102;
		if(function(x,y,matr[y][x]))
			length++;
	}
	return length;
}
int function(int x,int y,char cell)
{
	if(x<0||x>99||y<0||y>99)
		return 0;
	if(matr[y][x]=='1')
		return 0;
	if(matr[y][x]==cell)
	{
		matr[y][x]='1';
		function(x+1,y,cell);
		function(x-1,y,cell);
		function(x,y+1,cell);
		function(x,y-1,cell);
	}
	else
	{
//		printf("%c ",matr[y][x]);
		push(y*102+x);
	}	
	return 1;
}
int main()
{
	int x, y;
	int i, j;
	int num;
	//freopen("read.in","r",stdin);
	while(1)
	{
		length = 0 ;
		rear = 0;
		front = 0;	
		list[0]=0;	
		memset(matr,'1',sizeof(matr));
		scanf("%d %d\n",&x,&y);
		if(x==0 && y ==0)
			break;
		for(i=0;i<y;i++)
		{
			for(j=0;j<x;j++)
			{
				scanf("%c",&matr[i][j]);
			}	
			getchar();	
		}

		// for(i=0;i<102;i++)
		// {
		// 	for(j=0;j<102;j++)
		// 	{
		// 		printf("%c",matr[i][j]);
		// 	}
		// 	printf("\n");	
		// }
		num = getcell();
		printf("%d\n",num);
	}

	return 0;
}
