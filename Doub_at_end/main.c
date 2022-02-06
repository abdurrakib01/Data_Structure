#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
    int id;
    struct test *add;
    struct test *pre;
}test;
test *head, *tail;

void at_end(int a)
{
    test *ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    ptr->pre=NULL;
    if(head==NULL)
    {
        head=ptr;
        tail=ptr;
        return;
    }
    test *temp=head;
    while(temp->add!=NULL)
    {
        temp=temp->add;
    }
    temp->add=ptr;
    ptr->pre=temp;
    tail=ptr;
}
void print()
{
    test *temp=head;
    test *temp1=tail;
    while(temp!=NULL)
    {
        printf("%d ",temp->id);
        temp=temp->add;
    }
    printf("\n");
    while(temp1!=NULL)
    {
        printf("%d ",temp1->id);
        temp1=temp1->pre;
    }
}

int main()
{
    at_end(1);
    at_end(2);
    at_end(3);
    print();
    return 0;
}
