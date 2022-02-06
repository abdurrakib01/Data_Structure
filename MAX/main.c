#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
    int no;
    struct test *add;
}test;
test*head;
void at_end(int a)
{
    test*ptr;
    ptr=(test*)malloc(sizeof(test));
    ptr->no=a;
    ptr->add=NULL;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    test*temp=head;
    while(temp->add!=NULL)
    {
        temp=temp->add;
    }
    temp->add=ptr;
}
void MAX()
{

    test*temp=head;
    int m=temp->no;
    while(temp!=NULL)
    {
        if((temp->no)>(m))
        {
            m=temp->no;
        }
        temp=temp->add;
    }
    printf("\nmax is %d",m);

}
void print()
{
    test*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->no);
        temp=temp->add;
    }
}
int main()
{
    at_end(60);
    at_end(5);
    at_end(20);
    at_end(10);
    at_end(1);
    print();

    MAX();
}
