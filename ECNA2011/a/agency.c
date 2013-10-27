#include <stdio.h>

	int N;
	char sourcebits[1000];
	char destinybits[1000];
	int tax[1000];

int sort()
{
	int i,j;
	int temptax;
	char tempbit;
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(tax[j]>tax[i])
			{
				temptax = tax[j];
				tax[j] = tax[i];
				tax[i] = tamptax;
				tempbit = sourcebits[j];
				sourcebits[j] = sourcebits[i];
				sourcebits[i] = tempbit;
				tempbit = destinybits[j];
				destinybits[j] =destinybits[i];
				destinybits[i] = tempbit;
			}
		}
	}
}

int main()
{
	int i,j,k;
	

	scanf("%d",&N);
	getchar();
	while(N!=0)
	{
		 //gets(sourcebits);
		 //gets(destinybits);
		scanf("%s",sourcebits);
		scanf("%s",destinybits);
	
		for(i=0;i<N;i++)
		{
			scanf("%d",tax[i]);
		}
	
	
		printf("%s",sourcebits);
		printf("%s",destinybits);
	
	
		}

	}
//	for(i=0;i<N;i++)
//	for(i=0;i<N;i++)


	return 0;
}
