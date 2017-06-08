#include <cstdio>
#include <cmath>
#include <cstring>
const int maxn = 1000010;
typedef long long LL;
struct Factory{
	LL pi, exp;
}fac[20];

LL prime[maxn], p[maxn], pnum = 0;
void findPrime(int n)
{
	for(int i = 2; i < n; i++)
	{
		if(p[i] == false)
		{
			prime[pnum++] = i;
			for(int j = i; j < n; j+=i)
			{
				p[j] = true;
			}
		}
	}
}

int main()
{
	LL n;
	scanf("%lld", &n);
	
	memset(p, 0, sizeof(p));
	int sqr = (int)sqrt(1.0 * n);
	findPrime(maxn);
	int i = 0, num = 0;
	int test = n;
	while(prime[i]*prime[i] <= n)
	{		
		if(test % prime[i] == 0)
		{
			fac[num].pi = prime[i];
			fac[num].exp = 0;
			while(test % prime[i] == 0)
			{
				fac[num].exp++;
				test /= prime[i];
			}
			num++;
		}
		i++;
	}
	if(test != 1)
	{
		fac[num].pi = test;
		fac[num++].exp = 1;
	}
	printf("%lld=", n);
	if(n == 1)
	{
		printf("%d", 1);
		return 0;
	}
	for(i = 0; i < num; i++)
	{
		if(i > 0 && i < n-1)
		{
			printf("*");
		}
		if(fac[i].exp == 1)
		{
			printf("%d", fac[i].pi);
		}
		else
		{
			printf("%d^%d", fac[i].pi, fac[i].exp);
		}
		
	}
	return 0;
}
