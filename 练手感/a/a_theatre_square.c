#include <stdio.h>

int main()
{
	int m,n,a;

	scanf("%d %d %d",&m,&n,&a);
//	printf("%d,%d,%d",m,n,a);
	if(m%a==0)
		m = m/a;
	else
		m = m/a +1;
	if(n%a==0)
		n = n/a;
	else
		n = n/a + 1;

	m = m * n;
	printf("%d\n",m);
	return 0;

}