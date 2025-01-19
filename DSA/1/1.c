#include <stdio.h>

void addition(int* arr, int index, int insert, int size) {
    for (int i = size; i > index; i--)
        *(arr + i) = *(arr + i - 1);
    *(arr + index) = insert;
}

void delete(int* arr, int index, int size) {
    for (int i = index; i < --size; i++)
        *(arr + i) = *(arr + i + 1);
}

void display(int* arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d\n", *(arr + i));
}

void reverse(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = temp;
    }
}

void sorting(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void do_shift(int* arr, int size) {
    int temp = *(arr + size - 1);
    for (int i = size - 1; i > 0; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + 0) = temp;
}

int main() {
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);
    int arr[size+2];
    printf("Enter elements:");
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    int choice, index, insert;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Display the array\n");
        printf("4. Reverse the array\n");
        printf("5. Sort the array\n");
        printf("6. Shift the array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index to add: ");
                scanf("%d", &index);
                printf("Enter element to add: ");
                scanf("%d", &insert);
                addition(arr, index, insert, size);
                size++;
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                delete(arr, index, size);
                size--;
                break;
            case 3:
                printf("Array elements:\n");
                display(arr, size);
                break;
            case 4:
                reverse(arr, size);
                printf("Array reversed.\n");
                break;
            case 5:
                sorting(arr, size);
                printf("Array sorted.\n");
                break;
            case 6:
                do_shift(arr, size);
                printf("Array shifted.\n");
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}