#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
int N;
double P, R;
vector<int> vi[maxn];
double maxp = 0, r;
int maxnum = 0, maxdepth = 0;
void DFS(int index, int depth)
{
	if(vi[index].size() == 0)
	{
		
		if(depth > maxdepth)
		{
			maxdepth = depth;
			maxnum = 1;
		}
		else if(depth == maxdepth)
		{
			maxnum++;
		}
		return;
	}
	for(int i = 0; i < vi[index].size(); i++)
	{
		int id = vi[index][i];
		DFS(id, depth+1);
	}
}

int main()
{
	scanf("%d%lf%lf", &N, &P, &R);
	r = R/100;	
	int root;
	for(int i = 0; i < N; i++)
	{
		int id;
		scanf("%d", &id);
		if(id != -1)
		{
			vi[id].push_back(i);
		}
		else
		{
			root = i;
		}
	}
	DFS(root, 0);
	printf("%.2f %d", P * pow((1+r), maxdepth), maxnum);
	return 0;
}
