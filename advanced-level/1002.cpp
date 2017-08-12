#include <cstdio>
const int N = 1001;
int main()
{
	int n;
	scanf("%d", &n);
	double A[N] = {0}, B[N] = {0};//记得初始化 
	for(int i = 0; i < n; i++)
	{
		int e;
		double p;
		scanf("%d %lf", &e, &p);
		A[e] = p;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int e;
		double p;
		scanf("%d %lf", &e, &p);
		B[e] = p;
	}
	int count = 0;
	for(int i = 0; i < N; i++)
	{
		A[i] = A[i] + B[i];
		if(A[i] != 0)
		{
			count++;
		}
	}
	printf("%d", count);

	for(int i = N-1; i >= 0; i--)//i必须从N-1开始， A没有初始化N； 
	{
		if(A[i] != 0)
		{
			printf(" %d %.1f", i, A[i]);//这样输出最后一个判断才没出错。。。 
//			count--;
//			if(count > 0)
//			{
//				printf(" ");
//			}	
		}
	}
	return 0;
}
