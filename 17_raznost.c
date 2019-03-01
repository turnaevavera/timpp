#include <stdio.h>
#include <math.h>

int main()
{
	signed long n,i,x,c,s=0;
	scanf("%ld", &n);
	for(i=0; i<n; i++)
	{
	scanf ("%ld",&x);
	c=(pow((-1),(i+1))*pow(x,2));
	s = s + c;
	}	
	printf ("%ld\n",s);
return 0;
}
