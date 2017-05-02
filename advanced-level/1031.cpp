#include <cstdio>
#include <cstring>

int main()
{
	char str[100];
	scanf("%s", str);
	int len = strlen(str);
	int m, i, j;
	double n = 3.0;
	while((len+2-n)/2 > n)
	{
		n = n+1;
	}
	
	m = (int)(len+2-n)/2;
	n = len+2 - 2 *m;//不在两边的数应该归到底下 
	for(i = 0; i < m-1; i++)
	{
		printf("%c", str[i]);
		for(j = 0; j < n-2; j++)
		{
			printf(" ");
		}
		printf("%c\n", str[len-i-1]);
	}
	for(i = m-1; i < len-m+1; i++)
	{
		printf("%c", str[i]);
	}
	return 0;
 } 
