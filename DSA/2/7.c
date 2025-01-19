# include<stdio.h>
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
    printf("Enter the number needed:");
    int num,max=-100000,index=-1;
    scanf("%d",&num);
    while(num--){
        for(int j=0;j<n;j++){
            if(arr[j]>=max){
                max=arr[j];
                index=j;
            }
        }
        if(num){
            arr[index]=-10000;
            max=-10;
        }
    }
    printf("\n%d",max);

    return 0;
} 