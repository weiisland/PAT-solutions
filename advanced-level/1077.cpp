#include <cstdio>
#include <cstring>

void reverse(char str[])
{
	int len = strlen(str);
	int i;
	for(i = 0; i < len/2; i++)
	{
		char temp;
		temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	char str[n][300];
	int i, j, k = 0;
	bool flag = false;
	getchar();
	for(i = 0; i < n; i++)
	{	
		gets(str[i]);
		reverse(str[i]);
	}
	int len = strlen(str[0]);
	for(i = 0; i < len; i++)
	{
		for(j = 1; j < n; j++)
		{
			if(str[0][i] != str[j][i])
			{
				k = i;
				flag = true;
			}
		}
		if(flag == true)
		{
			break;
		}
		else
		{
			k = i+1;
		}
	}
	
	if(k == 0)
	{
		printf("nai");
	}
	else
	{
		for(i = k-1; i >= 0; i--)
		{
			printf("%c", str[0][i]);
		}
	}
	return 0;
}
