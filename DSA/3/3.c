#include<stdio.h>
int crr[9];
void zero_all_elements(int crr[]){
    for(int i=0;i<9;i++){
        (crr[i])=0;
    }
}
void merge(int l,int r,int mid){
    int l_sz=mid-l+1;
    int L[l_sz+1];
    int r_sz=r-mid;
    int R[r_sz+1];
    for(int i=0;i<l_sz;i++){
        L[i]=crr[i+l];
    }
    for(int i=0;i<r_sz;i++){
        R[i]=crr[i+mid+1];
    }
    L[l_sz]=999999999;
    R[r_sz]=999999999;
    int l_i=0;
    int r_i=0;
    for(int i=l;i<=r;++i){
        if(L[l_i]<=R[r_i]){
            crr[i]=L[l_i];
            l_i++;
        }
        else{
            crr[i]=R[r_i];
            r_i++;
        }
    }
}
int median(int p,int q){
    int o=(p+q)/2;
    if(q%2==0){
        return crr[o];
    }
    else{
        return (crr[o]+crr[o+1])/2;
    }
}
int merge_sort(int l,int r){
    if(l==r) return 1;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,r,mid);
    int med = median(0,8);
    return med;
}
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

    zero_all_elements(crr);
    printf("\n");
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            crr[0]=arr[i-1][j-1];
            crr[1]=arr[i-1][j];
            crr[2]=arr[i-1][j+1];
            crr[3]=arr[i][j-1];
            crr[4]=arr[i][j];
            crr[5]=arr[i][j+1];
            crr[6]=arr[i+1][j-1];
            crr[7]=arr[i+1][j];
            crr[8]=arr[i+1][j+1];

            brr[i][j]= merge_sort(0,8);
            zero_all_elements(crr);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",brr[i][j]);
        }
        printf("\n");
    }
    return 0;
}