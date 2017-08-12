#include <cstdio>
const int N = 100100;

int dis[N] = {0};

int main()
{
	int n, sum = 0;;
	scanf("%d", &n);
	for(int i = 2; i <= n+1; i++)//从2开始
	{
		int d;
		scanf("%d", &d);
		sum += d;
		dis[i] = dis[i-1] + d;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a > b)//可能要交换
		{
			int temp = b;
			b = a;
			a = temp;
		}
		int s1 = dis[b] - dis[a];
		int s2 = sum - s1;
		printf("%d\n", s1 < s2 ? s1 : s2); //简洁点
//		if(s1 < s2)
//		{
//			printf("%d\n", s1);
//		}
//		else
//		{
//			printf("%d\n", s2);
//		}
	}
	return 0;
}
