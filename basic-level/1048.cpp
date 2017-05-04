#include <cstdio>
#include <cstring>

char num[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int main()
{
	char A[110], B[110], C[110];
	scanf("%s %s", A, B);
	int len1 = strlen(A);
	int len2 = strlen(B);
	
	int i, j = 0, k = 1;
	//若是B长度大于A， 先把多的输出出来 
	if(len2 > len1)
	{
		for(i = 0; i < len2 - len1; i++)
		{
			printf("%c", B[i]);
		}
	}
	int b;//如果B长度小于A，少于的部分作为0，用b来替代B每一位的值 
	for(i = len2-1, j = len1-1; j >= 0; i--, j--)//不限制i的大小，只限制j大小 
	{
		if(i < 0)//避免出现数组下标为负数的情况 
		{
			b = 0;
		}
		else
		{
			b = B[i] - '0';
		}
		if(k % 2 == 1)
		{
			C[k] = num[(A[j] - '0' + b)%13];
		}
		else
		{
			int tmp = b - (A[j] - '0');
			if(tmp < 0)
			{
				C[k] = num[tmp+10];
			}
			else
			{
				C[k] = num[tmp];
			}
		}
		k++;
	}
	
		
	for(i = k-1; i >=1; i--)
	{
		printf("%c", C[i]);
	}
	
	return 0;
 } 
