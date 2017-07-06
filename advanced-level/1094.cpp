#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 110;

struct node{
	int level;
	vector<int> child;
}Node[maxn];
int n, m;
int maxg = 0, maxl = 0;
int gene[maxn] = {0};
void BFS(int root)
{
	queue<int> Q;
	Q.push(root);
	Node[root].level = 1;
	while(!Q.empty())
	{
		int front = Q.front();
		gene[Node[front].level]++;//队列取出数据的时候 
		Q.pop();
		
		for(int i = 0; i < Node[front].child.size(); i++)
		{
			int child = Node[front].child[i];
			Node[child].level = Node[front].level+1;			
			Q.push(child);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int id, k;
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; j++)
		{
			int child;
			scanf("%d", &child);
			Node[id].child.push_back(child);
		}
	}
	BFS(1);
	for(int i = 1; i < maxn; i++)
	{
		if(gene[i] > maxg)
		{
			maxg = gene[i];
			maxl = i;
		}
	}
	printf("%d %d\n", maxg, maxl);
	return 0;
}
