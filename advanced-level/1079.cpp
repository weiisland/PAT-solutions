#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100010;
double p, r, sum = 0;
int n;
struct node{
	double data;
	int depth;
	vector<int> child;
	bool flag;
}Node[maxn];

void BFS(int root)
{
	queue<int> Q;
	Q.push(root);
	Node[root].depth = 0;
	
	while(!Q.empty())
	{
		int f = Q.front();
		Q.pop();
		for(int i = 0; i < Node[f].child.size(); i++)
		{
			int child = Node[f].child[i];
			Node[child].depth = Node[f].depth+1;
			if(Node[child].flag)
			{
				sum += Node[child].data * pow(1+r, Node[child].depth);
			}
			Q.push(child);
		}
		
	}
}

int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	int m, child;
	for(int i = 0; i < n; i++)
	{
		
		scanf("%d", &m);
		if(m > 0)
		{
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &child);
				Node[i].flag = false;
				Node[i].child.push_back(child);
			}
		}
		else
		{
			scanf("%lf", &Node[i].data);
			Node[i].flag = true;
		}
	}
	if(n == 1)
	{
		printf("%.1f\n", p * Node[0].data);
		return 0;
	}
	BFS(0);
	printf("%.1f\n", p * sum);
	return 0;
}
