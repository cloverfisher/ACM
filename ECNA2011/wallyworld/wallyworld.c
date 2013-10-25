#include <stdio.h>
#include <math.h>
int mx1,mx2,my1,my2;
int wx1,wx2,wy1,wy2;
float solve();
int input()
{
	float result;
	int i = 1;
	while(scanf("%d %d %d %d",&mx1,&my1,&mx2,&my2)!=EOF)
	{
		getchar();
		if(mx1==0&&mx2==0&&my1==0&&my2==0)
			break;
		scanf("%d %d %d %d",&wx1,&wy1,&wx2,&wy2);
		getchar();
//		printf("%d %d %d %d\n%d %d %d %d\n",mx1,my1,mx2,my2,wx1,wy1,wx2,wy2);
		result = solve();
		result = result/2;
		printf("case %d: %.3f\n",i,result);
		i++;
	}
	return 0;
}

int judgecross()
{
	int flag;
	int x3,y3;
	if(wx1 == wx2)
		flag= 1; //wall parallel to y
	if(wy1 == wy2)
		flag = 2; //wall parallel to x
//	printf("flag : %d \n",flag);
	if(flag == 1)
	{
//		printf("wall parallel to y");
		if(mx1==mx2)
			return 0; //not accross
		if((wx1 - mx1)*(wx1 - mx2)>0)
			return 0;
		x3 = wx1;
		y3 = (my1-my2) * (x3-mx1)/(mx1-mx2) + my1;
//		printf("y3 : %d\n",y3);
		if((wy2-wy1)>0)
		{
			if(y3 >= wy1 && y3 < wy2)
			{
			//	if(y3 > my1 && y3 < my2)
				return 1;
			}
			else
				return 0;
		} 
		else
		{
			if(y3 >= wy2 && y3 < wy1)
			{
			//	if(y3 > my1 &&
				return 1;
			}
			else
				return 0;
		}
	}
	else if (flag == 2)
	{
//				printf("wall parallel to x");

		if(my1 == my2)
			return 0;
		if((wy1-my1)*(wy2-my2)>0)
			return 0;
		y3 = wy1;
		x3 = (mx1-mx2)*(y3-my1)/(my1-my2) + mx1;
		if((wx2-wx1)>0)
		{
			if(x3 >= wx1 && x3 < wx2)
				return 1;
			else
				return 0;
		}
		else
		{
			if(x3 < wx1 && x3 >= wx2)
				return 1;
			else 
				return 0;
		}
	}
	return 0;
}

float distance(int x1, int y1, int x2, int y2)
{
	int num;
	float result;
	num = (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
	result = sqrt(num); 
//	printf(" %d,%d %d,%d : %f\n",x1,y1,x2,y2,result);
	return result;
}

float solve()
{
	float result;
	float num1;
	float num2;
	if(judgecross() == 0)// not cross
	{
	//	printf("not cross\n");
		result = distance(mx1,my1,mx2,my2);
	}
	else
	{
	//	printf("cross\n");
		num1 = distance(mx1,my1,wx1,wy1) + distance(wx1,wy1,mx2,my2);
		num2 = distance(mx1,my1,wx2,wy2) + distance(wx2,wy2,mx2,my2);
		result = (num1 > num2)? num2:num1;  
	}
	return result;

}


int main()
{
	freopen("read.in","r",stdin);
	freopen("read.out","w",stdout);

	input();


	return 0;
}
