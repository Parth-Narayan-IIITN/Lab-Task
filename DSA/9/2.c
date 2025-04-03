# include <stdio.h>
# include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*element(struct node*head,int x){
    struct node*temp=head;
    struct node*nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=x;
    nnode->next=NULL;
    if(head==NULL){
        head=nnode;
    }else{
        while(temp->next){
            temp=temp->next;
        }
        temp->next=nnode;
    }
    return head;
}
void addition(struct node*head1,struct node*head2){
    struct node*temp1=head1;
    struct node*temp2=head2;
    while(temp1 || temp2){
        if(temp1 && temp2){
            printf("%d->",temp1->data+temp2->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }else if(!temp1 && temp2){
            printf("%d->",temp2->data);
            temp2=temp2->next;
        }
        else if(temp1 && !temp2){
            printf("%d->",temp1->data);
            temp1=temp1->next;
        }
    }
    printf("NULL");
}
int main(){
    int n;
    printf("No. of element in the first link list: ");
    scanf("%d",&n);
    printf("Enter the element of link list : ");
    struct node*head1=NULL;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        head1=element(head1,x);
    }
    printf("\n");

    int m;
    printf("No. of element in the second link list: ");
    scanf("%d",&m);
    printf("Enter the element of link list : ");
    struct node*head2=NULL;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        head2=element(head2,x);
    }
    printf("\n");
    addition(head1,head2);
}