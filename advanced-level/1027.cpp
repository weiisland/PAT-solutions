#include <cstdio>

char cnum[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int change(int a, int A[])
{
	int num = 0;
	do{
		A[num++] = a%13;
		a /= 13;
	}while(a != 0);
	int i, result = 0;
	
	if(num == 1)
	{
		printf("0%c", cnum[A[0]]);
	}
	else
	{
		for(i = num-1; i >= 0; i--)
		{
			int j = A[i];
			printf("%c", cnum[j]);
		}
	}
	
}

int main()
{
	int a, b, c;
	
	scanf("%d%d%d", &a, &b, &c);
	
	int A[10], B[10], C[10];
	printf("#");
	change(a, A);
	change(b, B);
	change(c, C);
	return 0;
}
