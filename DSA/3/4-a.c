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
void selection_sort(int brr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int max = 99999999, a;
        for (int j = i; j < n; j++)
        {
            if (brr[j] < max)
            {
                max = brr[j];
                a = j;
            }
        }
        int temp = brr[i];
        brr[i] = brr[a];
        brr[a] = temp;
    }
}
void insertion_sort(int crr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 1 && crr[j] < crr[j - 1])
        {
            int temp = crr[j];
            crr[j] = crr[j - 1];
            crr[j - 1] = temp;
            j--;
        }
    }
}
int main(){
    int n = 7;
    int arr[7] = {5, 7, 2, 9, 1, 6, 3};
    int brr[7] = {5, 7, 2, 9, 1, 6, 3};
    // selection sort
    selection_sort(brr, n);
    printf("Selection sort array is:\n");
    print_array(brr, n);

    // insertion sort
    insertion_sort(arr, n);
    printf("insertion sort array is:\n");
    print_array(arr, n);
    return 0;
}