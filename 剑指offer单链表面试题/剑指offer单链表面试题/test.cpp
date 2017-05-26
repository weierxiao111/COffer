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

int main()
{
	ListNode *pHead = NULL;
	PushBack(pHead, 1);
	PushBack(pHead, 2);
	PushBack(pHead, 3);
	PushBack(pHead, 4);
	PushBack(pHead, 5);
	PushBack(pHead, 6);
	PushBack(pHead, 7);
	PushBack(pHead, 8); 
	PushBack(pHead, 9);
	PrintTailToHead(pHead);
	ListNode *pTemp = FindNode(pHead, 9);
	DeleteNode(pHead, pTemp);
	PrintTailToHead(pHead);


	return 0;
}
