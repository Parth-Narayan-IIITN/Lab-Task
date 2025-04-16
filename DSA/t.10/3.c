#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int arr[6];
int rear=-1,front=-1;
void enqueue(){
    if(rear==-1){
        front++;
        rear++;
    }
    if(front==(rear+1)%6){
        printf("arr is full\n");
        return;
    }
    int x;
    printf("Enter thhe number:\n");
    scanf("%d",&x);

    arr[rear++]=x;
    rear=rear%6;
}
void dequeue(){
    if((front+1)%6>rear){
        printf("Their is no element to be deleted");
        return;
    }
    front++;
    front=front%6;
}
void display(){

    int i=front;
    while(i!=rear){
        printf("%d ",arr[i]);
        i++;
        i=i%6;
    }
    printf("\n");
}
int main(){
    bool check=true;
    printf("1-enqueue\n2-dequeue\n3-display\n0-To exit progam\n");
    while(check){
        int choice;
        printf("Enter the number of that operation:");
        scanf("%d",&choice);
        switch(choice){
            // case 0: check=false;
            //         printf("Progarm end here");
            //         break;
            case 1: 
                    // head =enqueue(head,count);
                    enqueue();
                    break;
            case 2: //head =dequeue(head);
                    dequeue();
                    break;
            case 3: display();
                    break;        
        }
    }
}