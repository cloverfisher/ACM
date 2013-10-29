#include <string.h>
#include <stdio.h>
#include <stdlib.h>

	int N;
	char sourcebits[1005];
	char destinybits[1005];
	long tax[1005];
int step =0;
char tempbits[1005];
int sort()
{
	int i,j;
	long temptax;
	char tempbit;
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(tax[j]>tax[i])
			{
				temptax = tax[j];
				tax[j] = tax[i];
				tax[i] = temptax;
				tempbit = sourcebits[j];
				sourcebits[j] = sourcebits[i];
				sourcebits[i] = tempbit;
				tempbit = destinybits[j];
				destinybits[j] =destinybits[i];
				destinybits[i] = tempbit;
			}
		}
	}
	return 0;
}

long sum(char bits[1005])
{
	long num=0;
	int i=0;
	for(i=0;i<N;i++)
		num=num + (bits[i]-'0')*tax[i];
	return num;
}


long function(int num,char bits[1005])
{
	char newbits[1005];
	long num1,num2;
//	printf("%s\n",bits);
	memset(newbits,0,sizeof(newbits));
	if(num == N-1)
	{
		if(sourcebits[num]=='0' && destinybits[num]=='0')
			return 0;
		if(sourcebits[num]=='1' && destinybits[num]=='1')
			return 0;
		else
		{
			strcpy(newbits,bits);
			newbits[num] = destinybits[num];
			step++;
	//		printf("sum : %d\n",sum(bits));
			return sum(newbits);
		}
	}

	if(sourcebits[num]=='0' && destinybits[num]=='0')
	{
	//	memset(tempbits,0,sizeof(tempbits));
	//	strcpy(tempbits,bits);
	//	num1 = function(num+1,tempbits);
		return function(num+1,bits);
	}
	else if(sourcebits[num]=='1' && destinybits[num]=='0')
	{
	//	printf("1-->0\n");
	//	memset(newbits,0,sizeof(newbits));
		strcpy(newbits,bits);
	//	printf("bits : %s\n",bits);
		//strcpy(bits,newbits);
		newbits[num]='0';
		num2 = sum(newbits);
	//	printf("newbits :%s\n",newbits);
	//	return 0;	
	
		num1 = function(num+1,newbits);
	step++;
	//		printf("a num1:%d,sum:%d\n",num1,sum(newbits));
		return num2+num1;
	}
	else if(sourcebits[num]=='0' && destinybits[num]=='1')
	{
	//			memset(newbits,0,sizeof(newbits));
		strncpy(newbits,bits,num);
		strcat(newbits,&destinybits[num]);//the right side is bits,the right side is destiny
		//newbits[num]='1';
	//	printf("%d: %s\n",num,newbits);
	//	memset(tempbits,0,sizeof(tempbits));
	//	strcpy(tempbits,bits);
	//	num1 = function(num+1,tempbits);
		num2 = function(num+1,bits);
		step++;
		return sum(newbits)+ num2;
	}
	else if(sourcebits[num]=='1' && destinybits[num]=='1')
	{
	//	memset(tempbits,0,sizeof(tempbits));
	//	strcpy(tempbits,bits);
		num1 = function(num+1,bits);

	//	strncpy(newbits,bits,num);
	//	strcat(newbits,destinybits[num]);//the right side is bits,the right side is destiny
		strcpy(newbits,bits);	
		newbits[num]='1';
		num2 = sum(newbits);//+function(num+1,newbits);
	//	printf("num2:%d\n",num2);
		memset(newbits,0,sizeof(newbits));
		strncpy(newbits,bits,num);
		strcat(newbits,&destinybits[num]);//the right side is bits,the right side is destiny
		newbits[num]='1';
		num2 = num2 + sum(newbits);
	//	printf("num2:%d\n",num2);
		//		printf("num1:%d\n",num1);
		if(num2>=tax[num]*(step+1))
		{
			return num1;
		}
		else
		{
			step+=2;
			return num1-tax[num]*(step-1)+num2;
		}
	//	return (num1>num2)?num2:num1;
	}

	return 0;

}

int main()
{
	int i,j,k;
	
	j=1;
	freopen("read.in","r",stdin);
	scanf("%d",&N);
	getchar();
	while(N!=0)
	{
		step =0;
		 //gets(sourcebits);
		 //gets(destinybits); 
		memset(sourcebits,0,sizeof(sourcebits));
		memset(destinybits,0,sizeof(destinybits));
	//	memset(tax,)
		scanf("%s",sourcebits);
		scanf("%s",destinybits);

		for(i=0;i<N;i++)
		{
			scanf("%ld",&tax[i]);
		}
				sort();
		printf("Case %d: %ld\n",j,function(0,sourcebits));
		j++;
	//	printf("%d\n",function(0,sourcebits));
	//	strncpy(sourcebits,destinybits,5);
	//	strcat(sourcebits,&destinybits[1]);
//strcpy(sourcebits,destinybits);
//		printf("%s",sourcebits);
	//	printf("%s",destinybits);
		scanf("%d",&N);
		getchar();
	
		}

	
//	for(i=0;i<N;i++)
//	for(i=0;i<N;i++)


	return 0;
}
