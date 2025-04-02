#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char arr[100],brr[100];
int top=-1;
void push(char c){
    if(top<99){
        top++;
        brr[top]=c;
    }
}
void pop(){
    if(top!=-1){
        top--;
    }
}
char top_emt(){
    if(top!=-1){
        return brr[top];
    }
}
int convert(){
    int k=(strlen(arr)+1)/2;
    for(int i=0;i<k;i++){
        push(arr[i]);
    }
    if(k%2==0){
        for(int i=k;i<strlen(arr);i++){
            if(top_emt()==arr[i])pop();
            else return 0;
        }
    }
    else{
        for(int i=k-1;i<strlen(arr);i++){
            if(top_emt()==arr[i])pop();
            else return 0;
        }
    }
    return 1;
}
int main(){
    printf("Enter the pallindrom: ");
    scanf("%s",arr);

    if (convert()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}