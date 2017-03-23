/*
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/

#include <stdio.h>

typedef struct student
{
  char name[11];
  char id[11];
  int result;
}stu;

int main()
{
  int n;
  scanf("%d", &n);
  
  if(n == 0)
  {
    return 0;
  }

  int i, max, min;
  stu stus[n];
  for(i = 0; i < n; i++)
  {
    scanf("%s %s %d", stus[i].name, stus[i].id, &stus[i].result);
    //printf("%s %s %d\n", stus[i].name, stus[i].id, stus[i].result);
  }
  max = stus[0].result;
  min = stus[0].result;
  stu tempmax, tempmin;
  tempmax = tempmin = stus[0];
  for(i = 1; i < n; i++)
  {
    //max = (max > stus[i].result) ? max : stus[i].result;
    if(max < stus[i].result)
    {
      max = stus[i].result;
      tempmax = stus[i];
    }
    
    if(min > stus[i].result)
    {
      min = stus[i].result;
      tempmin = stus[i];
    }
    
  }
  
  printf("%s %s\n", tempmax.name, tempmax.id);
  printf("%s %s", tempmin.name, tempmin.id);
  return 0;
}
