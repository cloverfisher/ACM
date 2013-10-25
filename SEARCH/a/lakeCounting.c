#include <stdio.h>
#include <string.h>

char square[110][110];

int queue[1100*1100];

int rear=1, tail=0;

int m,n;
int num=0;
int pop()
{
	rear++;
	return queue[rear-1];
}

void push(int a)
{
//	printf("%d,%d\n",a/110,a%110);
	tail++;
	queue[tail] = a;
}


int BFS()
{
	int k;
	int y,x;
	while(rear<=tail)
	{
		k = pop();
		y=k/110;
		x=k%110;
		if(square[y][x]=='W')
		{
			square[y][x]='.';
			if(square[y][x+1]=='W')
				push(110*y+x+1);

			if(square[y][x-1]=='W')
				push(110*y+x-1);

			if(square[y+1][x+1]=='W')
				push(110*y+110+x+1);

			if(square[y+1][x]=='W')
				push(110*y+110+x);

			if(square[y+1][x-1]=='W')
				push(110*y+110+x-1);

			if(square[y-1][x+1]=='W')
				push(110*y-110+x+1);

			if(square[y-1][x]=='W')
				push(110*y-110+x);

			if(square[y-1][x-1]=='W')
				push(110*y-110+x-1);
			// push(110*y+x-1);
			// push(110*(y+1)+x+1);
			// push(110*(y+1)+x-1);
			// push(110*(y+1)+x);
			// push(110*(y-1)+x+1);
			// push(110*(y-1)+x-1);
			// push(110*(y-1)+x);

		}
	}
	return 1;
}


int function()
{
	int i,j;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			if(square[i][j]=='.')
				continue;
			else
			{
	//			printf("%d,%d\n\n",i,j);
				push(110*i+j);
				BFS();
				num++;
			}
		}
	}
	return 1;
}



int main()
{
	int i,j;
	
//	freopen("read.in","r",stdin);
	
	scanf("%d %d",&n,&m);
	getchar();

	memset(square,'.',sizeof(square));
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
			scanf("%c",&square[i][j]);
		getchar();	
	}	
		function();
	// for(i=0;i<n+1;i++)
	// {
	// 	for (j=0;j<m+1;j++)
	// 		printf("%c ",square[i][j]);
	// 	printf("\n");
	// }

	printf("%d\n",num);
	return 0;

}
