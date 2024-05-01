#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
void insert(int e)
{
    struct node *t;
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next=NULL;
        head->prev=NULL;
    }
    else
    {
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }

        t->next=(struct node*)malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=NULL;
        t->next->prev=t;
    }
}
void display()
{
    struct node *t;
    if(head==NULL)
    {
        printf("DLL is Empty");
    }
    else
    {
        t=head;
        printf("\n");
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t=t->next;
        }
    }
}
void delete(int e)
{
    struct node *t;
    if(head==NULL)
    {

        printf("Doubly Linked List is Empty");

    }
    else if(head->data == e && head->next==NULL)
    {
        head=NULL;
    }
    else if(head->data==e)
    {
        head=head->next;
        head->prev=NULL;
    }
    else
    {
        t=head->next;
        while(t!=NULL && t->data!=e)
        {
            t=t->next;
        }
        if(t==NULL)
        {
            printf("Element not found");
        }
        else if(t->next == NULL)
        {
            t->prev->next=NULL;
        }
        else
        {
            t->prev->next=t->next;

            t->next->prev=t->prev;
        }
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    delete(20);
    display();
    delete(100);
    display();
    delete(10);
    display();
    delete(30);
    display();
    return 0;
}
