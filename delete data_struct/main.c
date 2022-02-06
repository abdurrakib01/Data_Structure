#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
    int id;
    struct test *add;
}test;
test*head;
void at_first(int a)
{
    test*ptr;
    ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    ptr->add=head;
    head=ptr;

}
void del_pos(int n)
{
    test*temp=head, *out;
    if(n==1)
    {
        out=head;
        head=head->add;
        free(out);
        return;
    }
    n=n-2;
    while(n--)
    {
        temp=temp->add;
    }
    out=temp-add;
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
     at_first(1);
     at_first(2);
     at_first(3);
     at_first(4);
     del_pos(3);
     print();


}
