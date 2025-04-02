#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prv;
};

struct node*push(struct node*head,int x){
    struct node*nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=x;
    nnode->next=NULL;
    nnode->prv=NULL;
    if(head==NULL){
        head=nnode;
    }else{
        nnode->next=head;
        head->prv=nnode;
        head=nnode;
    }
    return head;
}
struct node*pop(struct node*head){
    if(head==NULL){
        printf("There is no element to remove from the doubly link list\n");
    }
    else if(head->next==NULL){
        struct node*temp=head;
        head=NULL;
        free(temp);
    }
    else{
        struct node*temp=head;
        head=head->next;
        temp->next=NULL;
        head->prv=NULL;
        free(temp);
    }
    return head;
}
void display(struct node*head){
    if(head==NULL){
        printf("There is no element in the link list \n");
    }else{
        struct node*temp=head;
        while(temp){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
    struct node*head=NULL;
    int m=1;
    while(m){
        int option;
        printf("0-Stop the function\n1-Push\n2-pop\n3-display\nEnter:");
        scanf("%d",&option);
        switch(option){
            case 1 :printf("Enter the number to be pushed in the doubly link list: ");
                    int k;
                    scanf("%d",&k);
                    head=push(head,k);
                    break;
            case 2 :head=pop(head);
                    break;
            case 3: display(head);
                    break;
            case 0: m=0;
                    break;
        }
    }
}