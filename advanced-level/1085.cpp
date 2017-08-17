#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int A[maxn];
//寻找第一个大于x的数 
int high_bin(int left, int right, long long x)
{
	int mid;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(A[mid] > x)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	int n, p;
	
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A, A+n);
	int sum = -1;
	for(int i = 0; i < n; i++)
	{
		long long temp = (long long)A[i] * p;//可能达到10^18次方，用long long 
		int cur = high_bin(0, n, temp) - i;
		if(cur > sum)
		{
			sum = cur;
		}
	}
	printf("%d\n", sum);
	return 0;
}
