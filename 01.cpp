#include<stdio.h>
#include"Tree.h"

int main()
{
    SearchTree T = NULL;
    MakeEmpty(T);

    T = Insert(10, T);
    T = Insert(100, T);
    T = Insert(1000, T);
    T = Insert(20, T);
	T = Insert(30, T);

	printf("最大值: %d\n", FindMax(T)->Element);
    printf("最小值: %d\n", FindMin(T)->Element);

    printf("前序遍历二叉树: \n");
    PreorderTravel(T);

    printf("中序遍历二叉树: \n");
    InorderTravel(T);

    printf("后序遍历二叉树: \n");
    PostorderTravel(T);
    
    return 0;
}

