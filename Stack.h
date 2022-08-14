#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);//����Ƿ�Ϊ��ջ
int IsFull(Stack S);//����Ƿ���ջ
Stack CreateStack(int MaxElements);//�����µ�ջ
void DisposeStack(Stack S);//�ͷ�ջ
void MakeEmpty(Stack S);//������ջ
void Push(ElementType X, Stack S);//��ջ
ElementType Top(Stack S);//����ջ��
void Pop(Stack S);//��ջ
ElementType TopAndPop(Stack S);//����ջ��Ԫ�ز���ջ�е���

#define EmptyTOS -1
#define MinSrackSize 5

Stack CreateStack(int MaxElements)
{
	Stack S;

	if (MaxElements < MinSrackSize) printf("Error!");
	S = (Stack)malloc(sizeof(struct StackRecord));
	if (S == NULL) printf("Out of space!");
	S->Array = (int *)malloc(sizeof(ElementType) * MaxElements);
	if (S->Array == NULL) printf("Out of space!");
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S)) printf("Full stack!");
	else S->Array[++S->TopOfStack] = X;
}

ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S)) return S->Array[S->TopOfStack--];
	printf("Empty!");
	return 0; 
}

void Pop(Stack S) 
{
	if (IsEmpty(S)) printf("Empty!");
	else S->TopOfStack--;
}

ElementType Top(Stack S) 
{
	if (IsEmpty(S)) printf("Empty!");
	else return S->Array[S->TopOfStack];
}
