#include <stdio.h>
#include <stdlib.h> 
void sorting_function(int *array, int lenght) 
{
    if (array && lenght)
    {
        int bb = lenght;
        int i;
        int aa = 1;
        while (bb > 1 || aa)
        {
            if (bb > 1)
                bb /= 1.24733; 
            aa = 0;
            for (i = 0; i + bb < lenght; ++i)
                if (array[i + bb] < array[i])
                {
                    int cc;
                    cc = array[i];
                    array[i] = array[i + bb];
                    array[i + bb] = cc;
                    aa = 1;
                }
        }
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
