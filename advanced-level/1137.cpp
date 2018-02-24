#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define MAXN 10005
using namespace std;

struct node{
	string name;
	int gp, gm, gf, g;
};

node stu[MAXN];
map<string, int> post;

bool cmp(node stu1, node stu2)
{
	if(stu1.g != stu2.g)
	{
		return stu1.g > stu2.g;
	}
	else
	{
		return stu1.name < stu2.name;
	}
}

int main()
{
	int p, m, n, score, cnt = 1;
	string s;
	cin >> p >> m >> n;
	for(int i = 0; i < p; i++)
	{
		cin >> s >> score;
		if(score >= 200)
		{
			stu[cnt].name = s;
			stu[cnt].gp = score;
			stu[cnt].gm = -1;
			stu[cnt].gf = -1;
			post[s] = cnt;
			cnt++; 
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> s >> score;
		if(post[s] != 0)
		{
			stu[post[s]].gm = score;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		cin >> s >> score;
		if(post[s] != 0)
		{
			int t = post[s];
			stu[t].gf = stu[t].g = score;
			if(stu[t].gm > stu[t].gf)
			{
				stu[t].g = (int)(stu[t].gm * 0.4 + stu[t].gf * 0.6 + 0.5);
			}
		}
	}
	
	sort(stu + 1, stu + cnt, cmp);
	for(int i = 1; i < cnt; i++)
	{
		if(stu[i].g >= 60 && stu[i].g <= 100)
		{
			printf("%s %d %d %d %d\n", stu[i].name.c_str(), stu[i].gp, stu[i].gm, stu[i].gf, stu[i].g);
		}
		
	}
	return 0;
}
