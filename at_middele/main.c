#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct test
{
    int id;
    struct test *add;
}test;
test*head;
void at_middle(int a,int n)
{
    test *ptr;
    ptr=(test*)malloc(sizeof(test));
    ptr->id=a;
    ptr->add=NULL;

    test*temp=head;
    if(n==1){
        head=ptr;
    }
    else{
    n=n-2;
    while(n--)
    {
        temp=temp->add;
    }
    ptr->add=temp->add;
    temp->add=ptr;}

}
void print()
{
    test *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->id);
        temp=temp->add;
    }
}

int main()
{

     at_middle(1,1);
     at_middle(2,2);
     at_middle(3,3);

    print();
}
