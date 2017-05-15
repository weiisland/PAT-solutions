#include <cstdio>
#include <cstring>

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int team[1010];
	memset(team, 0, sizeof(team));
	int n, tn, pn, grade;
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d-%d %d", &tn, &pn, &grade);
		team[tn] += grade;
	}
	
	int max = 0, k;
	for(i = 0; i < 1010; i++)
	{
		if(team[i] > max)
		{
			max = team[i];
			k = i;
		}
	}
	printf("%d %d", k, max);
	return 0;
}
