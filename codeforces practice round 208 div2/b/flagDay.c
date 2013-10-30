#include <stdio.h>

int main()
{
	int m,n;//n is dancer and m is dance;
	int i,j,k;
	int dance[3*100001];
	int dancer[100002];
	scanf("%d %d",&n,&m);
	getchar();
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&dance[3*i],&dance[3*i+1],&dance[3*i+2]);
		getchar();
	}
	for(i=0;i<m;i++)
	{
		if(dancer[dance[3*i]]+dancer[dance[3*i+1]]+dancer[dance[3*i+2]]==0)
		{
			dancer[dance[3*i]] = 1;
			dancer[dance[3*i+1]] = 2;
			dancer[dance[3*i+2]] = 3;
		}
		else
		{
			for(j=0;j<3;j++)
			{
			if(dancer[dance[3*i+j]] !=0)
				break;
			}
			dancer[dance[3*i+(j+1)%3]] = ( (dancer[dance[3*i+j]]+1)%3==0)?3:(dancer[dance[3*i+j]]+1)%3;
			dancer[dance[3*i+(j+2)%3]] =  ((dancer[dance[3*i+j]]+2)%3==0)?3:(dancer[dance[3*i+j]]+2)%3;
		}
	}	
	for(i=1;i<n+1;i++)
	{
		printf("%d ",dancer[i]);
	}
}
