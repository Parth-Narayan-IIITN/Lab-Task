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
    printf("\n");
    int brr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&brr[i][j]);
        }
    }
    int crr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            crr[i][j]=0;
        }
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            sum=(arr[i][j]*brr[1][1])+
            (arr[i][j-1]*brr[1][0])+
            (arr[i][j+1]*brr[1][2])+
            (arr[i-1][j-1]*brr[0][0])+
            (arr[i-1][j]*brr[0][1])+
            (arr[i-1][j+1]*brr[0][2])+
            (arr[i+1][j-1]*brr[2][0])+
            (arr[i+1][j]*brr[2][1])+
            (arr[i+1][j+1]*brr[2][2]);
        sum=sum/9;
        crr[i][j]=sum;
        sum=0;
        }
    }
    printf("\nNew array is\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",crr[i][j]);
        }
        printf("\n");
    }
    return 0;
}