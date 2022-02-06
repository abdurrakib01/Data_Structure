#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
    int num;
    struct test *add;
    struct test *pre;

}test;
test *head, *top;
void PUSH(int x)
{
    test *ptr;
    ptr = (test*)malloc(sizeof(test));
    ptr->num = x;
    ptr->add = NULL;
    ptr->pre = NULL;
    if(head==NULL)
    {
        head=ptr;
        top=ptr;
        return;
    }
    test *temp=head;
    while(temp->add!=NULL)
    {
        temp=temp->add;
    }
    temp->add=ptr;
    ptr->pre=temp;
    top=ptr;


}
void POP()
{
    test *del;
    if(top==NULL)
    {
        printf("the stack is empty");
        return;
    }
    del=top;
    del->pre->add=NULL;
    top=del->pre;
    free(del);
}
void print()
{
    test*temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->num);
        temp=temp->add;
    }

}
int main()
{
    PUSH(1);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    print();
    printf("After using pop function!\n");
    POP();
    print();
    return 0;
}
