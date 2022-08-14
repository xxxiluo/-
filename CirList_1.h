#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int num;
	struct Node *next;
};

int IsEmpty(struct Node *head);//�ж������Ƿ�Ϊ��
int add_node(struct Node *head,int num);//����½��
struct Node *find_node(struct Node *head,int num);//���ҽ�㣬�����ظý��
struct Node *find_previous_node(struct Node *head,int num);//���ҽ�㣬�����ظý���ǰ��
int del_node(struct Node *head,int num);//ɾ�����
int insert_node(struct Node *node,int num);//������
int print_list(struct Node *List);//�������
int del_list(struct Node *head);//ɾ������
int swap(struct Node *p,struct Node *q);//������������
int sort(struct Node *head);//�������������

int IsEmpty(struct Node *head)
{
	return head->next==head;
}
int add_node(struct Node *head,int num)
{
	struct Node *new_node=NULL;
	struct Node *p=head;
	new_node=(struct Node *)malloc(sizeof(struct Node));
	if(new_node==NULL)
	{
		printf("Error!\n");
		return -1;
	}
	while(p->next!=head)
	{
		p=p->next;
	}
	p->next=new_node;
	new_node->next=head;
	new_node->num=num;
	return 0;
}

struct Node *find_node(struct Node *head,int num)
{
	struct Node *p=head->next;
	while(p!=head&&p->num!=num)
	{
		p=p->next;
	}
	if(p==head)
	{
		return NULL;
	}
	else
	{
		return p;
	}
}

struct Node *find_previous_node(struct Node *head,int num)
{
	struct Node *p=head;
	if(p->next->num==num) return p;
	p=p->next;
	while(p!=head&&p->next->num!=num)
	{
		p=p->next;
	}
	if(p==head)
	{
		return NULL;
	}
	else
	{
		return p;
	}
}

int del_node(struct Node *head,int num)
{
	struct Node *p,*pdel;
	p=find_previous_node(head,num);
	if(p==NULL)
	{
		return -1;
	}
	pdel=p->next;
	p->next=pdel->next;
	free(pdel);
	if(find_previous_node(p,num)!=NULL)	del_node(p,num);//ɾ�����ֳ���һ�εĽ��
	return 0;
}

int insert_node(struct Node *node,int num)
{
	struct Node *new_node=NULL;
	struct Node *p=node->next;
	new_node=(struct Node *)malloc(sizeof(struct Node));
	if(new_node==NULL||node==NULL)
	{
		printf("Error!\n");
		return -1;
	}
	node->next=new_node;
	new_node->next=p;
	new_node->num=num;
	return 0;
}

int print_list(struct Node *head)
{
	struct Node *p=head->next;
	int list_len=0;
	printf("head-> ");
	while(p!=head)
	{
		printf("%d-> ",p->num);
		list_len++;
		p=p->next;
	}
	printf("head, list len : %d\n",list_len);
	return 0;
}

int del_list(struct Node *head)
{
	struct Node *p,*pfree;
	p=head->next;
	head->next=head;
	while(p!=head)
	{
		pfree=p->next;
		free(p);
		p=pfree;
	}
	return 0;
}

int swap(struct Node *p,struct Node *q)
{
	int t;
	t=p->num;
	p->num=q->num;
	q->num=t;
	return 0;
}

int sort(struct Node *head)
{
	struct Node *p,*q;
	for(p=head->next;p!=head;p=p->next)
          for(q=p->next;q!=head;q=q->next)
               if((p->num)>(q->num))
                   swap(p,q);
	return 0;
}