#include<stdio.h>
#include<stdlib.h>

#define size 10
int front=-1;
int rear=-1;
int cqueue[size];

int isfull(int max){
    return (rear+1)%max==front;
}
int isempty(){
    return front==-1;
}
void display(int max){
    if(isempty()){
        printf("circular queue is empty");
    }
    else{
        printf("Queue elements are: ");
        int i=front;
        while(i!=rear){
            printf("%d->",cqueue[i]);
            i=(i+1)%max;    
        }
        printf("%d",cqueue[rear]);
    }
}
void enque(int value,int max){
    if(isfull(max)){
        printf("circular Queue is full");
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        cqueue[rear]=value;
    }
    else{
        rear=(rear+1)%max;
        cqueue[rear]=value;
        display(max);
    }
}
void deque(int max){
    if(isempty()){
        printf("circular queue is empty");
    }
    else if(front==rear){
        printf("%d is deleted..",cqueue[rear]);
        front=-1;
        rear=-1;
    }else{
         printf("%d is deleted..",cqueue[front]); 
         front=(front+1)%max;
    }
}
void search(int value){
    if(isempty()){
        printf("circular queue is empty");
    }
    else{
        int pos=0;
        int i=front;
        while(i!=rear){
            if(cqueue[i]==value){
                printf("%d is found at %d",value,pos);
            }else{
                i=i+1;
                pos=pos+1;
            }
        }
        if(cqueue[rear]==value){
            printf("%d is found at %d",value,pos);
        }else{
        printf("Element not found");
        }
    }
    
}


int main(){
    int max,ch,value;
    printf("Enter the size of circular Queue: ");
    scanf("%d",&max);
    do{
        printf(" \n 1.Enque \n 2.Deque \n 3.Display \n 4.Search \n 5.exit \n Enter Your Choice: ");
        scanf("%d",&ch);
         switch(ch){
                        case 1:
                                printf("Enter the value to be Inserted: ");
                                scanf("%d",&value);
                                enque(value,max);
                                break;
                        case 2:
                                deque(max);
                                break;
                        case 3:
                                display(max);
                                break;
                        case 4:
                                printf("Enter the value to Search: ");
                                scanf("%d",&value);
                                search(value);
                                break;
                        case 5:
                                printf("Exiting the program..!!");
                                exit(0);
                        }
        
    }while(1);
    
}
