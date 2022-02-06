#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct test
{
    int id;
    char name[30];
    struct test *add;
    struct test *pre;
}test;
test *head,*tail;
void insert_at_end(int a,char str[30])
{
    test *ptr = (test*)malloc(sizeof(test));
    ptr->id=a;
    strcpy(ptr->name,str);
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

void insert_at_first(int a)
{
    test*ptr=(test*)malloc(sizeof(test));
    ptr->id= a;
    ptr->add= NULL;
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

void insert_at_nth(int n,int a)
{
    test*ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;
    if(n==1)
    {
        head=ptr;
        tail=ptr;
        return;
    }
    test*temp=head;
    n-=2;
    while(n--)
    {
        temp=temp->add;
    }
    if(temp->id==tail->id)
    {
        temp->add=ptr;
        ptr->pre=temp;
        tail=ptr;
        return;
    }
    ptr->add=temp->add;
    temp->add->pre=ptr;
    temp->add=ptr;
    ptr->pre=temp;

}

void delet_by_value(int a)
{
    test*temp=head;
    while(temp->id != a)
    {
        temp=temp->add;
    }
    test*del;
    if(temp->id==head->id)
    {
        del=head;
        head=temp->add;
        temp->add->pre=NULL;
        free(del);
        return;
    }
    if(temp->id==tail->id)
    {
        del=tail;
        temp->pre->add=NULL;
        tail=del->pre;
        return;
    }
    del=temp;
    temp->pre->add=del->add;
    del->add->pre=temp->pre;
    free(del);
}
void delete_by_pos(int n)
{
    test*temp=head,*del;
    if(n==1)
    {
        del=head;
        head=temp->add;
        temp->add->pre=NULL;
        free(del);
        return;
    }
    n-=2;
    while(n--)
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
    test*temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->id);
        temp=temp->add;
    }
}
void print1()
{
    test*temp;
    temp=tail;
    while(temp!=NULL)
    {
        printf("%d\n",temp->id);
        temp=temp->pre;
    }
}

int main()
{
    insert_at_first(2);
    insert_at_first(5);
    insert_at_first(6);
    insert_at_nth(4,3);
    delete_by_pos(4);
    print();
    print1();

    return 0;
}
