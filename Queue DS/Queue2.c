#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int data;
    struct Queue *next;
}*front,*rear,*front1,*rear1;
void enqueue()
{
    struct Queue *ptr;
    ptr=(struct Queue*)malloc(sizeof(struct Queue));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(front==NULL)
        {
            front=rear=ptr;
        }
        else{
            rear->next=ptr;
            rear=ptr;
        }
        ptr->next=NULL;
    }
}
void veersingh(struct Queue *veer)
{
    if(veer==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Queue *ptr;
        for(ptr=veer;(ptr);ptr=ptr->next)
        {
            printf("\nData is %d",ptr->data);
        }
    }
}
void traverse()
{
    veersingh(front);
}
void dequeue()
{
    if(front==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Queue *prev;
        prev=front;
        front=front->next;
        free(prev);
        printf("\nDeleted!!");
    }
}
void copyQueue()
{
    struct Queue *temp;
    for(temp=front;(temp);temp=temp->next)
    {
        if(temp->data>0)
        {
            struct Queue *ptr;
            ptr=(struct Queue*)malloc(sizeof(struct Queue));
            if(ptr==NULL)
            {
                printf("\nCannot allocate memory!!");
                return;
            }
            ptr->data=temp->data;
            if(front1==NULL)
                front1=rear1=ptr;
            else{
                rear1->next=ptr;
                rear1=ptr;
            }
            ptr->next=NULL;
        }
    }
}
void cTraverse()
{
    veersingh(front1);
}
void main()
{
    front=rear=NULL;
    front1=rear1=NULL;
    int c;
    do{
        printf("\n1. Add new Node");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Copy Queue");
        printf("\n5. Traverse Copy Queue");
        printf("\n6. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            enqueue();
        else if(c==2)
            traverse();
        else if(c==3)
            dequeue();
        else if(c==4)
            copyQueue();
        else if(c==5)
            cTraverse();
    }while(c!=6);
}
