#include <stdio.h>

int m;
int c[100];

int  main()
{
	int i,j,k,x,y;
	int sum,beginner,intermediate;
	scanf("%d",&m);
	getchar();
	sum = 0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&c[i]);
		getchar();
		sum = sum + c[i];
	}
	scanf("%d",&x);
	scanf("%d",&y);
	
	i=1;
	intermediate = sum;
	beginner = 0;
	for(i=1;i<m;i++)
	{

		beginner = beginner + c[i-1];
		intermediate = intermediate - c[i-1];
//		printf("%d,%d",beginner,intermediate);
		if(beginner>=x && beginner <= y && intermediate >=x && intermediate <= y)
		{
			printf("%d " ,i+1);	
			return 0;
		}
	}
	printf("0");
	return 0;


}
