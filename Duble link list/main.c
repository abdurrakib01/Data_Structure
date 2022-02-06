#include <stdio.h>
#include <stdlib.h>

typedef struct test
{
    int id;
    struct test *add;
    struct test *pre;
}test;
test *head,*tail;
void at_first(int a)
{
    test*ptr;
    ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    ptr->pre=NULL;
    if(head==NULL)
    {
        head=ptr;
        tail=ptr;
        return;
    }
    ptr->add=head;
    head->pre=ptr;
    head=ptr;
}
void at_end(int a)
{
    test*ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    ptr->pre=NULL;
    if(head==NULL)
    {
        head=ptr;
        tail=ptr;
        return;
    }
    test*temp=head;
    while(temp->add!=NULL)
    {
        temp=temp->add;
    }
    temp->add=ptr;
    ptr->pre=temp;
    tail=ptr;
}
void at_nth(int a, int n)
{
    test*ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    ptr->pre=NULL;
    test*temp=head;
    if(n==1)
    {
        ptr->add=head;
        head->pre=ptr;
        head=ptr;
        return;
    }
    n-=2;
    while(n--)
    {
        temp=temp->add;
    }
    ptr->add=temp->add;
    temp->add->pre=ptr;
    temp->add=ptr;
    ptr->pre=temp;
}
void print()
{
    test*temp=head;
    while(temp!=NULL)
    {
        printf("%d ", temp->id);
        temp=temp->add;
    }
    printf("\n");
    test*ptr=tail;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->id);
        ptr=ptr->pre;
    }
}
int main()
{
    at_end(1);
    at_end(2);
    at_end(3);
    at_end(4);
    at_nth(0,1);
    print();

}
