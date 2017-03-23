/*
给定一串长度不超过105的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，
得到整数N，然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，其字母序号之和为：16+1+20+2+1+19+9+3=71，
而71的二进制是1000111，即有3个0、4个1。

输入格式：

输入在一行中给出长度不超过105、以回车结束的字符串。

输出格式：

在一行中先后输出0的个数和1的个数，其间以空格分隔。

输入样例：
PAT (Basic)
输出样例：
3 4
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 100002

int getline(char *s, int max)
{
  if(fgets(s, max, stdin) == NULL)
  {
    return 0;
  }
  else
  {
    return strlen(s);
  }
}

int main()
{
  
  char str[100002];
  getline(str, MAXLINE);
  
  int i = 0, sum = 0, c0 = 0, c1 = 0;
  while(str[i] != '\0')
  {
    if('a' <= str[i] && str[i] <= 'z')
    {
      sum += (str[i] - 'a' + 1);
    }
    else if('A' <= str[i] && str[i] <= 'Z')
    {
      sum += (str[i] - 'A' + 1);
    }
    i++;
  }

  while(sum != 0)
  {
    if((sum % 2) == 1)
    {
      c1++;
    }
    else
    {
      c0++;
    }
    sum /= 2;
  }
  
  printf("%d %d", c0, c1);
  return 0;
}
