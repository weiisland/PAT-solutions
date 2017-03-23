/*
每个PAT考生在参加考试时都会被分配两个座位号，一个是试机座位，一个是考试座位。正常情况下，考生在入场时先得到试机座位号码，入座进入试机状态后，
系统会显示该考生的考试座位号码，考试时考生需要换到考试座位就座。但有些考生迟到了，试机已经结束，他们只能拿着领到的试机座位号码求助于你，
从后台查出他们的考试座位号码。

输入格式：

输入第一行给出一个正整数N（<=1000），随后N行，每行给出一个考生的信息：“准考证号 试机座位号 考试座位号”。其中准考证号由14位数字组成，
座位从1到N编号。输入保证每个人的准考证号都不同，并且任何时候都不会把两个人分配到同一个座位上。

考生信息之后，给出一个正整数M（<=N），随后一行中给出M个待查询的试机座位号码，以空格分隔。

输出格式：

对应每个需要查询的试机座位号码，在一行中输出对应考生的准考证号和考试座位号码，中间用1个空格分隔。

输入样例：
4
10120150912233 2 4
10120150912119 4 1
10120150912126 1 3
10120150912002 3 2
2
3 4

输出样例：
10120150912002 2
10120150912119 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_s
{
  char admission[14];
  int cmp_num;
  int sit_num;
}student_t;

int main(int argc, char *argv[]) {
  int n = 0, i = 0, j = 0,m=0;
  scanf("%d",&n);
  
  student_t st[n];
  
  
  for(i =0; i < n ; i++)
  {
    scanf("%s",st[i].admission);
    scanf("%d%d",&st[i].cmp_num,&st[i].sit_num);
    if (st[i].cmp_num > n || st[i].sit_num > n) {
      return 0;
    }    
  }
  scanf("%d",&m);
  int tryit[m];
  for(i = 0 ; i < m; i++)
  {
    tryit[i] = 0;
    scanf("%d",&tryit[i]);
  }
  
  for(i = 0 ; i < m; i++)
  {
    for(j =0; j < n; j++)
    {
      if(tryit[i] == st[j].cmp_num)
      {
        printf("%s %d\n", st[j].admission,st[j].sit_num);
      }
    }
  }
  
  return 0;
}
