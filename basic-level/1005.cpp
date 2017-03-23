/*
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，
则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，
我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。

输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

输入样例：
6
3 5 6 7 8 11
输出样例：
7 6
*/

#include <stdio.h>

void select(int *A, int *B, int n)
{
	int i, j;
	//int *B = A; //B指向A，A怎么变化，B输出的都是A 

	for(i = 0; i < n; i++)
	{
		while(A[i] != 1)
		{
			if(A[i]%2 == 0)
			{
				A[i] /= 2;
				for(j = 0; j < n; j++)
				{
					if(i != j && A[i] == B[j])
					{
						B[j] = 0;
					}
				}
			}
			else if(A[i]%2 == 1)
			{
				A[i] = (3 * A[i] + 1) / 2;
			
				for(j = 0; j < n; j++)
				{
					if(i != j && A[i] == B[j])
					{
						B[j] = 0;
					}
				}
			}
		}	
	}
}

void insertsort(int *A, int n)
{
	int i, j;
	for(i = 1; i < n; i++)
	{
		int key = A[i];
		j = i-1;
		while(j >= 0 && A[j] < key)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
		
	}
}

void insertsort2(int *A, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		int key = A[i];
		if(A[i-1] <= A[i])
		{
			j = i-1;
			while(j >= 0 && A[j] < key)
			{
				A[j+1] = A[j];
				j--;
			}
			A[j+1] = key;
		}			
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int A[n], B[n];
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < n; i++)
	{
		B[i] = A[i]; //这样改变A才不会改变B 
	}
	
	select(A, B, n);

	insertsort(B, n);
	
	
	for(i = 0; i < n; i++)
	{
		if(B[i+1] != 0 && B[i] != 0 && i+1 <= n)
		{
			printf("%d ", B[i]);
		}
		else if(B[i+1] == 0 && B[i] != 0 && i+1 <= n)
		{
			printf("%d", B[i]);
		}
		
	}
	
	return 0;
}
