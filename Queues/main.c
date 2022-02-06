#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
    int a;
    struct test *add;
}test;
test *head;
void inqueues(int x)
{
    test *ptr;
    ptr = (test*)malloc(sizeof(test));
    ptr->a=x;
    ptr->add=NULL;
    if(head == NULL)
    {
        head=ptr;
        return;
    }
    test *temp=head;
    while (temp->add!=NULL)
    {
        temp=temp->add;
    }
    temp->add= ptr;
}
int dequeues()
{
    test*temp=head;
    if(head == NULL)
    {
        printf("Queues is empty");
        return;
    }
    test*del;
    del=temp;
    head=temp->add;
    free(del);
}
void print()
{
    test *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->a) ;
        temp=temp->add;
    }

}


int main()
{
     inqueues(7);
     inqueues(5);
     inqueues(3);
     inqueues(2);
     inqueues(1);
     dequeues();
     print();

}

