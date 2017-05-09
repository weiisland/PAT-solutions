#include <cstdio>

int main()
{
	int a, b, c, d;
	int save[10];
	scanf("%d %d", &a, &b);
	c = a+b;
	if(c < 0)
	{
		d = -c;
		printf("-");
	}
	else
	{
		d = c;
	}
	int i = 0;
	if(d == 0)//0要特殊处理下
	{
		printf("0");
	}
	else
	{
		while(d != 0)
		{
			save[i] = d % 1000;
			d /= 1000;
			i++;
		}
		int k = i-1;
		printf("%d", save[k]);
		k--;
		while(k >= 0)
		{
			printf(",%003d", save[k]);
			k--;
		}
	}
	
	
	return 0;
 } 
