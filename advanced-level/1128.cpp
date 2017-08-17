#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1010;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int queen[maxn] = {0};
		bool flag = true;
		int m;
		scanf("%d", &m);
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &queen[j]);
		}
		for(int j = 1; j <= m; j++)
		{
			for(int k = j+1; k <= m; k++)
			{
				//不在同一行和不在对角线 
				if(abs(k-j) == abs(queen[k] - queen[j]) || queen[k] == queen[j])
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
