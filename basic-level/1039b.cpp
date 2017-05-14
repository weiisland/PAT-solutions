#include <cstdio>
#include <cstring>
int main()
{
	char sell[1010], buy[1010];
	int ss[128];
	memset(ss, 0, sizeof(ss));
	gets(sell);
	gets(buy);
	int len1 = strlen(sell);
	int i;
	for(i = 0; i < len1; i++)
	{
		char c1 = sell[i];
		ss[c1]++;
	}
	int len2 = strlen(buy);
	int less = 0;
	for(i = 0; i < len2; i++)
	{
		char c2 = buy[i];
		ss[c2]--;
	}
	for(i = 0; i < 128; i++)
	{
		if(ss[i] < 0)
		{
			less += ss[i];
		}
	}
	if(less < 0)
	{
		printf("No %d", -less);
	}
	else
	{
		printf("Yes %d", len1-len2);
	}
	
	
	return 0;
}
