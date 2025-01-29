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
void merge(int a[], int l, int r, int mid)
{
    int l_sz = mid - l + 1;
    int L[l_sz + 1];
    for (int i = 0; i < l_sz; i++)
    {
        L[i] = a[i + l];
    }
    int r_sz = r - mid;
    int R[r_sz + 1];
    for (int i = 0; i < r_sz; i++)
    {
        R[i] = a[mid + 1 + i];
    }
    L[l_sz] = 999999999;
    R[r_sz] = 999999999;
    int l_i = 0, r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[l_i] > R[r_i])
        {
            a[i] = R[r_i];
            r_i++;
        }
        else
        {
            a[i] = L[l_i];
            l_i++;
        }
    }
}
void merge_sort(int a[], int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, r, mid);
}
int main()
{
    int n = 7;
    int err[7] = {5, 7, 2, 9, 1, 6, 3};
    merge_sort(err, 0, n - 1);
    printf("merge sort array is:\n");
    print_array(err, n);
    return 0;
}