#include<stdio.h>
#include"Stack.h"

int main()
{
    Stack S = CreateStack(10);
    Push(1,S);
    Push(2,S);
	Push(3,S);
    printf("%d\n",Top(S));
    Pop(S);
    printf("%d\n",Top(S));

    DisposeStack(S);
    return 0;
}

