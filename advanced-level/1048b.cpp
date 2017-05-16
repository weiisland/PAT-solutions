#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int semiFind(int A[], int start, int end, int a)
{
	int mid;
	while(start <= end)
	{
		mid = (start+end)/2;
		if(a == A[mid])
		{
			return mid;
		}
		else if(a < A[mid])
		{
			end = mid-1;
		}
		else
		{
			start = mid+1;		
		}
	}
	return -1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int coins[n];
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &coins[i]);
	}
	sort(coins, coins+n);
	bool flag = false;
	
	for(i = 0; i < n-1; i++)
	{
		int ans = semiFind(coins, i+1, n-1, m-coins[i]);
		if(ans != -1)
		{
			printf("%d %d", coins[i], m-coins[i]);
			flag = true;
			break;
		}
	}
	
	if(flag == false)
	{
		printf("No Solution");
	}
	return 0;
}
