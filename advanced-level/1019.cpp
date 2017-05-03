#include <cstdio>

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	int num = 0, i, flag = 1;
	int A[50];
	do{
		A[num++] = n%b;
		n /= b;
	}while(n != 0);
	num--;
	for(i = 0; i <= num/2; i++)
	{
		if(A[i] != A[num-i])
		{
			flag = 0;
		}
	}
	if(flag == 0)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
	}
	for(i = num; i >= 0; i--)
	{
		printf("%d", A[i]);
		if(i > 0)
		{
			printf(" ");
		}
	}
}
