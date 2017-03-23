/*
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int calDA(char *A, char DA)
{
  char *tmp;
  char result[10],temp[2];
  memset(result,0,sizeof(result));
  memset(temp,0,sizeof(temp));
  int count = 0, i = 0;
  sprintf(temp, "%c",DA);
  
  tmp = strstr(A,temp);
  while(NULL != tmp)
  {
    count++;
    tmp = strstr(tmp+1, temp);    
  }

  if(count > 0)
  {
    for(i = 0; i < count; i++)
    {
      result[i] = DA;
    }
    return atoi(result);
  }
  else
  {
    return 0;
  }
}

int main()
{
  char A[10] , DA[10], B[10], DB[10];
  scanf("%s%s%s%s", A,DA,B,DB);
  int calA,calB;
  calA = calDA(A,DA[0]);

  calB = calDA(B,DB[0]);
 
  printf("%d",calA+calB);
  return 0;
}
