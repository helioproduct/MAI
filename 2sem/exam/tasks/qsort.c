#include <stdio.h>  


void qsort_rec(int* a, int l, int r)
{
    int i = l, j = r;
    int tmp;
    int x = a[(l + r) / 2];
    
    do 
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
            
        if (i <= j) 
        {
            if (i < j) {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);
    
    if (i < r)
        qsort_rec(a, i, r);
    if (l < j)
        qsort_rec(a, l,j);
}

int main(void)
{
    int a[5] = {5, 4, 3, 2, 1};
    int size = sizeof(a) / sizeof(a[0]);

    qsort_rec(a, 0, size - 1);

    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);

    return 0;
}