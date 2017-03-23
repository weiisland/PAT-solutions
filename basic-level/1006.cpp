/*
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。
例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
SS123
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int n,i;
  scanf("%d",&n);
  
  char s[128];
  char tmp[9];
  
  int c = n % 10;//个 

  int b = (n / 10) % 10;//十 

  int a = n / 100;//百   

  
  if(a != 0)
  {
    for(i = 0; i < a; i++)
    {
      s[i] = 'B';
      
    }
    s[a] = NULL;
  }
  else
  {
    s[a] = NULL;
  }

  if(b != 0)
  {
    for(i = 0; i < b; i++)
    {
      strcat(s,"S");
    }
  }
  
  if(c != 0)
  {
    for(i = 0; i < c; i++)
    {
      sprintf(tmp,"%d",i+1);
      strcat(s,tmp);
    }
  }

  printf("%s",s);
   
  return 0;
}
