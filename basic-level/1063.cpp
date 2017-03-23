/*
在数学中，矩阵的“谱半径”是指其特征值的模集合的上确界。换言之，对于给定的n个复数空间的特征值{a1+b1i, ..., an+bni}，
它们的模为实部与虚部的平方和的开方，而“谱半径”就是最大模。

现在给定一些复数空间的特征值，请你计算并输出这些特征值的谱半径。

输入格式：

输入第一行给出正整数N（<= 10000）是输入的特征值的个数。随后N行，每行给出1个特征值的实部和虚部，其间以空格分隔。
注意：题目保证实部和虚部均为绝对值不超过1000的整数。

输出格式：

在一行中输出谱半径，四舍五入保留小数点后2位。

输入样例：
5
0 1
2 0
-1 0
3 3
0 -3
输出样例：
4.24
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float bubbleSort(float *array, int n)
{
  int i, j;
  for(i = 0; i < n; i++)
  {
    for(j = 1; j < n - i; j++)
    {
      if(array[j-1] > array[j])
      {
        float tmp = array[j-1];
        array[j-1] = array[j];
        array[j] = tmp;
      }     
    }
  }
  return array[n-1];
}

int main()
{
  int n = 0, i = 0;
  scanf("%d", &n);
  
  int sa[n][2];
  float result[n];
  for(i = 0; i < n; i++)
  {
    scanf("%d%d", &sa[i][0], &sa[i][1]);
    int tmp = pow(sa[i][0], 2) + pow(sa[i][1], 2);
    result[i] = sqrt(tmp);
  }
  printf("%0.2f", bubbleSort(result, n));
  return 0;
}
