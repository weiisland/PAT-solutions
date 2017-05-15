#include <cstdio>
#include <cstring>

int main()
{
	int n;
	int guess[10010];
	memset(guess, 0, sizeof(guess));
	scanf("%d", &n);
	int i, m[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
		guess[m[i]]++;
	}
	
	bool flag = false;
	for(i = 0; i < n; i++)
	{
		if(guess[m[i]] == 1)
		{
			printf("%d", m[i]);
			flag = true;
			break;
		}
	}
	if(flag == false)
	{
		printf("None");
	}
	return 0;
}
