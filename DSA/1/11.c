#include <stdio.h>
#include <stdbool.h>

void insertValue(int* numbers, int position, int value, int* length) {
    for (int i = *length; i > position; i--) {
        numbers[i] = numbers[i - 1];
    }
    numbers[position] = value;
    (*length)++;
}

void removeValue(int* numbers, int position, int* length) {
    for (int i = position; i < *length - 1; i++) {
        numbers[i] = numbers[i + 1];
    }
    (*length)--;
}

void printNumbers(const int* numbers, int length) {
    printf("The array contains: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void reverseNumbers(int* numbers, int length) {
    for (int left = 0, right = length - 1; left < right; left++, right--) {
        int temp = numbers[left];
        numbers[left] = numbers[right];
        numbers[right] = temp;
    }
}

void sortNumbers(int* numbers, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void rotateNumbers(int* numbers, int length) {
    int last = numbers[length - 1];
    for (int i = length - 1; i > 0; i--) {
        numbers[i] = numbers[i - 1];
    }
    numbers[0] = last;
}

void displayMenu() {
    printf("\nOptions:\n");
    printf("1. Add a number\n");
    printf("2. Delete a number\n");
    printf("3. View the numbers\n");
    printf("4. Reverse the array\n");
    printf("5. Sort the array\n");
    printf("6. Rotate the array\n");
    printf("7. Quit\n");
    printf("Enter your choice: ");
}

int main() {
    int length;
    printf("Enter the number of elements: ");
    scanf("%d", &length);
    int numbers[length + 5];  // Allocate space for potential insertions
    printf("Enter the elements: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &numbers[i]);
    }

    bool isRunning = true;
    while (isRunning) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int pos, value;
            printf("Enter position to insert (0 to %d): ", length);
            scanf("%d", &pos);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            if (pos >= 0 && pos <= length) {
                insertValue(numbers, pos, value, &length);
                printf("Value inserted successfully.\n");
            } else {
                printf("Invalid position.\n");
            }
        } else if (choice == 2) {
            int pos;
            printf("Enter position to delete (0 to %d): ", length - 1);
            scanf("%d", &pos);
            if (pos >= 0 && pos < length) {
                removeValue(numbers, pos, &length);
                printf("Value removed successfully.\n");
            } else {
                printf("Invalid position.\n");
            }
        } else if (choice == 3) {
            printNumbers(numbers, length);
        } else if (choice == 4) {
            reverseNumbers(numbers, length);
            printf("Array reversed successfully.\n");
        } else if (choice == 5) {
            sortNumbers(numbers, length);
            printf("Array sorted successfully.\n");
        } else if (choice == 6) {
            rotateNumbers(numbers, length);
            printf("Array rotated successfully.\n");
        } else if (choice == 7) {
            isRunning = false;
            printf("Exiting program. Goodbye!\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}