#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node*next;
}node;
int rear=-1,front=-1;
struct node*enqueue(struct node*head){
    struct node*temp=head;
    int x;
    printf("Enter the value: ");
    scanf("%d",&x);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=x;
    if(head==NULL){
        head=newnode;
        temp=head;
        rear++;
        front++;
    }else{
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newnode;
        rear++;
    }
    return head;
}

struct node*dequeue(struct node*head){
    if(front>rear){
        printf("Their is no element to be deleted");
        return NULL;
    }
    struct node*temp=head;
    head=head->next;
    front++;
    return head;
}
void display(struct node*head){
    node*temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    struct node*head=NULL;
    bool check=true;
    printf("1-enqueue\n2-dequeue\n3-display\n0-To exit progam\n");
    while(check){
        int choice;
        printf("Enter the number of that operation:");
        scanf("%d",&choice);
        switch(choice){
            case 0: check=false;
                    printf("Progarm end here");
                    break;
            case 1: 
                    // head =enqueue(head,count);
                    head=enqueue(head);
                    break;
            case 2: //head =dequeue(head);
                    head=dequeue(head);
                    break;
            case 3: display(head);
                    break;        
        }
    }
}