/*
一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；
最后按照以下关系对应Z值与校验码M的值：

Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2

现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

输入格式：

输入第一行给出正整数N（<= 100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

输出格式：

按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。
如果所有号码都正常，则输出“All passed”。

输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：
All passed
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RIGHT 1
#define WRONG -1

static char cm[] = {'1','0','X','9','8','7','6','5','4','3','2'};
static int ba[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}; //100

int sumAndCheck(char *s)
{
  int len = strlen(s);
  int sum = 0, i = 0, mod = 0;

  for(i = 0; i < len-1; i++)
  {
    if(s[i] == 'X')
    {
      sum += (10 * ba[i]);
    }
    else if('0' <= s[i] && s[i] <= '9')
    {
      sum += ((s[i] - '0') * ba[i]);
    }
    else
    {
      return WRONG;
    }
  }
  mod = sum%11;
  return mod;
}



int main()
{
  int n, i;
  scanf("%d", &n);
  char *id[n];
  int result, flag = RIGHT;
  
  for(i = 0; i < n; i++)
  {
    id[i] = (char*)malloc(17*sizeof(char));
    memset(id[i], 0, sizeof(id[i]));
    scanf("%s", id[i]);
  }
  
  for(i = 0; i < n; i++)
  {
    result = sumAndCheck(id[i]);
    if(result == -1)
    {
      printf("%s\n", id[i]);
      flag = WRONG;
    }
    else if(cm[result] != id[i][17])
    {
      printf("%s\n", id[i]);
      flag = WRONG;
    }
    
  }
  if(flag == RIGHT)
  {
    printf("All passed");
  }

  return 0;
}
