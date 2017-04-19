#include <stdio.h>

int callatz(int n)
{
  int i = 0;
  while(n != 1)
  {
    if(n%2 != 0)
    {
      n = (3*n+1)/2;
    }
    else
    {
      n = n/2; 
    }
    i++;
  }
  return i;
}


int main()
{
  int n;
  scanf("%d", &n);
  
  int i = callatz(n);
  printf("%d\n", i);
  return 0;
}
