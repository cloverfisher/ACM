#include <stdio.h>
#define MAX 400000

int queue[MAX*2];
int list[400000] = {0};
int step;
int nowstep;

int man;
int cow;


int maxstep;
int maxx;

int rear=0,head=1;

int tempstep,tempx;

void push(int x,int st)
{
	rear++;
	list[x] = 1;
	queue[rear*2] = x;
	queue[rear*2+1] = st;
}

void pop()
{
	tempx = queue[head*2];
	tempstep = queue[head*2+1];
	head++;
}

int function(int x,int step)
{
	int a,b,c;
	push(x,0);
	while(1)
	{
	pop();
	// if(tempx<=0)
	// 	continue;
	// if(tempx>=200000)
	// 	continue;
	if(tempx != cow)
	{
		if(list[tempx*2]==0&&tempx<=100000&&tempx>=0)
			push(tempx*2,tempstep+1);
		if(list[tempx+1]==0&&tempx<=100000&&tempx>=0)
			push(tempx+1,tempstep+1);
		if(list[tempx-1]==0&&tempx<=100000&&tempx>=0)
			push(tempx-1,tempstep+1);
	}
	else
		return tempstep;		
	}


	// if(x==cow)
	// {
	// 	maxstep = step;
	// 	return step;
	// }
	// else if(x<0)
	// {
	// 	return maxstep;
	// }
	// else if(step == maxstep)
	// {
	// 	return maxstep;
	// }
	// else if(x >2 * cow )
	// {
	// 	return maxstep;
	// }
	// else
	// {
	// 	a = function(x*2,step+1);
	// 	c = function(x-1,step+1);
	// 	b = function(x+1,step+1);

	// 	a = (a>b)?b:a;
	// 	c = (c>a)?a:c;
	// 	return c;
	// }
	
		

	
}

int main()
{
	int temp;
	scanf("%d %d",&man,&cow);
//	maxx = man;
	temp = cow;
	while(1)
	{
		if(temp<= man)
			break;
		temp = temp/2;
	//	maxx = maxx *2;
		maxstep++;
	}
	maxstep+=man + temp;
//	printf("%d,%d\n",temp,maxstep);
	function(man,0);
	printf("%d\n",tempstep);
	return 0;
}
