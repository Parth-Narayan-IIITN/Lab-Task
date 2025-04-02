#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prv;
};
struct node*convert(struct node*head,int arr[]){
    struct node*temp=head;
    for(int i=0;i<9;i++){
        struct node*nnode=(struct node*)malloc(sizeof(struct node));
        nnode->data=arr[i];
        nnode->next=NULL;
        if(head==NULL){
            head=nnode;
            temp=nnode;
        }
        else{  
            temp->next=nnode;
            nnode->prv=temp;
            temp=nnode;
        }
    }
    return head;
}
void print(struct node*head){
    struct node*temp=head;
    while(temp){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main(){
    int arr[9]={1,2,3,4,5,6,7,8,9};
    struct node*head=NULL;
    head=convert(head,arr);
    print(head);
}