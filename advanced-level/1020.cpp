#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 50;

int post[maxn], in[maxn];
int n;
struct node{
	int data;
	node *lchild, *rchild;
};

node* create(int postL, int postR, int inL, int inR)
{
	if(postL > postR)
	{
		return NULL;
	}
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k = inL; k <= inR; k++)
	{
		if(in[k] == post[postR])
		{
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(postL, postL+numLeft-1, inL, k-1);
	root->rchild = create(postL+numLeft, postR-1, k+1, inR);
	return root;
}
int num = 0;
void layerOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* top = q.front();
		q.pop();
		printf("%d", top->data);
		if(num < n-1)
		{
			printf(" ");
		}
		num++;
		if(top->lchild != NULL)
		{
			q.push(top->lchild);
		}
		if(top->rchild != NULL)
		{
			q.push(top->rchild);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	node *root = create(0, n-1, 0, n-1);
	layerOrder(root);
	return 0;
}
