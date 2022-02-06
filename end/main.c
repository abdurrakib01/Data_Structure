#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    test*node=head;
    if(head==NULL)
    {
        head=ptr;
    }
    else{
        while(node->add!=NULL)
        {
            node=node->add;
        }
        node->add=ptr;
    }

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
    a-=2;
    while(a--)
    {
        temp=temp->add;

    }
    out=temp->add;
    temp->add=out->add;
    free(out);

}
void del_by_val(int a)
{
    test *temp=head, *out;
    int x=0;
    while(temp->no!=a)
    {
        x+=1;
    }
     if(x==1)
    {
        out=head;
        head=head->add;
        free(out);
        return;
    }
    x-=2;
    while(x--)
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
        printf("%d ",temp->no);
        temp=temp->add;
    }
}


int main()
{
  at_end(2);
  at_end(3);
  at_end(4);
  at_end(5);
  del_by_val(4);


  print();
}
