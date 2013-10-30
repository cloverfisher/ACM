#include <stdio.h>
#define MAX 3*200000
int m,n; //n knights m tournament

int l[MAX+2]={0}, r[MAX+2]={0}, x[MAX+2]={0};
int beat[MAX+3] = {0};
int queue[MAX+3] = {0};

int main()
{
	int i,j,k;
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&l[i+1],&r[i+1],&x[i+1]);
		getchar();
	}

	for(i=1;i<m+1;i++)
	{
		for(j=l[i];j<=r[i];j++)
		{
			if(beat[j]!=0)
				continue;
			else if(j==x[i])
				;
			else
			{
				beat[j] = x[i];
			}
		}
	//	x[i];
	}
//	beatx[i-1]
	for(i=1;i<n+1;i++)
		printf("%d ",beat[i]);
return 0;
}
