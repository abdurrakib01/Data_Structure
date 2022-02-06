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
test *head, *tail;
void at_end(int a, char str[30])
{
    test *ptr=(test*)malloc(sizeof(test));
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
        printf("%d-%s\n",temp->id,temp->name);
        temp=temp->add;
    }
    printf("\n");
    while(temp1!=NULL)
    {
        printf("%d-%s ",temp1->id,temp1->name);
        temp1=temp1->pre;
    }
}

int main()
{

    at_end(1001,"abdur");
    at_end(1002,"rakib");

    print();
    return 0;
}
