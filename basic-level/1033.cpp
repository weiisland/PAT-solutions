#include <cstdio>
#include <cstring>

int main()
{
	char wrong[128], in[100010];
	gets(wrong);
	gets(in);
	
	int hash[128];
	int i;
	for(i = 0; i < 128; i++)
	{
		hash[i] = 0;
	}
	int len1 = strlen(wrong);
	for(i = 0; i < len1; i++)
	{
		char c1 = wrong[i];
		if('A'<= c1 && c1 <= 'Z')
		{
			hash[c1] = 1;
			hash[c1+32] = 1;
		}		
		if(c1 == '+')
		{
			int j = 'A';
			for(; j <= 'Z'; j++)
			{
				hash[j] = 1;
			}
		}
		hash[c1] = 1;
	}
	
	int len2 = strlen(in);
	for(i = 0; i < len2; i++)
	{
		char c2 = in[i];
		if(hash[c2] == 0)
		{
			printf("%c", c2);
		}
	}
	
	return 0;
}
