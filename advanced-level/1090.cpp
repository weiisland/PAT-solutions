#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100100;

struct node{
	int layer;
	vector<int> child;
}Node[maxn];

int N;
double P, R, r;

int num = 0, maxdepth = -1;

void BFS(int root)
{
	queue<int> q;
	Node[root].layer = 0;
	q.push(root);
	
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
		if(Node[top].layer > maxdepth)
		{
			maxdepth = Node[top].layer;
			num = 1;
		}
		else if(Node[top].layer == maxdepth)
		{
			num++;
		}
		for(int i = 0; i < Node[top].child.size(); i++)
		{
			int id = Node[top].child[i];
			Node[id].layer = Node[top].layer + 1;
			q.push(id);
		}
	}
}

int main()
{
	scanf("%d%lf%lf", &N, &P, &R);
	r = R / 100;
	int root;
	for(int i = 0; i < N; i++)
	{
		int id;
		scanf("%d", &id);
		if(id != -1)
		{
			Node[id].child.push_back(i);
		}
		else
		{
			root = i;
		}
	}
	BFS(root);
	printf("%.2f %d", P*pow(1+r, maxdepth), num);
	return 0;
}
