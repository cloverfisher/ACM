#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DBS(char square[][22],int x, int y, int length);
int function(char square[][22],int x,int y)
{
	int i,j;
	int sx=0,sy=0;
	int length=0;
	for(i=0;i<y;i++)
	{
		for(j=0;j<x;j++)
		{
		//	printf("%c",square[j][i]);
			if(square[j][i] == '@')
			{
				sx = j;
				sy=i;
				break;
			}
				
		}
	}
	
//	printf("%d , %d \n",sx,sy);
	length = DBS(square,sx,sy,0);
	printf("%d\n",length);
	return 1;
}

int DBS(char square[][22],int x, int y, int length)
{
	if((square[x][y] !='.')&&(square[x][y]!='@' ))
		return length;
	square[x][y] = '#';
	length++;
	length = DBS(square,x-1,y,length);	
	length = DBS(square,x+1,y,length);
	length = DBS(square,x,y-1,length);
	length = DBS(square,x,y+1,length);
	return length;
}

int main()
{
//	freopen("read.in","r",stdin);
	int i,j;
	
	int x,y;
	char square[22][22] ;
	while(1)
	{

	scanf("%d %d\n",&x,&y);
//	printf("%d",x);
//	printf("%d\n",y);
	if(x==0&&y==0)
		break;
	
	memset(square,'#',sizeof(square));
	//printf("%lu",sizeof());
	for(i=1;i<y+1;i++)
	{
		for(j=1;j<x+2;j++)
		{
			scanf("%c",&square[j][i]);	
		}
	}
	// for(i=0;i<y+2;i++)
	// {
	// 	printf("%2d",i);
	// 	for(j=0;j<x+2;j++)
	// 	{
	// 		printf("%c",square[j][i]);
	// 	}
	// //	printf("\n");
	// }
	function(square,x+2,y+2);
}

}
