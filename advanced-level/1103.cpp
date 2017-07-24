#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> squ, temp, ans;
int N, K, P;
int sumadd = -1;
bool flag = false;
//不先初始化会超时 
void init()
{
	int i = 1, temp = 0;
	while(temp <= N)
	{
		squ.push_back(temp);
		temp = pow(i, P);
		i++;
	}
}

void BFS(int index, int nowk, int sumS, int sum)
{
	if(nowk == K && sumS == N)
	{
		if(sum > sumadd)
		{
			ans = temp;
			sumadd = sum;
			flag = true;
		}
		return;
	}
	
	if(index == 0 || nowk > K || sumS > N)
	{
		return;
	}
	temp.push_back(index);
	BFS(index, nowk+1, sumS + squ[index], sum+index);
	temp.pop_back();
	BFS(index-1, nowk, sumS, sum);
}

int main()
{
	scanf("%d%d%d", &N, &K, &P);
	init();
	BFS(squ.size()-1, 0, 0 , 0);
	
	if(flag)
	{
		printf("%d =", N);
		for(int i = 0; i < ans.size(); i++)
		{
			printf(" %d^%d", ans[i], P);
			if(i < ans.size()-1)
			{
				printf(" +");
			}
		} 
	}
	else
	{
		printf("Impossible\n");
	}

	return 0;
}

