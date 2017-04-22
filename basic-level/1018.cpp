/*
锤子剪刀布 (20)
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/

#include <stdio.h>

int judge(char a, char b)
{
	if(a == b)
	{
		return 0;
	}
	
	if((a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C'))
	{
		return 1;
	}
	else if((b == 'C' && a == 'J') || (a == 'C' && b == 'B') || (b == 'J' && a == 'B'))
	{
		return -1;
	}
}

int max(int a, int b, int c)
{
	if(a > b && a > c)
	{
		return a;
	}
	else if(b > a && b > c)
	{
		return b;
	}
	else
	{
		return c;
	}
}

void winmax(int aj, int ac, int ab)
{
	if(ac == aj && aj == ab)
	{
		printf("B");
	}
	else if(ac == aj && ab < aj)
	{
		printf("C");
	}
	else if(ab == ac && aj < ac)
	{
		printf("B");
	}
	else if(ab == aj && ac < aj)
	{
		printf("B");
	}
	else if(ac == max(aj, ac, ab))
	{
		printf("C");
	}
	else if(ab == max(aj, ac, ab))
	{
		printf("B");
	}
	else if(aj == max(aj, ac, ab))
	{
		printf("J");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int a1 = 0, a2 = 0, a3 = 0;//甲赢， 平， 负 
	int ac = 0, aj = 0, ab = 0;
	int bc = 0, bj = 0, bb = 0;
	while(n--)
	{
		getchar();//注意这里要吸收掉输入n时候的一个换行符，不然会被scanf写入
		char a, b;
		scanf("%c %c", &a, &b);
		if(judge(a, b) == 1)
		{
			a1++;
			if(a == 'C')
			{
				ac++;
			}
			else if(a == 'B')
			{
				ab++;
			}
			else if(a == 'J')
			{
				aj++;
			}
		}
		if(judge(a, b) == 0)
		{
			a2++;
		}
		if(judge(a, b) == -1)
		{
			a3++;
			if(b == 'C')
			{
				bc++;
			}
			else if(b == 'B')
			{
				bb++;
			}
			else if(b == 'J')
			{
				bj++;
			}
		}
	}
	
	printf("%d %d %d\n", a1, a2 , a3);
	printf("%d %d %d\n", a3, a2 , a1);

	winmax(aj, ac, ab);
	printf(" ");
	winmax(bj, bc, bb);
	return 0;
}
