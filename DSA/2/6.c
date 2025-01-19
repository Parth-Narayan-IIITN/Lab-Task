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

    for(int i=0;i<n;i++){
        if(arr[i]==-50){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
                arr[j]=-50;
            }
        }
        printf("%d ",arr[i]);
    }
    return 0;
}