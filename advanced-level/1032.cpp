#include <cstdio>
#include <cstring>

const int maxn = 100010;

struct Node{
	char c;
	int next;
	bool flag;
}node[maxn];

int main()
{
	for(int i = 0; i < maxn; i++)
	{
		node[i].flag = false;
	}
	int addr1, addr2, n;
	scanf("%d%d%d", &addr1, &addr2, &n);
	for(int i = 0; i < n; i++)
	{
		int ad1, ad2;
		char s;
		scanf("%d %c %d", &ad1, &s, &ad2);
		node[ad1].c = s;
		node[ad1].next = ad2;
	}
	
	int p = addr1;
	int q = addr2;
	int len1 = 0, len2 = 0;
	while(p != -1)
	{
		len1++;
		p = node[p].next;
	}
	while(q != -1)
	{
		len2++;
		q = node[q].next;
	}
	p = addr1;
	q = addr2;
	if(len1 > len2)
	{
		int del = len1 - len2;
		while(del > 0)
		{
			p = node[p].next;
			del--;
		}
	}
	else
	{
		int del = len2 - len1;
		while(del > 0)
		{
			q = node[q].next;
			del--;
		}
	}

	while(p != -1 && q != -1)
	{
		if(node[p].c == node[q].c && p == q) //必须多加p==q这个判断，判断是同一个地址 
		{
			printf("%05d", p);
			return 0;
		}
		else
		{
			p = node[p].next;
			q = node[q].next;
		}
	}
	printf("-1");
	return 0;
}
