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
    //Defining he window
    int w;
    printf("window : ");
    scanf("%d",&w);
    float sum=0;
    // Printing the values
    for(int i=0;i<n;i++){
        if(i<w-1){
            sum+=arr[i];
            printf("%f\n",sum/(i+1));
        }
        else{
            sum=0;
            int x=i;
            int y=w;
            while(y--){
                sum+=arr[x];
                x--;
            }
            printf("%f\n",sum/(w));
        }
    }
    for(int i=n-w+1;i<n;i++){
        sum=0;
        int x=i;
        while(x<n){
        sum+=arr[x];
        x++;
        }
        printf("%f\n",sum/(--w));
    }
    return 0;
}