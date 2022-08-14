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

	printf("���ֵ: %d\n", FindMax(T)->Element);
    printf("��Сֵ: %d\n", FindMin(T)->Element);

    printf("ǰ�����������: \n");
    PreorderTravel(T);

    printf("�������������: \n");
    InorderTravel(T);

    printf("�������������: \n");
    PostorderTravel(T);
    
    return 0;
}

