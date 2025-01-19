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
    // Bubble Sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    // New array to find frequency
    int drr[n];
    for(int i=0;i<n;i++){
        drr[i]=arr[i];
    }

    int brr[n],crr[n],x=0;
    for(int i=0;i<n;i++){
        int count=0,a=0;
        for(int j=i;j<n;j++){
            if(drr[j]==-50){
                continue;
            }
            else if(arr[i]==drr[j]){
                drr[j]=-50;
                count++;
                a=1;
            }  
        }
        // taking frq count and value in 2 different array
        if(a){
                brr[x]=count;
                crr[x]=arr[i];
                x++;
            }
    }
    // printf("\n");
    // for(int i=0;i<x;i++){
    //     printf("%d------ %d\n",crr[i],brr[i]);
    // }
    // printf("\n"); 
    for(int i=0;i<x-1;i++){//Reshuffling them
        for(int j=0;j<x-1;j++){
            if(brr[j]>brr[j+1]){
                int temp = brr[j];
                brr[j] = brr[j+1];
                brr[j+1] = temp;

                int temp1=crr[j];
                crr[j]=crr[j+1];
                crr[j+1]=temp1;
            }
        }
    }

    // for(int i=0;i<x;i++){
    // printf("%d------ %d\n",crr[i],brr[i]);
    // }
    // printf("\n");
    printf("Array is:\n");
    for(int i=0;i<x;i++){
        while(brr[i]--){
            printf("%d\n",crr[i]);
        }
    }
    return 0;
}