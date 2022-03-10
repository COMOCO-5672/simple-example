#include <setjmp.h>
#include <stdio.h>
jmp_buf buf;

void banana()
{
    printf("in banana() \n");
    longjmp(buf, 1);
    printf("you'll never see this,because i longjmp'd");
}

int main()
{
    if (setjmp(buf))
    {
        printf("back in main\n");
    }
    else
    {
        printf("first time through\n");
        banana();
    }
}