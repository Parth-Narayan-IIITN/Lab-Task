#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int wait_number;
    struct node*next;
    char name[50];
}node;
node*rear=NULL,*front=NULL;
// node*enqueue(node*head,int k){
    // node*temp=head;
void enqueue(int k){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the name:");
    scanf("%s", &newnode->name);
    newnode->wait_number=k;
    newnode->next=NULL;
    if(rear==NULL){
        rear++;
        front++;
        rear=newnode;
        front=newnode;
    }
    rear->next=newnode;
    rear=newnode;
    // if(head==NULL){
    //     head=newnode;
    //     temp=head;
    // }else{
    //     while(temp->next){
    //         temp=temp->next;
    //     }
    //     temp->next=newnode;
    // }
    // return head;
}
// node*dequeue(node*head){
//     if(head==NULL){
//         return NULL;
//     }else if(head->next==NULL){
//         return NULL;
//     }
void dequeue(){
    if(rear==NULL || front==NULL){
        printf("There is no patient");
        rear= NULL;
        front=NULL;
    }
    else{
        node*temp=front;
        front=front->next;
        temp->next=NULL;
        free(temp);
        node*temp1=front;
        while(temp1){
            temp1->wait_number-=1;
            temp1=temp1->next;
        }
    }
    //     node*temp=head;
    //     head=head->next;
    //     temp->next=NULL;
    //     free(temp);
    //     node*temp1=head;
    //     while(temp1){
    //         temp1->wait_number-=1;
    //         temp1=temp1->next;
    //     }
    
    // return head;
}
// display(node *head){
void display(){
    node*temp=front;
    if(front==NULL){
        printf("Their is no patient");
    }else{
        while(temp){
            printf("Name:%s\n",temp->name);
            printf("Waiting Number: %d\n",temp->wait_number);
            temp=temp->next;
        }
    }
    
}
int main(){
    bool check=true;
    // struct node*head=NULL;
    int count=0;
    printf("1-enqueue\n2-dequeue\n3-display\n0-To exit progam\n");
    while(check){
        int choice;
        printf("Enter the number of that operation:");
        scanf("%d",&choice);
        switch(choice){
            case 0: check=false;
                    printf("Progarm end here");
                    break;
            case 1: count++;
                    // head =enqueue(head,count);
                    enqueue(count);
                    break;
            case 2: //head =dequeue(head);
                    dequeue();
                    count--;
                    break;
            case 3: display();
                    break;        
        }
    }
}