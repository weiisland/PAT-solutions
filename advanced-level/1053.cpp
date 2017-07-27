#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node{
	int data;
	vector<int> child;
}Node[maxn];

int cmp(int a, int b)
{
	return Node[a].data > Node[b].data;
}

vector<int> temp;//temp用于保存带权路径序号 
int N, M, S;

void DFS(int index, int num)
{
	if(num > S)//剪枝 
	{
		return;
	}
	if(Node[index].child.size() == 0)//到了根节点 
	{
		if(num == S)
		{
			for(int i = 0; i < temp.size(); i++)
			{
				printf("%d", Node[temp[i]].data);
				if(i < temp.size()-1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		return;
	}

	for(int i = 0; i < Node[index].child.size(); i++)
	{
		int id = Node[index].child[i];
		temp.push_back(id);		
		DFS(Node[index].child[i], num+Node[id].data);
		temp.pop_back();
		//DFS(Node[index].child[i], num);
	}
}

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &Node[i].data);
	}
	for(int i = 0; i < M; i++)
	{
		int k, id, child;
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(), Node[id].child.end(), cmp);//提前把大的路径先遍历，儿子节点大的在左边 
	}
	temp.push_back(0);//必须先把根给push进去 
	DFS(0, Node[0].data);
	
	return 0;
}
