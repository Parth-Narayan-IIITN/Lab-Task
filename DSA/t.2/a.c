# include <stdio.h>
# include<stdbool.h>
int main(){
    int n;
    scanf("%d",&n);
    int brr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&brr[i]);
    }

    for (int i = 0; i < (n)/2; i++)
    {
        int max = 99999999, a;
        int min=-1,b;
        for (int j = i; j < n-i; j++)
        {
            if (brr[j] < max)
            {
                max = brr[j];
                a = j;
            }
            if(brr[j]>min){
                min=brr[j];
                b=j;
            }
        }
        int temp = brr[i];
        brr[i] = brr[a];
        brr[a] = temp;

        int temp1 = brr[n-i-1];
        brr[n-i-1] = brr[b];
        brr[b] = temp1;
    }

    for(int i=0;i<n;i++){
        printf("%d ",brr[i]);
    }

    return 0;
}