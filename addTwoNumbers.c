#include<stdio.h>
#include<malloc.h>
#define bool char
#define true 1
#define false 0
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
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *start_one = l1;
	struct ListNode *start_two = l2;

	bool use_one = false;
	short counter = 0;
	while (l1 && l2) {
		l1->val += l2->val + counter;
		if (l1->val > 9) {
			l1->val -= 10;
			counter = 1;

		} else {
			counter = 0;

		}
		l2->val = l1->val;

		l1 = l1->next;
		l2 = l2->next;

	}

	while (counter) {
		if (l1) {
			l1->val += counter;
			if (l1->val > 9) {
				l1->val -= 10;
				l1 = l1->next;
				use_one = true;
				counter = 1;

			} else {
				counter = 0;

			}

		} else if (l2) {
			l2->val += counter;
			if (l2->val > 9) {
				l2->val -= 10;
				l2 = l2->next;
				counter = 1;

			} else {
				counter = 0;

			}

		} else if (!use_one) {
			counter = 0;
			struct ListNode *empty = start_one;
			empty->val = 1;
			empty->next = NULL;
			start_one = start_two;
			while (start_one->next) {
				start_one = start_one->next;

			}
			start_one->next = empty;

		} else {
			counter = 0;
			struct ListNode *empty = start_two;
			empty->val = 1;
			empty->next = NULL;
			start_two = start_one;
			while (start_two->next) {
				start_two = start_two->next;

			}
			start_two->next = empty;

		}

	}

	if (l1 || use_one) { return start_one;  }
	return start_two;

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
