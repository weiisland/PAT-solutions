#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int coins[n];
	int value[1010];
	memset(value, 0, sizeof(value));
	int i, v1, v2;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &coins[i]);
		v1 = coins[i];
		value[v1]++;
	}
	sort(coins, coins+n);
	bool flag = false;
	for(i = 0; i < n; i++)
	{
		v1 = coins[i];
		if(v1 < m)
		{
			v2 = m - v1;
			if(v1 != v2 && value[v2] > 0)
			{
				printf("%d %d", v1, v2);
				flag = true;
				break;
			}
			else if(v1 == v2 && value[v1] > 1)
			{
				printf("%d %d", v1, v2);
				flag = true;
				break;
			}
		}
		
	}
	if(flag == false)
	{
		printf("No Solution");
	}
	return 0;
}
