#include <stdio.h>
#include <stdbool.h>
void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}
int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    while (i < j)
    {
        while (i <= h && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}
void quick_sort(int a[], int l, int h)
{
    if (l < h)
    {
        int j = partition(a, l, h);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, h);
    }
}
int main(){
    int n=7;
    int err[7] = {5, 7, 2, 9, 1, 6, 3};
    quick_sort(err, 0, n - 1);
    printf("quick sort array is:\n");
    print_array(err, n);

    return 0;
}