/*
给定数字0-9各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意0不能做首位）。
例如：给定两个0，两个1，三个5，一个8，我们得到的最小的数就是10015558。

现给定数字，请编写程序输出能够组成的最小的数。

输入格式：

每个输入包含1个测试用例。每个测试用例在一行中给出10个非负整数，顺序表示我们拥有数字0、数字1、……数字9的个数。整数间用一个空格分隔。
10个数字的总个数不超过50，且至少拥有1个非0的数字。

输出格式：

在一行中输出能够组成的最小的数。

输入样例：
2 2 0 0 0 3 0 0 1 0
输出样例：
10015558
*/

#include <stdio.h>
#include <string>

int main()
{
  int num[10];

  int str[50];
  int count = 0;
  scanf("%d%d%d%d%d%d%d%d%d%d", &num[0],&num[1],&num[2],&num[3],&num[4],&num[5],&num[6],&num[7],&num[8],&num[9]);
  
  
  for(int i = 1; i < 10; i++)
  {
    if(num[i] != 0)
    {  
      for(int j = 0; j < num[i]; j++)
      {
        str[count] = i;
        count++;
      }
        
    }
  }
  
  if(num[0] != 0)
  {
    for(int j = count -1; j > 0; j--)
    {
      str[j + num[0]] = str[j];
    }
    for(int i = 1; i <= num[0]; i++)
    {
      str[i] = 0;
    }
    
    for(int k = 0; k < count+num[0]; k++)
    {
      printf("%d", str[k]);
    }
    
  }
  else
  {
    for(int i = 0; i < count; i++)
    {
      printf("%d", str[i]);
    }
  }
  
  return 0;
}
