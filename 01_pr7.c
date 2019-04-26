#include <stdio.h>
void sorting_function(int* arr, int lev, int prav)
{
    int i = lev, j = prav;
    double tmp, ccc = arr[(lev + prav) / 2];
    do {
        while (arr[i] < ccc)
            i++;
        while (arr[j] > ccc)
            j--;
        if (i <= j)
        {
            if (i < j)
            {
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < prav)
        sorting_function(arr, i, prav);
    if (lev < j)
        sorting_function(arr, lev,j);
}
int main()
{
    int a, i;
    scanf("%d", &a);
    int arr[a];
    for(i=0; i<a; i++){
        scanf("%d", &arr[i]);
    }
    sorting_function(arr,0,a-1);
    for(i=0; i<a; i++){
        printf("%d ", arr[i]);
    }
    printf("\a");
    printf("\n");
}
