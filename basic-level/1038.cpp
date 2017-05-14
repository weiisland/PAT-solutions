#include <cstdio>
#include <cstring>

int main()
{
	int n;
	scanf("%d", &n);
	int grade[101];
	memset(grade, 0, sizeof(grade));
	int i;
	for(i = 0; i < n; i++)
	{
		int s;
		scanf("%d", &s);
		grade[s]++;
	}
	int m;
	scanf("%d", &m);
	for(i = 0; i < m; i++)
	{
		int p;
		scanf("%d", &p);
		printf("%d", grade[p]);
		if(i < m-1)
		{
			printf(" ");
		}
	}
	return 0;
}
