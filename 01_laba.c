#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int sift(int *chisl, int verh, int niz)
{
    int temp = 0;
    int maximum, success = 0;
    while ((verh * 2 <= niz) && (!success))
    {
        if (verh * 2 == niz) {
          temp++;
          maximum = verh * 2;
        }
        else if (chisl[verh * 2] > chisl[verh * 2 + 1]) {
         temp++; 
         maximum = verh * 2;
        }
        else {temp++;
          maximum = verh * 2 + 1;
        }
         temp++;
        if (chisl[verh] < chisl[maximum])
        {
            int temp1 = chisl[verh];
            chisl[verh] = chisl[maximum];
            chisl[maximum] = temp1;
            verh = maximum;
            temp++;
        }
        else {
          success = 1;
             }
    }
  return temp;
}

int funcPyramidSort(int *chisl, int arr_len)
{
    int temp = 0;
    for (int i = (arr_len / 2) ; i >= 0; i--) {
      temp+=sift(chisl, i, arr_len - 1);
    }

    for (int i = arr_len - 1; i >= 1; i--)
    {
        int temp1 = chisl[0];

        chisl[0] = chisl[i];

        chisl[i] = temp1;

        temp+=sift(chisl, 0, i - 1);

    }

    return temp;

}

int main()
{
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

rez = funcPyramidSort(a,n[f]);

sr_rez +=rez;

}

stop = clock();
printf("%d\n %f \n",n[f],sr_rez/1000);
sr_rez = 0;
rez = 0;
double clock_rez = (stop - start)/(double)CLOCKS_PER_SEC;
printf("%f \n",clock_rez*100000);
start ,stop = 0;
clock_rez = 0;
}
}
