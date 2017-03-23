/*
小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，
某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，
还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。


图 1
输入格式：

每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

输出格式：

如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

输入样例1：
ppRYYGrrYBR2258
YrR8RrY
输出样例1：
Yes 8
输入样例2：
ppRYYGrrYB225
YrR8RrY
输出样例2：
No 2
*/

#include <stdio.h>

#define YES 1
#define NO 0

int toSort(char *s, int* ch)
{
  int i, sum;
  
  for(i = 0; i < 62; i++)
  {
    ch[i] = 0;
  }
  i = 0;
  while (s[i] != '\0' && s[i] != '\n') 
  {
    if ('0' <= s[i] && s[i] <= '9') {
      ch[s[i]-'0']++;
    }
    else if ('a' <= s[i] && s[i] <= 'z') {
      ch[10+s[i]-'a']++;
    }
    else if ('A' <= s[i] && s[i] <= 'Z') {
      ch[36+s[i]-'A']++;
    }
    i++;
  }

  sum = 0;
  for(i = 0; i < 62; i++)
  {
    //printf("%d:%d--", i, ch[i]);
    sum += ch[i];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  char a[1000], b[1000];//a是商店商品，b是想买的样式
  scanf("%s", a);
  scanf("%s", b);

  int i, j, k, sump, sumq;
  int p[62], q[62];
  sump = toSort(a, p);

  sumq = toSort(b, q);

  j = YES;
  k = 0;
  for(i = 0; i < 62; i++)
  {
    if((p[i] - q[i]) >= 0)
    {
      j = YES;
    }
    else
    {
      j = NO;
      break;
    }
    
  }
  if (j == YES) {
    printf("Yes %d", sump -sumq);
  }
  else if(j == NO)
  {
    for(i = 0; i < 62; i++)
    {
      if(q[i] > 0 && p[i] < q[i])
      {
        k += (q[i] - p[i]);
      }
      
    }
    printf("No %d", k);
  }
  return 0;
}
