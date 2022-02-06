#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
    char id;
    struct test *add;
}test;
test *head;
void at(char a)
{
    test *ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    ptr->add=head;
    head=ptr;
}
void del_by_pos(int a)
{
    test *temp=head, *out;
    if(a==1)
    {
        out=head;
        head=head->add;
        free(out);
        return;
    }
    a=a-2;
    while(a--)
    {
        temp=temp->add;
    }
    out=temp->add;
    temp->add=out->add;
    free(out);
}
void del_by_value(int value)
{
    test *temp=head,*out;
    if(value==head->id)
    {
        out=head;
        head=head->add;
        free(out);
        return;
    }
    while(temp->add->id!=value)
    {
        temp=temp->add;
    }
    out=temp->add;
    temp->add=out->add;
    free(out);
}

void print()
{
    test*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->id);
        temp=temp->add;
    }
}
int main()
{
    at('x');
    at('3');
    at('d');
    at('5');
    at('a');
    del_by_pos(4);
    print();
}
