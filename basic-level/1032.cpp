#include <stdio.h>

typedef struct wajue{
	int num;
	int score;
}wajue_s;

int main()
{
	int n;
	scanf("%d", &n);
	wajue_s wj[n];
	int sum[n+1];
	int i;
	for(i = 0; i < n; i++)
	{
		sum[i] = 0;
		scanf("%d%d", &wj[i].num, &wj[i].score);
	}
	
	for(i = 0; i < n; i++)
	{
		sum[wj[i].num] += wj[i].score;
	}
	
	int max = sum[0], top;
	for(i = 0; i < n+1; i++)
	{
		if(max < sum[i])
		{
			max = sum[i];
			top = i;
		}
	}
	printf("%d %d", top, max);
	return 0;
}
