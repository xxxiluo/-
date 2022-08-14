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

int IsEmpty(Stack S);//检测是否为空栈
int IsFull(Stack S);//检测是否满栈
Stack CreateStack(int MaxElements);//创建新的栈
void DisposeStack(Stack S);//释放栈
void MakeEmpty(Stack S);//创建空栈
void Push(ElementType X, Stack S);//进栈
ElementType Top(Stack S);//返回栈顶
void Pop(Stack S);//出栈
ElementType TopAndPop(Stack S);//给出栈顶元素并从栈中弹出

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
