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

void del_by_value(int value)
{
    test*temp=head,*del;
    if(head->id==value)
    {
        del=head;
        head=head->add;
        head->pre=NULL;
        free(del);
        return;
    }

    if(tail->id==value)
    {
        del=tail;
        del->pre->add=NULL;
        tail=del->pre;
        free(del);
        return;
    }
    while(temp->add->id!=value)
    {
        temp=temp->add;
    }
    del=temp->add;
    temp->add=del->add;
    del->add->pre=temp;
    free(del);
}
void del_by_pos(int p)
{
    test*temp=head, *del;
    if(p==1)
    {
        del=head;
        head=head->add;
        head->pre=NULL;
        free(del);
        return;
    }

    p-=2;
    while(p--)
    {
        temp=temp->add;
    }
    if(temp->add->id==tail->id)
    {
        del=tail;
        del->pre->add=NULL;
        tail=del->pre;
        free(del);
        return;
    }
    del=temp->add;
    temp->add=del->add;
    del->add->pre=temp;
    free(del);
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
    at_end(4);
    at_end(5);
    at_end(6);
    del_by_pos(3);

    print();

}
