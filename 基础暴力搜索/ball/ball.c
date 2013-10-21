#include <stdio.h>
#include <string.h>
//#include <stack>
int function(int flag);
int str[20] = {0};
int stra[20] = {0};
int strb[20] = {0};
int flaga = 0, flagb = 0, flag =0;
int function(int flag)
{
	
	if(flag == 10)
		return 1;

	if(str[flag]>stra[flaga])
	{
	//	printf("%d a",str[flag] + 100);
		flaga++;
		stra[flaga] = str[flag];
		flag++;
		if(	function(flag))
			return 1;
		flag--;	
		flaga--;	
	}
	if(str[flag]>strb[flagb])
	{
		//		printf("b %d",str[flag] + 100);
		//		printf("c %d",stra[flagb] + 100);
		flagb++;
		strb[flagb] = str[flag];
		flag++;
		if(function(flag))	
		{
			return 1;
		}
		flag--;
		flagb--;	
	}
	return 0;

}



int main()
{
	int num;
	int i , j ;
//	freopen("read.in","r",stdin);
	scanf("%d\n",&num);
	for(i=0;i<num;i++)
	{
		flag = 0;
		flaga = 0;
		flagb = 0;

		for(j=0;j<10;j++)
		{
			scanf("%d",&str[j]);
		}
		//scanf("%d %d %d %d %d %d %d %d %d %d ",&str[0],&str[1],&str[2],&str[3],&str[4],&str[5],&str[6],&str[7],&str[8],&str[9]);
	//	scanf("n",&str[5],&str[6],&str[7],&str[8],&str[9]);
	//	printf("%d",str[0]);	
	//	memset(stra,'0',sizeof(stra));
	//	memset(strb,'0',sizeof(strb));
		if(function(0))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
