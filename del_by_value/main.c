#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
    int id;
    struct test *add;

}test;
test *head;

void at_end(int a)
{
    test *ptr;
    ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    test*temp=head;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    else
    {
        while(temp->add!=NULL)
        {
            temp=temp->add;
        }
        temp->add=ptr;
    }
}
void at_nth(int a, int n)
{
    test *ptr;
    ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    test*temp=head;
    if(n==1)
    {
        ptr->add=head;
        head=ptr;
        return;
    }
    n=n-2;
    while (n--)
    {
        temp=temp->add;
    }
    ptr->add=temp->add;
    temp->add=ptr;

}

void by_val(int a, int value)
{

    test *ptr;
    ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    test*temp=head;
    while(temp->id!=value)
        {
           temp=temp->add;
        }
    ptr->add=temp->add;
    temp->add=ptr;


}
void insert_at_4th(int a,int b)
{

    test *temp = head;
    test *node = (test*)malloc(sizeof(test));
    node -> id = a;
    node -> add=NULL;


    b-=2;
    while(b--)
    {
        temp=temp->add;
    }
    node->add=temp->add;
    temp->add=node;
}
void print()
{
    test *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->id) ;
        temp=temp->add;

    }

}


int main()
{



     at_end(2);
     at_end(4);
     at_end(7);
     at_end(8);
     insert_at_4th(943,4);

     print();

}
