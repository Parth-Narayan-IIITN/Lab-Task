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

struct Node* deleteFirst(struct Node* head){
    struct Node *ptr= head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index){
    struct Node *p= head;
    struct Node *q= head->next;

    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node* deleteLast(struct Node* head){
    struct Node *p= head;
    struct Node *q= head->next;

    while(q->next !=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node* deleteTHEvalue(struct Node* head, int value){
    struct Node *p= head;
    struct Node *q= head->next;

    while(q->data=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next=q->next;
        free(q);
    }
    return head;
}

int main(){
    struct Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;

    // linked list memory allocated in heap
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head-> data=4;
    head->next=second;

    second-> data=3;
    second->next=third;
    
    third-> data=8;
    third->next=fourth;

    fourth->data=1;
    fourth->next=NULL;

    head=deleteAtIndex(head, 2);

    head=deleteFirst(head);

    // head=deleteAtIndex(head, 2);

    head= deleteLast(head);

    // head= deleteTHEvalue(head,8);
    transverse(head);
    return 0;
}