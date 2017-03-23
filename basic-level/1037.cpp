/*
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，
二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，
Knut是[0, 29)区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int strToint(string s)
{
  const char* cs = s.c_str();
  char n1[7], n2[2], n3[2];
  const char *p1, *p2;
  p1 = strchr(cs, '.');
  snprintf(n1, p1-cs+1, "%s", cs);

  p2 = strchr(p1+1, '.');
  snprintf(n2, p2-p1, "%s", p1+1);

  snprintf(n3, 3, "%s", p2+1);

  int total = atoi(n1) * 17 * 29 + atoi(n2) * 29 + atoi(n3);
  return total;
  
}


int main()
{
  string Pm, Am;
  cin >> Pm >> Am;

  int remain = strToint(Am) - strToint(Pm);
  
  int Knut = abs(remain) % 29;
  int Sickle = (abs(remain) / 29) % 17;
  int Galleon = (abs(remain) / 29) / 17;
  
  if(remain >= 0)
  {
    printf("%d.%d.%d", Galleon, Sickle, Knut);
  }
  else
  {
    printf("-%d.%d.%d", Galleon, Sickle, Knut);
  }
  
  return 0;
}
