#include <stdio.h>


int	sudoku[3][3][3][3]; 



int nosame(int si,int sj,int sk,int st,int tempnum)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(sudoku[si][sj][i][j] == tempnum)
				return 0;
			if(sudoku[si][i][sk][j] == tempnum)
				return 0;
			if(sudoku[i][sj][j][st] == tempnum)
				return 0;
		}
	}
	return 1;
}
int DFS(int num)
{
	int si,sj,sk,st;
	int tempnum;
	si = num/27;
	sj = num/3%3;
	sk = num/9%3;
	st = num%3;
	if(num>80)
		return 1;
	if(sudoku[si][sj][sk][st]==0)
	for(tempnum=1;tempnum<10;tempnum++)
	{
		if(nosame(si,sj,sk,st,tempnum))
		{
			sudoku[si][sj][sk][st] = tempnum;
			if(DFS(num+1)==1)
				return 1;
			sudoku[si][sj][sk][st] = 0;
		}
	}
	else//this number is not zero
	{
		if(DFS(num+1)==1)
			return 1;
	}
	return 0;

}







int main()
{
	int casenum;
	int casei;	
	int i,j,k,t;





	//freopen("read.in","r",stdin);
	scanf("%d",&casenum);
	getchar();
	for(casei=0;casei<casenum;casei++)	
	{
		for(i=0;i<3;i++)
		{
			for(k=0;k<3;k++)
			{
				for(j=0;j<3;j++)
				{
					for(t=0;t<3;t++)
					{
						scanf("%1d",&sudoku[i][j][k][t]);
						//getchar();
					}
				}
			}
		}
	DFS(0);	

		





		for(i=0;i<3;i++)
		{
			for(k=0;k<3;k++)
			{
				for(j=0;j<3;j++)
				{
					for(t=0;t<3;t++)
					{
						printf("%d",sudoku[i][j][k][t]);
					}
				}
				printf("\n");
			}
		}
		
	}


	return 0;
}
