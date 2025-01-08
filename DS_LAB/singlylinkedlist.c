#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node* next;
};
struct node* top=NULL;

void ibeg(int val){
        struct node* newnode=malloc(sizeof(struct node*));
        newnode->data=val;
        if(top==NULL){
                top=newnode;
                top->next=NULL;
                }
        else{
                newnode->next=top;
                top=newnode;
        }
        printf("%d is Inserted at the begnning\n",val);
}


void iend(int val){
        struct node* newnode=malloc(sizeof(struct node*));
        newnode->data=val;
        struct node* temp=top;
        newnode->next=NULL;
        if(top==NULL){
                top=newnode;
        }
        else{
                struct node* temp=top;
                while(temp->next != NULL){
                        temp=temp->next;
                }
                temp->next=newnode;
        }
        printf("%d is inserted into list!",val);
}

void ipos(int val,int position){ 
        struct node* temp=top;
        int count=1;
        if(position==1){
                        ibeg(val);
                }
        else{
                while(temp->next != NULL && count<position-1){
                        temp=temp->next;
                        count++;
                }
                if(temp->next==NULL){
                        iend(val);
                }
                else{
                        struct node* newnode=malloc(sizeof(struct node*));
                        newnode->data=val;
                        newnode->next=temp->next;
                        temp->next=newnode;
                        printf("%d is inserted into list!",val);
                }
        }
}


void display(){
        struct node* temp=top;
        if(top==NULL){
                printf("List is Empty!!");
                }
        else{
                printf("Elements in List is:\n");
                while(temp!=NULL){
                        printf("%d->",temp->data);
                        temp=temp->next;
                        }
                }
        }

void dbeg(){
        if(top==NULL){
                printf("List is Empty!! ");
        }
        else{
                struct node* temp=top;
                top=top->next;
                printf("%d is deleted from begnning of list!",temp->data);
                free(temp);
        }
}

void dend(){
        if(top==NULL){
                printf("List is Empty!");
        }
        else if(top->next==NULL){
                dbeg();
        }
        else{
                struct node* temp=top;
                while(temp->next->next != NULL){
                        temp=temp->next;
                }
                struct node* last=temp;
                temp=temp->next;
                printf("%d is deleted from end of the list",temp->data);
                free(temp);
                last->next=NULL;
        }
}

void dpos(int pos){
        if(top==NULL){
                printf("List is Empty!");
        }
        else if(pos==1){
                dbeg();
        }
        int count=1;
        struct node* temp=top;
        while(temp->next != NULL && count<pos-1){
                temp=temp->next;
        }
        if(temp->next==NULL){
                dend();
        }
        else{
                struct node* del=temp->next;
                temp->next=del->next;
                printf("%d is deleted from list",del->data);
                free(del);
        }
}

void main(){
        int val,position,choice,pos;
        while(1){
                printf("\n Choose an operation:\n 1.Isert at begning\n 2.Insert at the end\n 3. insert at random position\n 4.Deletion at Begnning\n 5.deletion at end\n 6.deletion at any position\n 7.Display\n 8.exit\n Enter you choice: \n");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("Enter the value to pushed at begining:");
                                scanf("%d",&val);
                                ibeg(val);
                                break;
                        case 2:
                                printf("Enter the value to pushed at end:");
                                scanf("%d",&val);
                                iend(val);
                                break;
                        case 3:
                                printf("Enter the position to insert: ");
                                scanf("%d",&position);
                                printf("Enter the value to be inserted: ");
                                scanf("%d",&val);
                                ipos(val,position);
                                break;
                        case 4:
                                dbeg();
                                break;
                        case 5:
                                dend();
                                break;
                        case 6:
                                printf("Enter the position to delete");
                                scanf("%d",&pos);
                                dpos(pos);
                                break;
                        case 7:
                                display();
                                break;
                        case 8:
                                exit(0);
                        }
                }
        }
