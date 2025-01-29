#include<stdio.h>
int main(){
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    int arr[n][n];
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int brr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j]=0;
        }
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            sum=arr[i][j]+
            arr[i][j-1]+
            arr[i][j+1]+
            arr[i-1][j-1]+
            arr[i-1][j]+
            arr[i-1][j+1]+
            arr[i+1][j-1]+
            arr[i+1][j]+
            arr[i+1][j+1];
        sum=sum/9;
        brr[i][j]=sum;
       sum=0; }
    }
    printf("\nNew array is\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",brr[i][j]);
        }
        printf("\n");
    }
    return 0;
}