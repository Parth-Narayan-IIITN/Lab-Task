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
    for (int i = 0; i < n; i=i+2)
    {
        int max = 99999999, a;
        for (int j = i; j < n; j=j+2)
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
    printf("Selection:\n");
    for(int i=0;i<n;i=i+2){
        printf("%d ",brr[i]);
    }
    printf("\n");
}
void insertion_sort(int crr[], int n)
{
    for (int i = 3; i < n; i=i+2)
    {
        int j = i;
        while (j >= 3 && crr[j] < crr[j - 2])
        {
            int temp = crr[j];
            crr[j] = crr[j - 2];
            crr[j - 2] = temp;
            j=j-2;
        }
    }
    printf("Insertion:\n");
    for(int i=1;i<n;i=i+2){
        printf("%d ",crr[i]);
    }
    printf("\n");
}
int main(){
    int n = 9;
    int arr[9] = {54, 72, 92, 69, 11, 26, 31,87,42};
    selection_sort(arr, n);
    insertion_sort(arr, n);
    printf("sort array is:\n");
    print_array(arr, n);
    return 0;
}