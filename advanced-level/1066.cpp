#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int data, height;
	node *lchild;
	node *rchild; 
}*root;//必须在此先定义root，之后才能被&引用 

node* newNode(int data)
{
	node* root = new node;
	root->data = data;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}

int getHeight(node *root)
{
	if(root == NULL)
	{
		return 0;
	 } 
	return root->height;
}

void updateH(node *root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1; 
}

int balanceH(node *root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node* &root)//用到了引用，前面就必须有先声明root 
{
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateH(root);
	updateH(temp);
	root = temp;
}

void R(node* &root)
{
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateH(root);
	updateH(temp);
	root = temp;
}

void insert(node* &root, int v)
{
	if(root == NULL)
	{
		root = newNode(v);
		return;
	}
	
	if(v < root->data)
	{
		insert(root->lchild, v);
		updateH(root);
		if(balanceH(root) == 2)
		{
			if(balanceH(root->lchild) == 1) //LL
			{
				R(root);
			}
			else if(balanceH(root->lchild) == -1) //LR
			{
				L(root->lchild);//注意 
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild, v);
		updateH(root);
		if(balanceH(root) == -2)
		{
			if(balanceH(root->rchild) == -1) // RR
			{
				L(root);
			}
			else if(balanceH(root->rchild) == 1) // RL
			{
				R(root->rchild);
				L(root);
			 } 
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int temp;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		insert(root, temp);
	}
	printf("%d\n", root->data);
	return 0;
}
