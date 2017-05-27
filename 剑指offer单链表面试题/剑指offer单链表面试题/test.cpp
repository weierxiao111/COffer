#include <iostream>
using namespace std;
#include <assert.h>

struct ListNode {
	ListNode(const int &data = 0 )
		:_data(data)
		,_pNext(NULL)
	{}
	ListNode *_pNext;
	int _data;
}Node;

void PushBack(ListNode *& phead, const int& data)
{
	ListNode *pNode = phead;
	if (NULL == phead)
		phead = new ListNode(data);
	else
	{
		while (pNode->_pNext)
			pNode = pNode->_pNext;
		pNode->_pNext = new ListNode(data);
	}

}

void PrintTailToHead(ListNode *phead)
{
	if (phead != NULL)
	{
		PrintTailToHead(phead->_pNext);
		cout << phead->_data << " ";
	}
	else
		cout << endl;
}

ListNode *FindNode(ListNode *phead, const int &data)
{
	if (NULL == phead)
		return NULL;
	while (phead)
	{
		if (phead->_data == data)
			return phead;
		phead = phead->_pNext;
	}
	return phead;
}

bool DeleteNode(ListNode* &phead, ListNode *DelNode)
{
	if (NULL == phead || NULL == DeleteNode)
		return false;
	if (phead == DelNode)
	{
		ListNode *Temp = phead;
		phead = phead->_pNext;
		delete Temp;
		return true;
	}
	if (NULL == DelNode->_pNext)
	{
		ListNode *pNode = phead;
		while (pNode->_pNext != DelNode)
			pNode = pNode->_pNext;
		pNode->_pNext = NULL;
		delete DelNode;
	}
	else
	{
		ListNode *Temp = DelNode->_pNext;
		DelNode->_data = Temp->_data;
		DelNode->_pNext = Temp->_pNext;
		delete Temp;
	}
	
}

ListNode *TailKNode(ListNode *phead, int k)
{
	if (NULL == phead || k <= 0)
		return NULL;
	ListNode *FastNode = phead;
	ListNode *SlowNode = phead;

	while (k-- > 1 )
	{
		FastNode = FastNode->_pNext;
		if (NULL == FastNode)
			return NULL;
	}

	while (FastNode->_pNext)
	{
		SlowNode = SlowNode->_pNext;
		FastNode = FastNode->_pNext;
	}
	return SlowNode;
}

ListNode *ResverList(ListNode *phead)
{
	if (NULL == phead || NULL == phead->_pNext)
		return phead;
	ListNode *prev = NULL;
	ListNode *pCur = phead;
	ListNode *pnext = phead->_pNext;
	while (pnext)
	{
		pCur->_pNext = prev;
		prev = pCur;
		pCur = pnext;
		pnext = pnext->_pNext;
	}
	pCur->_pNext = prev;
	return pCur;
}

ListNode *Merge(ListNode *phead1, ListNode *phead2)
{
	if (NULL == phead1)
		return phead2;
	if (NULL == phead2)
		return phead1;

	ListNode *newphead = NULL;
	if (phead1->_data < phead2->_data)
	{
		newphead = phead1;
		newphead->_pNext = Merge(phead1->_pNext, phead2);
	}
	else
	{
		newphead = phead2;
		newphead->_pNext = Merge(phead1, phead2->_pNext);
	}

	return newphead;
}

int main()
{
	ListNode *pHead1 = NULL;
	PushBack(pHead1, 1);
	PushBack(pHead1, 3);
	PushBack(pHead1, 5);
	PushBack(pHead1, 6);
	PushBack(pHead1, 8); 
	PushBack(pHead1, 9);
	ListNode *pHead2 = NULL;
	PushBack(pHead2, 2);
	PushBack(pHead2, 4);
	PushBack(pHead2, 5);
	PushBack(pHead2, 8);
	PushBack(pHead2, 9);
	PushBack(pHead2, 12);
	PushBack(pHead2, 12);
	ListNode *mergehead = Merge(pHead1, pHead2);
	PrintTailToHead(mergehead);


	return 0;
}
