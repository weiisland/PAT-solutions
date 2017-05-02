#include <cstdio>

int main()
{
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int m = 1; //m表示有多少行 
	while(2*m*m <= n+1)
	{
		//s = 2 * (m * m);
		m++;
	}
	m--;
	
	int i, j;
	for(i = m; i > 0; i--)
	{
		for(j = 0; j < (m-i); j++)
		{
			printf(" ");
		}
		for(j = 0; j < (1 + 2*(i - 1)); j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}
	for(i = 2; i <= m; i++)
	{
		for(j = 0; j < (m-i); j++)
		{
			printf(" ");
		}
		for(j = 0; j < (1 + 2*(i - 1)); j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}
	int k = n-2*m*m+1;
	if(n != 0)
	{
		printf("%d", k);
	}
	
	return 0;
}
