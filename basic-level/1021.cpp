/*
给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。
例如：给定N = 100311，则有2个0，3个1，和1个3。

输入格式：

每个输入包含1个测试用例，即一个不超过1000位的正整数N。

输出格式：

对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

输入样例：
100311
输出样例：
0:2
1:3
3:1
*/

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  string s;
  cin >> s;
  char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
  int count[10] = {0};
  
  int len = s.length();
  for(int i = 0; i < len; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      if(s[i] == nums[j])
      {
        count[j]++;
      }
    }
  }
  
  
  for(int j = 0; j < 10; j++)
  {
    if(count[j] != 0)
    {
      printf("%c:%d\n", nums[j], count[j]);
    }
  }  
  return 0;
}
