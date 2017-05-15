#include <cstdio>
#include <cstring>

int main()
{
	char s1[10010], s2[10010];
	gets(s1);
	gets(s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i, j;
	bool flag = false;
	for(i = 0; i < len1; i++)
	{
		for(j = 0; j < len2; j++)
		{
			if(s1[i] == s2[j])
			{
				flag = true;
				break;
			}
		}
		if(flag == false)
		{
			printf("%c", s1[i]);
		}
		flag = false;
	}
	return 0;
}
