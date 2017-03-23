/*
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：

输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。

输出格式：

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7
*/

#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()

{
  string input;
  getline(cin, input);
  
  int count[26] = {0}, max = 0;
  char tmp;

  int len = input.length();
  for (int i = 0; i < len; i++)
  {
    if (65 <= input[i] && input[i] <= 90)
    {
      input[i] = tolower(input[i]);
    }

    for (int j = 'a'; j <= 'z'; j++)
    {
      if (input[i] == j)
      {
        count[j-'a']++;
      }
    }
  }
  
  for (int i = 0; i < 26; i++)
  {
    if (max < count[i])
    {
      max = count[i];
      tmp = 'a' + i;
    }
  }

  printf("%c %d", tmp, max);
  return 0;
}
