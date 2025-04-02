#include <stdio.h>
#include<stdlib.h>
int top=-1;
const int n=8;
int arr[8];
void push(int x){
    if(top<n-1){
        top++;
        arr[top]=x;
    }else{
        printf("stack overflow \n");
    }
}
void pop(){
    if(top!=-1){
        top--;
    }else{
        printf("Their is no element to remove \n");
    }
}
void display(){
    if(top==-1){
        printf("There is no element in the array \n");
    }else{
        for(int i=0;i<=top;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
int main(){
    int m=1;
    while(m){
        int option;
        printf("0-Stop the function\n1-Push\n2-pop\n3-display\nEnter:");
        scanf("%d",&option);
        switch(option){
            case 1 :printf("Enter the number to be pushed in the array");
                    int k;
                    scanf("%d",&k);
                    push(k);
                    break;
            case 2 :pop();
                    break;
            case 3: display();
                    break;
            case 0: m=0;
                    break;
        }
    }
}