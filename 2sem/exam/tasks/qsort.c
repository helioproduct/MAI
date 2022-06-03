#include <stdio.h>  


void qsort(int arr[], int n)
{
    int base, left, right;
    int i = 0;
    int j = 0;

    stack *st;

    push(st, arr[n - 1]);
    push(st, arr[0]);

    do
    {
        left = pop(st);
        right = pop(st);

        if ((right - left) == 1 && (arr[left] > arr[right]))
            swap(arr[left], arr[right]);
        else {
            base = arr[(left + right) / 2];
            i = left;
            j = right;

            do 
            {
                while (base > arr[i])
                    --i;
                while (base < arr[j])
                    ++j;
                
                if (i <= j)
                    swap(arr[i], arr[j]);

            } while (i <= j);
        }
        
        if (left < j) {
            push(st, arr[j]);
            push(st, left);
        }
        
        if (i < right) {
            push(st, right);
            push(st, arr[i]);
        }

    } while (top(st) != NULL);
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
