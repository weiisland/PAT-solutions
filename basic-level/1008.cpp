/*
数组元素循环右移问题 (20)
一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。

输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例：
6 2
1 2 3 4 5 6
输出样例：
5 6 1 2 3 4
*/
#include <stdio.h>

void reverse(int A[], int start, int end)
{
	int i, j;
	for(i = start, j = end; i < j; i++, j--)
	{
		int temp = A[j];
		A[j] = A[i];
		A[i] = temp;
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	
	int f = m%n;
	int i, A[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	reverse(A, 0, n-1);
	reverse(A, 0, f-1);
	reverse(A, f, n-1);
	for(i = 0; i < n-1; i++)
	{
		printf("%d ", A[i]);
	}
	printf("%d", A[n-1]);
	return 0;
}
