#include <stdio.h>
#include <stdlib.h> 
void sorting_function(int *array, int size)
{
    int i, j, shag;
    int cc;
    for (shag = size / 2; shag > 0; shag /= 2)
        for (i = shag; i < size; i++)
        {
            cc = array[i];
            for (j = i; j >= shag; j -= shag)
            {
                if (cc < array[j - shag])
                    array[j] = array[j - shag];
                else
                    break;
            }
            array[j] = cc;
        }
}
int main()
{
    int a, i;
    scanf("%d", &a);
    int arr[a];
    for(i=0; i<a; i++){
        scanf("%d", &arr[i]);
    }
    sorting_function(arr, a);
    for (i = 0; i<a; i++){
        printf("%d ", arr[i]);
    }
    printf("\a");
    return 0;
}
