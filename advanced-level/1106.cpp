#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;
const double INF = 1e12;//设置最大值 
vector<int> child[maxn];

int n, sum = 1;
double p, r, cost = 0, lowest = INF;

void DFS(int index, int depth)
{
	if(child[index].size() == 0)
	{
		cost = pow(1+r, depth);
		if(cost < lowest)
		{
			lowest = cost;
			sum = 1;//小于最低值时，叶子个数计为1 
		}
		else if(cost == lowest)
		{
			sum++;
		}
		return;
	}
	for(int i = 0; i < child[index].size(); i++)
	{
		DFS(child[index][i], depth+1);
	}
}

int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		if(k != 0)
		{
			for(int j = 0; j < k; j++)
			{
				int ch;
				scanf("%d", &ch);
				child[i].push_back(ch);
			}
		}
	}
	DFS(0, 0);
	printf("%.4f %d\n", p * lowest, sum);
	return 0;
}
