#include <cstdio>
#include <cmath>
#include <cstring>
bool isPrime(int n)
{
	if(n <= 1)
	{
		return false;
	}
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int ms, n;
	scanf("%d %d", &ms, &n);
	if(!isPrime(ms))
	{
		int k = ms+1;
		while(!isPrime(k))
		{
			k++;
		}
		ms = k;
	}
	int i, A[n];
	bool p[10001];
	memset(p, 0, sizeof(p));
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		int tmp = A[i] % ms;
		if(p[tmp] == 0)
		{
			printf("%d", tmp);
			if(i < n-1)
			{
				printf(" ");
			}
			p[tmp] = 1;
		}
		else
		{
			int step = 1;
			int flag = false;
			for(; step < ms; step++)
			{
				int temp = (A[i] + step * step) % ms;
				if(p[temp] == 0)
				{
					printf("%d", temp);
					if(i < n-1)
					{
						printf(" ");
					}
					p[temp] = 1;
					flag = true;
					break;
				}
			}
			if(flag == false)
			{
				printf("-");
				if(i < n-1)
				{
					printf(" ");
				}
			}

		}
	}
	return 0;
}
