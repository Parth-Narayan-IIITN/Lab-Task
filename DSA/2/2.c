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
    int brr[n];
    for(int i=0;i<n;i++){
        brr[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        int count=0,a=0;
        for(int j=0;j<n;j++){
            if(brr[j]==-50){
                continue;
            }
            else if(arr[i] == brr[j]){
                brr[j]=-50;
                count++,a=1;
            }    
        }
        if(a){
            printf("%d------%d\n",arr[i],count);
        }
    }
    return 0;
}