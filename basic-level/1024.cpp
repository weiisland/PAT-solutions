#include <cstdio>
#include <cstring>

int main()
{
	char num[10001];
	char real[20001];
	gets(num);
	int len = strlen(num);
	int i, j, p, e; //p小数部分，是E的位置 
	for(i = 3; num[i] != 'E'; i++)
	{
		;
	}
	p = i;//E
	int gap = p - 3;//gap是小数点后面的位数 
	e = p+1;//+ - e是指数的符号位置 
	int exp = 0;//exp是指数大小 
	for(i = e+1; i < len; i++)
	{
		exp = exp * 10 + (num[i] - '0');
	}
	if(num[0] == '+' || num[0] == '-') 
	{
		real[0] = num[0];//直接根据正负数来区分输出， real[0]固定是符号位 
		if(num[e] == '+')//指数为正要区分小数部分位数是否大于指数 
		{
			real[1] = num[1];
			if(gap <= exp)//小于指数，多余的补0 
			{
				for(j = 2, i = 3; i < p; j++, i++)
				{
					real[j] = num[i];
				}
				
				for(i = 0 ; i < exp-gap; i++, j++)//补0 
				{
					real[j] = '0';
				}
				real[j] = '\0';
			}
			else
			{
				for(j = 2, i = 3; i < 3+exp; j++, i++)//确定小数点位置 
				{
					real[j] = num[i];
				}
				real[j] = '.';
				j++;
				for(; i < p; j++, i++)
				{
					real[j] = num[i];
				}
			}
			
		}
		else //E- 指数是负数 
		{
			if(exp == 0)
			{
				real[1] = num[1]; 
			}
			else
			{
				real[1] = '0';
			}
			real[2] = '.';
			for(j = 3, i = 0; i < exp-1; j++, i++)//小数点后的0 
			{
				real[j] = '0';
			}
			real[j] = num[1];//整数位 
			j++;
			for(i = 3; i < p; i++, j++)
			{
				real[j] = num[i];
			}
		}
	}
	
	if(num[0] == '+')
	{
		for(i = 1; i < strlen(real); i++)
		{
			printf("%c", real[i]);
		}
	}
	else
	{
		for(i = 0; i < strlen(real); i++)
		{
			printf("%c", real[i]);
		}
	}
	
	return 0;
}
