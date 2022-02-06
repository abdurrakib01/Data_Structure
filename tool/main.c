#include <stdio.h>
#include <stdlib.h>
typedef struct chadda
{
    int chadda;
    struct chadda *next;
}chadda;




int main(){

 chadda*head=(chadda*)malloc(sizeof(chadda));



    printf("Hello world!\n");
    return 0;
}
