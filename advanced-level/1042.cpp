#include <stdio.h>

int main()
{
	char shape[] = {'S', 'H', 'C', 'D', 'J'};
	int k, i, j;
	scanf("%d", &k);
	int A[54];
	int keep[54];//保存最后54张牌最后的位置 
	int f;//用来保存k次洗牌后 对应的牌的位置 
	
	for(i = 0; i < 54; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < 54; i++)
	{
		f = A[i];//f赋初值，第一次洗牌位置 
		for(j = 1; j < k; j++)
		{
			f = A[f-1];//k次洗牌后位置 
		}
		keep[i] = f;//保存f 
	}
	
	for(i = 1; i < 54; i++)
	{
		for(j = 1; j <= 54; j++)
		{
			//按照洗完牌的顺序从1-54位置分别输出 
			if(i == keep[j-1])
			{
				printf("%c%d ", shape[(j-1)/13], j%13 == 0 ? 13 : j%13);
			}
		}
	}
	//最后一个输出的数特别处理 
	for(j = 1; j <= 54; j++)
	{
		if(54 == keep[j-1])
		{
			printf("%c%d", shape[(j-1)/13], j%13 == 0 ? 13 : j%13);
		}
	}
	
	return 0;
}
