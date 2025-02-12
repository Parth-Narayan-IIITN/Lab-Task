#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void transverse(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element is : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node* insertFirst(struct Node *head,int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=head;
    return ptr;
}

struct Node * insertATindex(struct Node *head,int data,int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    
    struct Node* p = head;
    int i=0;

    while(i!=index-1){
        p=p->next;
        i++;
    }

    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct Node* insertATend(struct Node *head,int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node* p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct Node* insertAfterNode(struct Node *head,struct Node*prevNode,int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}

int main(){
    struct Node*head;
    struct Node*second;
    struct Node*third;

    // linked list memory allocated in heap
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head-> data=44;
    head->next=second;

    second-> data=4;
    second->next=third;
    
    third-> data=84;
    third->next=NULL;

    head=insertFirst(head,56);

    head=insertATindex(head , 88,3);

    head=insertATend(head,666);

    // head=insertAfterNode(head,second,91);
    transverse(head);
    return 0;
}