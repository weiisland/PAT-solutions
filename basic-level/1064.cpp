/*
如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如123和51就是朋友数，因为1+2+3 = 5+1 = 6，
而6就是它们的朋友证号。给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。注意：我们默认一个整数自己是自己的朋友。

输入格式：

输入第一行给出正整数N。随后一行给出N个正整数，数字间以空格分隔。题目保证所有数字小于104。

输出格式：

首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。

输入样例：
8
123 899 51 998 27 33 36 12
输出样例：
4
3 6 9 26
*/

#include <iostream>

using namespace std;

int main()
{
  int n, count = 1;
  cin >> n;
  int num[n], st[n];
  for(int i = 0; i < n; i++)
  {
    cin >> num[i];
    int a = num[i];
    int temp = 0;
    while(a >= 1)
    {
      temp += a % 10;
      a = a / 10;
    }
    st[i] = temp;
  }
  
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j < n - i; j++)
    {
      if(st[j] < st[j-1])
      {
        int tmp = st[j-1];
        st[j-1] = st[j];
        st[j] = tmp;
      }
    }
  }
  
  for(int i = 1; i < n; i++)
  {
    if(st[i-1] < st[i])
    {
      count++;
    }
  }
  
  cout << count << endl;
  
  for(int i = 1; i < n; i++)
  {
    if(st[i-1] < st[i])
    {
      cout << st[i-1] <<" ";
    }
  }
  cout << st[n-1];
  return 0;
}
