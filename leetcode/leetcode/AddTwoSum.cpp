#include"stdafx.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

/*ÌâÄ¿ÃèÊö
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
2018-3-1
*/

struct ListNode {
	int val;
	struct ListNode *next;
};


int GetLength(struct ListNode* p);
void supplyList(struct ListNode *l, int n);


/*complex/bad solution*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int L1 = GetLength(l1);
	int L2 = GetLength(l2);

	if (L1 != L2)
		L1 > L2 ? supplyList(l2, L1 - L2) : supplyList(l1, L2 - L1);

	bool IsCarry = false;
	struct ListNode* p = l1;
	while (l1)
	{
		l1->val += l2->val;
		if (IsCarry)
		{
			l1->val++;
			IsCarry = false;
		}
		if (l1->val >= 10)
		{
			l1->val -= 10;
			IsCarry = true;
			if (l1->next == NULL)
			{
				struct ListNode *newL = (struct ListNode*)malloc(sizeof(struct ListNode));
				newL->val = 1;
				newL->next = NULL;
				l1->next = newL;
				break;
			}
		}
		if (l1 != NULL)
			l1 = l1->next;
		if (l2 != NULL)
			l2 = l2->next;
	}
	return p;
}

/*simple/good solution*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p = l1, *q = l2, *current = dummyHead;
	int carry = 0, result = 0, x = 0, y = 0;

	while (p != NULL || q != NULL)
	{
		x = (p == NULL) ? 0 : p->val;
		y = (q == NULL) ? 0 : q->val;
		result = x + y + carry;
		carry = result / 10;
		struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->val = result % 10;
		current->next = temp;
		current = current->next;
		if (p != NULL) p = p->next;
		if (q != NULL) q = q->next;
	}

	if (carry == 1)
	{
		struct ListNode *last = (struct ListNode*)malloc(sizeof(struct ListNode));
		last->val = 1;
		current->next = last;
		last->next = NULL;
	}
	else current->next = NULL;

	return dummyHead->next;
}
int GetLength(struct ListNode* p)
{
	int n = 0;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}
void supplyList(struct ListNode *l, int n)
{
	struct ListNode *temp = NULL;
	while (l != NULL && l->next != NULL)
		l = l->next;
	while (n--)
	{
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->val = 0;
		l->next = temp;
		if (n == 0)
			temp->next = NULL;
		l = l->next;
	}
}

struct ListNode* makeList(int length)
{
	struct ListNode *q = NULL;
	int value = 0;
	for (int i = 0; i < length; i++)
	{
		struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf_s("%d", &value);
		p->val = value;
		p->next = q;
		q = p;
	}
	return q;
}

int main()
{
	int L1, L2;
	printf("print two list length\n");
	scanf_s("%d %d", &L1, &L2);
	printf("print l1\n");
	struct ListNode *l1 = makeList(L1);
	printf("print l2\n");
	struct ListNode *l2 = makeList(L2);
	struct ListNode *p = addTwoNumbers(l1, l2);
	printf("p\n");
	while (p)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	system("pause");
}