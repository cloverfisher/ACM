#include <stdio.h>
#include <string.h>

int squire[22][22]= {5};
int step = 0;
int minstep = 11;
int function(int x, int y);

int function(int x,int y)
{
	int tempx,tempy;
	step++;
	if(step > 10)
		return 0;
	if(squire[y+1][x]==3||squire[y-1][x]==3||squire[y][x+1]==3||squire[y][x-1]==3)
	{
		if(step < minstep)
			minstep = step;
		return 1;
	}
	tempx = x;
	tempy = y;
	if(squire[tempy][tempx+1]==0)
	{
///				printf(" x++ ");

		while(squire[tempy][tempx+1]==0)
			tempx++;	
		if(squire[tempy][tempx+1]==3)
				{
			if(step < minstep)
				minstep = step;
		}
		if(squire[tempy][tempx+1]==1)
		{
			squire[tempy][tempx+1]=0;
			if(function(tempx,tempy)==1)
				return 1;
			else
				squire[tempy][tempx+1]=1;
		}	
	}
	tempx = x;
	tempy = y;
	if(squire[tempy+1][tempx]==0)
	{
//		printf(" y++ ");
		while(squire[tempy+1][tempx]==0)
			tempy++;	
		if(squire[tempy+1][tempx]==3)
		{
			if(step < minstep)
				minstep = step;
		}
		if(squire[tempy+1][tempx]==1)
		{
			squire[tempy+1][tempx]=0;
			if(function(tempx,tempy)==1)
				return 1;
			else
				squire[tempy+1][tempx]=1;
		}	
	}
	tempx = x;
	tempy = y;
	if(squire[tempy-1][tempx]==0)
	{
//		printf(" y-- ");
		while(squire[tempy-1][tempx]==0)
			tempy--;	
		if(squire[tempy-1][tempx]==3)
					{
			if(step < minstep)
				minstep = step;
		}
		if(squire[tempy-1][tempx]==1)
		{
			squire[tempy-1][tempx]=0;
			if(function(tempx,tempy)==1)
				return 1;
			else
				squire[tempy-1][tempx]=1;
		}	
	}

		tempx = x;
	tempy = y;
	if(squire[tempy][tempx-1]==0)
	{
		//		printf(" x-- ");

		while(squire[tempy][tempx-1]==0)
			tempx--;	
		if(squire[tempy][tempx-1]==3)
			{
			if(step < minstep)
				minstep = step;
		}
		if(squire[tempy][tempx-1]==1)
		{
			squire[tempy][tempx-1]=0;
			if(function(tempx,tempy)==1)
				return 1;
			else
				squire[tempy][tempx-1]=1;
		}	
	}
//	printf("% d,%d ",tempx,tempy);
	step--;
	return 0;
	

}	



int main()
{
	int x,y;
	int i,j;
	int sx,sy;	
	scanf("%d %d",&x,&y);
	while(x>0||y>0)
	{
	step = 0;	
	minstep = 11;
	for(i=0;i<22;i++)
		for(j=0;j<22;j++)
			squire[i][j]= 5;
	for(i=1;i<y+1;i++)
	{
		for(j=1;j<x+1;j++)
		{
			scanf("%d",&squire[i][j]);
			if(squire[i][j]==2)
			{
				sy = i;
				sx = j;	
				squire[i][j] = 0;	
			}
		}	

	}	
		// for(i=0;i<22;i++)
		// {		
		// 	for(j=0;j<22;j++)
		// 		printf("%d",squire[i][j]);
		// 	printf("\n");
		// }
function(sx, sy);
	if(minstep<11)
		printf("%d\n",minstep);
	else
		printf("-1\n");

		scanf("%d %d",&x,&y);	
	}


	return 0;
}
