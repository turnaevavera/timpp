#include <stdio.h>
#include <stdlib.h>
void sorting_function(int *num, int bbb, int lenght)
{
    int maximum;
    int acc = 0;
    while ((bbb * 2 <= lenght) && (!acc))
    {
        if (bbb * 2 == lenght){
            maximum = bbb * 2;
        }
        else if (num[bbb * 2] > num[bbb * 2 + 1]){
            maximum = bbb * 2;
        }else{
            maximum = bbb * 2 + 1;
        }
        if (num[bbb] < num[maximum])
        {
            int temp = num[bbb];
            num[bbb] = num[maximum];
            num[maximum] = temp;
            bbb = maximum;
        }else
            acc = 1;
    }
}
void sortingg_function(int *num, int array_size)
{
    for (int i = (array_size / 2) - 1; i >= 0; i--)
        sorting_function(num, i, array_size);
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = num[0];
        num[0] = num[i];
        num[i] = temp;
        sorting_function(num, 0, i - 1);
    }
}
int main()
{
    int a, i;
    scanf("%d", &a);
    int m[a];
    for(i=0; i<a; i++){
        scanf("%d", &m[i]);
    }
    sortingg_function(m, a);
    for (i = 0; i<a; i++){
        printf("%d ", m[i]);
    }
    printf("\a");
    printf("\n");
    return 0;
}
