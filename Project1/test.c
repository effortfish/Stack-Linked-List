#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

//定义头节点
typedef struct{
	int data;
	struct LNode* next;
}LNode;

void Add(LNode* p, int d)
{
	LNode* new_Node;
	new_Node = (LNode*)malloc(sizeof(LNode));
	new_Node->data = d;
	new_Node->next = p->next;
	p->next = new_Node;
}

bool Delete(LNode* p)
{
	if (p->next == NULL)
		return false;
	//建立一个临时指针来存放要删除的节点
	LNode* tem_Pointer;
	tem_Pointer = p->next;
	p->next = tem_Pointer->next;
	free(tem_Pointer);
	return true;
}

void Show(LNode* p)
{
	LNode* tem_Pointer;
	tem_Pointer = p->next;
	/*while (1)
	{
		printf("%d ", tem_Pointer->data);
		tem_Pointer = tem_Pointer->next;
		if (tem_Pointer->next == NULL)
		{
			break;
		}
	}*/
	printf("%d ", tem_Pointer->data);
	tem_Pointer = tem_Pointer->next;
}

int main()
{
	LNode* ps;
	int d = 10;
	ps = (LNode*)malloc(sizeof(LNode));
	ps->next = NULL;
	Add(ps, d);
	Show(ps);
	Delete(ps);
	return 0;
}