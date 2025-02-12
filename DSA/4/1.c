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

    transverse(head);
    return 0;
}