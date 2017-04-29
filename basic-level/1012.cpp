#include <stdio.h>

int main()
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    int b2 = 0, b4 = 0, b5 = 0;
    int i, A[n];
    for(i = 0; i < n; i++)
    {
      scanf("%d", &A[i]);
      if(A[i] % 5 == 0 && A[i]%2 == 0)
      {
        a1 += A[i];
      }
      else if(A[i] % 5 == 1)
      {
        if(b2 % 2 == 0)
        {
          a2 += A[i];
        }
        else
        {
          a2 -= A[i];
        }
        b2++;
      }
      else if(A[i] % 5 == 2)
      {
        a3++;
      }
      else if(A[i] % 5 == 3)
      {
        b4++;
        a4 += A[i];
      }
      else if(A[i] % 5 == 4)
      {
        if(A[i] > a5)
        {
          a5 = A[i];
        }
      }
    }
    
    a1 == 0 ? printf("N ") : printf("%d ", a1);
    a2 == 0 && b2 == 0 ? printf("N ") : printf("%d ", a2);
    a3 == 0 ? printf("N ") : printf("%d ", a3);
    a4 == 0 ? printf("N ") : printf("%.1f ", (double)a4/b4);
    a5 == 0 ? printf("N") : printf("%d", a5);
    printf("\n");
    //printf("%d %d %d %.1f %d\n", a1, a2, a3, (double)a4/b4, a5);
  }
  return 0;
}
