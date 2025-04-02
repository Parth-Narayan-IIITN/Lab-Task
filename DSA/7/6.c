# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h> 
struct node{
    int data;
    struct node*next;
};
struct node*convert(struct node*head,int arr[],int n){
    struct node*temp=head;
    for(int i=0;i<n;i++){
        struct node*nnode=(struct node*)malloc(sizeof(struct node));
        nnode->data=arr[i];
        nnode->next=NULL;
        if(head==NULL){
            head=nnode;
            temp=head;
        }else{
            temp->next=nnode;
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
    printf("NULL\n\n");
}

struct node*merge(struct node*head1,struct node*head2){
    struct node*temp=head1;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
}
int main(){
    int arr[]={1,2,3,4,5};
    int brr[]={6,7,8,9};
    
    struct node*head1=NULL;
    head1=convert(head1,arr,5);
    print(head1);

    struct node*head2=NULL;
    head2=convert(head2,brr,4);
    print(head2);

    head1=merge(head1,head2);
    print(head1);
}