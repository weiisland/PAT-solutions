/*
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  char *chinese[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
  char num[101], csum[1001];
  scanf("%s", num);
  //printf("%s", num);
  int i, sum = 0, len = strlen(num);
  for(i=0; i < len; i++)
  {
    sum += (num[i] - '0');
  }
  //printf("%d\n", sum);
  sprintf(csum, "%d", sum);
  int cl = strlen(csum);
  for(i = 0; i < cl-1; i++)
  {
    int t = csum[i] - '0';
    printf("%s ", chinese[t]);
  }
  printf("%s", chinese[csum[cl-1] - '0']);
  
  return 0;
}
