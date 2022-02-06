#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
    int id;
    char name;
    struct test *add;
}test;
test *head;
void at_first(char ch)
{
    test *ptr;
    ptr=(test*)malloc(sizeof(test));

    ptr->name=ch;
    ptr->add=NULL;
    ptr->add=head;
    head=ptr;

}
void print()
{
    test *temp=head;
    while(temp!=NULL)
    {
        printf("%c ",temp->name) ;
        temp=temp->add;
    }

}


int main()
{
     at_first('a');
     at_first('5');
     print();

}
