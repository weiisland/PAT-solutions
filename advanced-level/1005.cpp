#include <cstdio>
#include <cstring>

char eng[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
	char num[110];
	int A[100];
	scanf("%s", num);
	int len = strlen(num);
	int i, sum = 0;
	for(i = 0; i < len; i++)
	{
		sum += (num[i] - '0');
	}
	int s = 0;
	do{
		A[s++] = sum%10;
		sum /= 10;
	}while(sum);
	
	int k = s-1;
	for(; k >= 0; k--)
	{
		printf("%s", eng[A[k]]);
		if(k > 0)
		{
			printf(" ");
		}
	}
	
	return 0;
}
