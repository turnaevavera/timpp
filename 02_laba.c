#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int sort(int *chisl, int size)
{
	int i, j,temp=0;

	int sm;

	int tmp;

	for (sm = size / 2; sm > 0; sm /= 2){

		for (i = sm; i < size; i++)

		{

			tmp = chisl[i];

			for (j = i; j >= sm; j -= sm)

			{

				if (tmp < chisl[j - sm])

				{

				    temp++;

					chisl[j] = chisl[j - sm];

				}

				else{

				    temp++;

					break;
				}

				temp++;
			}

			chisl[j] = tmp;
		}
	}

	return temp;	

}

int main()

{
    srand(time(0));
  clock_t start,stop;
unsigned long t;
    double rez,sr_rez = 0;
int n[15] = {1,2,3,4,5,10,15,20,25,30,50,75,100,250,500};
for (int f = 0 ; f <15;f++)
{
int *a;
a = (int*)malloc(n[f] * sizeof(int));
start = clock();
for (int j = 0;j <1000;j++)
{
for (int i = 0;i < n[f]; i ++)
{
a[i] = rand()%  10000 - 8419;
} 
rez = sort(a,n[f]);
sr_rez +=rez;
}
stop = clock();
printf("%d\n %f \n",n[f],sr_rez/1000);
sr_rez = 0;
rez = 0;
double clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",clock_rez*1000000);
start ,stop = 0;
clock_rez = 0;
}
}
