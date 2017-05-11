#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct test{
	char id[15];
	int socre;
	int location;
	int locRank;
	int rank;
}Test;

int cmpt(Test t1, Test t2)
{
	if(t1.socre != t2.socre)
	{
		return t1.socre > t2.socre;
	}
	else
	{
		return strcmp(t1.id, t2.id) < 0;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	Test T[n*300];
	int i, j, loc = 0;
	for(i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		
		for(j = 0; j < m; j++)
		{
			scanf("%s %d", T[loc+j].id, &T[loc+j].socre);
			T[loc+j].location = i+1;
		}
		sort(T+loc, T+loc+m, cmpt);
		T[loc].locRank = 1;
		for(j = loc+1; j < loc+m; j++)
		{
			if(T[j].socre == T[j-1].socre)
			{
				T[j].locRank = T[j-1].locRank;
			}
			else
			{
				T[j].locRank = j-loc+1;
			}
		}
		loc += m;
		
	}
	
	sort(T, T+loc, cmpt);
	T[0].rank = 1;
	for(j = 1; j < loc; j++)
	{
		if(T[j].socre == T[j-1].socre)
		{
			T[j].rank = T[j-1].rank;
		}
		else
		{
			T[j].rank = j+1;
		}
	}
	printf("%d\n", loc);
	for(i = 0; i < loc; i++)
	{
		printf("%s %d %d %d\n", T[i].id, T[i].rank, T[i].location, T[i].locRank);
	}
	
	return 0;
}
