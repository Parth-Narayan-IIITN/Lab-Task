#include <stdio.h>
int main(){
    // Defining the array elements
    int n;
    printf("Enter the n: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count=0;
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
        j--;
        count++;
    }
    printf("Number of Inversions: %d\n",count);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


    return 0;
}