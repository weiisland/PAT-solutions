#include <cstdio>
#include <cstring>
using namespace std;
//层序遍历与中序遍历确定二叉树 
typedef int type;//以后即使数组类型更改也只需要改一个地方 

const int maxn = 100;
struct node{
	type data;
	node* lchild;
	node* rchild;
};

node* layercreate(type layer[], type in[], int len, int inL, int inR)
{
	if(inL > inR)
	{
		return NULL;
	}
	int lb = inL, le, rb, re = inR;//in数组左右子树区间 
	bool flag = false;
	node* root = new node;
	for(int lev = 0; lev < len; lev++)//在层序遍历数组中找到第一个在in数组中的数，也就是该in数组的根 
	{
		for(int k = inL; k <= inR; k++)
		{
			if(layer[lev] == in[k])
			{
				le = k-1;
				rb = k+1;
				flag = true;
				root->data = in[k];
				break;
			}
		}	
		if(flag)
		{
			break;
		}		
	} 
	root->lchild = layercreate(layer, in, len, lb, le);
	root->rchild = layercreate(layer, in, len, rb, re);
	return root;
}

void preOrder(node* root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

int main()
{
	int n;
	type layer[maxn], in[maxn];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &layer[i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	node* root = layercreate(layer, in, n, 0, n-1);
	preOrder(root);
	return 0;
}
