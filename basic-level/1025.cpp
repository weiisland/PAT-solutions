#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int addr, data, next;
	bool flag;
	int order;//用来代表链表的链接序号 
}node[maxn];

int cmp(Node a, Node b)
{
	if(a.flag == false || b.flag == false)
	{
		return a.flag > b.flag;
	}
	else
	{
		return a.order < b.order;
	}
}

void reverse(Node node[], int start, int end)
{
	Node tmp;
	int mid = (start + end)/2;
	for(int i = start, j = 0; i < mid; i++)
	{
		tmp = node[i];
		node[i] = node[end-1-j];//如果end-1-i会导致第二轮反转出错 
		node[end-1-j] = tmp;
		j++;
	}
}

int main()
{
	for(int i = 0; i < maxn; i++)
	{
		node[i].flag = false;
		node[i].order = maxn;
	}
	int begin, n, k;
	scanf("%d%d%d", &begin, &n, &k);
	int add;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &add);
		scanf("%d%d", &node[add].data, &node[add].next);
		node[add].addr = add;
	}
	
	int p = begin, count = 0;
	while(p != -1)
	{
		node[p].flag = true;
		node[p].order = count;
		count++;	
		p = node[p].next;
	}
	
	sort(node, node+maxn, cmp);

	for(int i = 0; i < count; i += k)
	{
		if(i+k <= count)//必须用count而不是n，不然最后一个判断点会出错，因为有可能链表并不是连续有效地 
		{
			reverse(node, i, i+k);
		}	
	}
	
	for(int i = 0; i < count; i++)
	{
		if(i != count-1)
		{
			printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i+1].addr);
		}
		else
		{
			printf("%05d %d -1\n", node[i].addr, node[i].data);
		}
	}
	return 0;
}
 
