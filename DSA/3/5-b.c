#include <stdio.h>

// Counters for basic operations
int comp_count = 0;  // Number of comparisons
int swap_count = 0;  // Number of swaps

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}

int partition(int a[], int l, int h) {
    int pivot = a[l];
    int i = l, j = h;

    while (i < j) {
        while (i <= h && a[i] <= pivot) {
            comp_count++; // Counting comparisons
            i++;
        }
        while (a[j] > pivot) {
            comp_count++; // Counting comparisons
            j--;
        }
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            swap_count++;  // Counting swaps
        }
    }
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    swap_count++;  // Counting the final pivot swap
    return j;
}

void quick_sort(int a[], int l, int h) {
    if (l < h) {
        int j = partition(a, l, h);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, h);
    }
}

int main() {
    int n = 7;
    int err[7] = {1, 2, 3, 4, 5, 6, 7};

    quick_sort(err, 0, n - 1);

    printf("Quick sort array is:\n");
    print_array(err, n);

    // Print the counts of basic operations
    printf("Total comparisons: %d\n", comp_count);
    printf("Total swaps: %d\n", swap_count);

    return 0;
}