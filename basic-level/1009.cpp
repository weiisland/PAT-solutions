/*
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

int getline(char *line, int max)
{
  if(fgets(line, max, stdin) == NULL)
  {
    return 0;
  }
  else
  {
    return strlen(line);
  }
}

int main()
{
  char str[81];
  char str2[80];
  char *keep[80];
  int len; 

  len = getline(str, MAXLINE);
  
  char *p, *q;
  int i = 0, j = 0, k = 0;
  p = q = str;
  
  p = strchr(str, ' ');
  while(p)
  {
    
    keep[i] = (char*)malloc((p-q) * sizeof(char));
    memset(keep[i], 0, sizeof(keep[i]));

    strncpy(keep[i], q, p-q);

    i++;
    q = p+1;
    
    p = strchr(p+1, ' ');
  }
  keep[i] = (char*)malloc((sizeof(q)/sizeof(char))* sizeof(char));

  strncpy(keep[i], q, strlen(q)-1);

  for(; i > 0; i--)
  {
    printf("%s ", keep[i]);  
  }
  printf("%s", keep[0]);
  return 0;
}
