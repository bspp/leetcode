#include<stdio.h>
#include<malloc.h>
struct ListNode
{
	int val;
	struct ListNode *next;
};
void add(struct ListNode *l1,int element)
{
	struct ListNode *p = l1;
	while(1)
	{
		if(p->next == NULL)
		{
			struct ListNode *node = malloc(sizeof(struct ListNode));
			node->val = element;
			p->next = node;
			break;
		}else
			p = p->next;
	}
}
void printList(struct ListNode *l1)
{
	struct ListNode *p = l1;
	while(1)
	{
		if(p != NULL)
		{
			printf("%d\n",p->val);
			p = p->next;
		}else
			break;
}}
struct ListNode* addTwoNumbers(struct ListNode *l1,struct ListNode* l2)
{
	struct ListNode *result = malloc(sizeof(struct ListNode));
	result->next = NULL;
	result->val = 0;

	struct ListNode *p = result;
	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
	int add =  0;
	int i = 0;

	while(p1 != NULL || p2 != NULL || add != 0)
	{
		if(p1 != NULL)
		{
			add = add +p1->val;
			p1=p1->next;
		}
		if(p2 != NULL)
		{
			add = add + p2->val;
			p2 = p2->next;
		}
		struct ListNode *node = malloc(sizeof(struct ListNode));
		node->next = NULL;
		node->val = 0;
		
		node->val = add % 10;
		add = add / 10;

		p->next = node;
		p = node;
	}

	return result->next;
}
int main(){
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	struct ListNode *l2 = malloc(sizeof(struct ListNode));
	struct ListNode *l3;
	l1->val = 2;
	add(l1,2);
	add(l1,8);
	add(l1,4);
	add(l1,7);
	add(l1,2);
	add(l1,0);
	add(l1,3);
	add(l1,4);
	add(l1,1);
	l2->val = 8;
	add(l2,7);
	add(l2,9);
	add(l2,2);
	add(l2,7);
	add(l2,6);
	add(l2,7);

	l3 = addTwoNumbers(l1,l2);
	printList(l3);




}
