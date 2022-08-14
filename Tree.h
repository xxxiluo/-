#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty( SearchTree T );//令树为空
Position Find( ElementType X, SearchTree T );//查找X所在的结点
Position FindMin( SearchTree T );//查找最小的结点
Position FindMax( SearchTree T );//查找最大的结点
SearchTree Insert( ElementType X, SearchTree T );//插入新结点
SearchTree Delete( ElementType X, SearchTree T );//删除X所在结点
ElementType Retrieve( Position P );//返回该结点的值
void PreorderTravel(SearchTree T);//前序遍历
void InorderTravel(SearchTree T);//中序遍历
void PostorderTravel(SearchTree T);//后序遍历
void printTree(SearchTree  T,int level);//打印树
void printfTree(SearchTree *T, int type,  int level);

typedef int Status;

struct TreeNode
{
    ElementType Element;
    SearchTree Left;    
    SearchTree Right;   
};

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if( T == NULL )    
        return NULL;
    if (X < T->Element ) 
        return Find(X, T->Left);
    else
    if (X > T->Element)  
        return Find(X, T->Right);
    else
        return T; 
}

Position FindMin(SearchTree T)
{
    if ( T == NULL )
        return NULL;
    else
    if ( T-> Left == NULL )
        return T;
    else
        return FindMin( T->Left );
}

Position FindMax(SearchTree T)
{
    if ( T != NULL )
        while(T->Right != NULL)
            T = T->Right;
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        T =(struct TreeNode*) malloc(sizeof( struct TreeNode ));
        if ( T == NULL )
            printf("Out of space!!!\n");
        else
        {
            T->Element = X; 
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)   
        T->Right = Insert(X, T->Right);

    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if (T == NULL)
        printf("Element not found\n");

    else if (X < T->Element)  
        T->Right = Delete(X, T->Left);

    else if (X > T->Element) 
        T->Right = Delete(X, T->Left);
    
    else if (T->Left && T->Right) 
    {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else
    {
        TmpCell = T;

        if (T->Left == NULL) 
            T = T->Right;
       
        else if (T->Right == NULL)
            T = T->Left;
        free( TmpCell );
    }

    return T;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void PreorderTravel(SearchTree T)
{
    if (T != NULL)
    {
        printf("%d\n", T->Element);
        PreorderTravel(T->Left);
        PreorderTravel(T->Right);
    }
}

void InorderTravel(SearchTree T)
{
    if (T != NULL)
    {
        InorderTravel(T->Left);
        printf("%d\n", T->Element);
        InorderTravel(T->Right);
    }
}

void PostorderTravel(SearchTree T)
{
    if (T != NULL)
    {
        PostorderTravel(T->Left);
        PostorderTravel(T->Right);
        printf("%d\n", T->Element);
    }
}

void printTree(SearchTree  T,int level) 
{
	int i;
	if (!T) 
	{
		for (i = 0; i < level; i += 1) 
		{ 
			printf("  ");
		}
		printf("NULL\n");
		return;
	}
	printTree(T->Right,level+1);
	for (i = 0; i < level; i += 1) 
	{
		printf("  ");
	}
	printf("%02d\n",T->Element);
	printTree(T->Left,level+1);
}
void printfTree(SearchTree T, int type,  int level)
{
	int i;

	if (NULL == T)
		return;

	printfTree(T->Right, 2, level+1);
	switch (type)
	{
	case 0:
		printf("%2d\n", T->Element);
		break;
	case 1:
		for (i = 0; i < level; i++)	
			printf("\t");
		printf("\\\n");
		for (i = 0; i < level; i++)	
			printf("\t");
		printf("  %2d\n", T->Element);

		break;
	case 2:

		for (i = 0; i < level; i++)	
			printf("\t");
		printf(" %2d\n", T->Element);
		for (i = 0; i < level; i++)	
			printf("\t");
		printf("/\n");
		break;	
	}
	printfTree(T->Left, 1,  level+1);
}
