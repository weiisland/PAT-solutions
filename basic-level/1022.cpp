/*
输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
1103
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

void reverse(char *s)
{
  int i, j;
  int len = strlen(s);
  for(i = 0, j = len-1; i < len/2; i++, j--)
  {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

int main()
{
  int a, b, d, sum, j, i = 0;

  int s[100];
  scanf("%d%d%d", &a, &b, &d);
  sum = a + b;

  if(sum == 0)
  {
    printf("0");
    return 0;
  }
  else
  {
    while(sum != 0)
    {
      s[i++] = sum % d;
      sum /= d; 
    }
    for(j = i-1; j >= 0; j--)
    {
      printf("%d", s[j]);
    }
    return 0;
  }
}
