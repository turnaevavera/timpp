#include <stdio.h>

int main()
{
  int i;
  signed long n=0;
  signed long x=0;
  float s=0;
  scanf ("%ld",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%ld",&x);
      s=s+x;
    }
    printf ("%.4f\n", (s/n));
  return 0;
}
