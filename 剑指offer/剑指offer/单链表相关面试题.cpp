#include <iostream>
#include <stack>
#include <list>
using namespace std;

typedef struct SignalListNode {
	SignalListNode(const int& data = 0)
		:_data(data)
		,_Pnext(NULL)
	{}
	SignalListNode *_Pnext;
	int _data;
}Node;

void PushBack(Node*& phead, const int& value)
{
	if (NULL == phead)
		phead = new Node(value);
	else
	{
		Node *ptemp = phead;
		while (ptemp->_Pnext)
			ptemp = ptemp->_Pnext;
		ptemp->_Pnext = new Node(value);
	}
}

void PushFront(Node*& phead, const int& value)
{
	Node* ptemp = new Node(value);
	ptemp->_Pnext = phead;
	phead = ptemp;
}

void printList(Node *phead)
{
	while (phead)
	{
		cout << phead->_data << "->";
		phead = phead->_Pnext;
	}
	cout << endl;
}

Node* Findnode(Node *phead, const int& value)
{
	while (phead)
	{
		if (phead->_data == value)
			return phead;
		phead = phead->_Pnext;
	}
	return NULL;
}

void DeleteNode(Node *&phead, Node *delNode) //删除节点
{
	if (NULL == phead || NULL == delNode)
		return;
	if (delNode->_Pnext != NULL) //非尾节点
	{
		Node *pnext = delNode->_Pnext;
		delNode->_data = pnext->_data;
		delNode->_Pnext = pnext->_Pnext;
		delete pnext;
		pnext = NULL;
	}
	else if (phead == delNode)  //头节点
	{
		delete delNode;
		delNode = NULL;
		phead = NULL;
	}
	else  //尾节点
	{
		Node* ptemp = phead;
		while (ptemp -> _Pnext != delNode)
		{
			ptemp = ptemp->_Pnext;
		}
		ptemp->_Pnext = NULL;
		delete delNode;
		delNode = NULL;
	}

}

void PrintTailtoHead_Nor(Node *phead)
{
	stack<Node*> st;
	while (phead)
	{
		st.push(phead);
		phead = phead->_Pnext;
	}
	while (!st.empty())
	{
		Node* pTemp = st.top();
		cout << pTemp->_data << "->";
		st.pop();
	}
	cout << "NULL" << endl;
}

void PrintTailToHead(Node *phead)
{
	if (phead)
	{
		PrintTailToHead(phead->_Pnext);
		cout << phead->_data << "->";
	}
}

Node* FindKToTail(Node *phead, size_t k) //删除倒数第K个节点
{
	if (NULL == phead || k == 0)
		return NULL;
	Node *fast = phead;
	Node *slow = phead;
	while (--k)
	{
		if (fast->_Pnext == NULL)
		{
			cout << "已经到头了" << endl;
			return NULL;
		}
		fast = fast->_Pnext;
	}
	while (fast->_Pnext != NULL)
	{
		slow = slow->_Pnext;
		fast = fast->_Pnext;
	}
	return slow;
}

Node* ResverLsit(Node *phead)   //翻转链表
{
	if (NULL == phead || phead->_Pnext == NULL)
		return phead;
	Node* Tailhead = NULL;
	Node *pnode = phead;
	Node *ppre = NULL;
	while (pnode != NULL)
	{
		Node *pnext = pnode->_Pnext;
		if (NULL == pnext)
			Tailhead = pnode;
		pnode->_Pnext = ppre;
		ppre = pnode;
		pnode = pnext;		
	}
	return Tailhead;
}

//合并两个有序链表
Node *MergeList(Node *phead1, Node* phead2)
{
	if (NULL == phead1)
		return phead2;
	if (NULL == phead2)
		return phead1;
	Node* newhead = NULL;
	if (phead1->_data < phead2->_data)
	{
		newhead = phead1;
		newhead->_Pnext = MergeList(phead1->_Pnext, phead2);
	}
	else 
	{
		newhead = phead2;
		newhead->_Pnext = MergeList(phead1, phead2->_Pnext);
	}
	return newhead;
}

/*
Node* MergeList_Nor(Node *phead1, Node *phead2)
{
	if (NULL == phead1)
		return phead2;
	if (NULL == phead2)
		return phead1;
	Node* newhead = phead1;
	Node* pnode = phead2;
	Node* next = NULL;
	while (pnode != NULL)
	{
		next = pnode->_Pnext;

	}
	return newhead;

}
*/
size_t  GetlenghtList(Node* phead)
{
	if (NULL == phead)
		return 0;
	Node* pNode = phead;
	while (pNode->_Pnext != NULL)
		pNode = pNode->_Pnext;
	return (pNode - phead + 1);
}
//两个链表的第一个交点
Node* FindFirstFcous(Node* phead1, Node* phead2)
{
    size_t len1 = GetlenghtList(phead1);
	size_t len2 = GetlenghtList(phead2);
	int len = len1 - len2;
	Node* shorthead = phead2;
	Node* longhead = phead1;
	if (len1 < len2)
	{
		shorthead = phead1;
		longhead = phead2;
		len = len2 - len1;
	}
	for (int i = 0; i < len; ++i)
		longhead = longhead->_Pnext;
	while ((longhead != NULL) &&
		(shorthead != NULL) &&
		(longhead != shorthead)
		)
	{
		longhead = longhead->_Pnext;
		shorthead = shorthead->_Pnext;
	}
	return longhead;
}

Node* TailNode(Node *phead)
{
	while (phead != NULL && phead->_Pnext != NULL)
		phead = phead->_Pnext;
	return phead;
}
//约瑟夫环问题，0-n-1构成环，每次删除第m个元素，求最后剩下的数字
int JosephRing_1(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	Node* Ring = NULL;
	for (int i = 0; i < n; ++i)
		PushBack(Ring, i);
	Node* Tail = TailNode(Ring);
	Tail->_Pnext = Ring;

	Node* ppre = Tail;
	Node* pnode = Ring;
	while (ppre != pnode)
	{
		for (int j = 1; j < m; ++j)
		{
			ppre = ppre->_Pnext;
			pnode = pnode->_Pnext;
		}
		Node *pdel = pnode;
		ppre->_Pnext = pnode->_Pnext;
		pnode = pnode->_Pnext;
		delete pdel;
	}
	return pnode->_data;
}

int JosephRing_2(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	list<int> ring;
	for (int i = 0; i < n; ++i)
		ring.push_back(i);
	list<int>::iterator it = ring.begin();
	while (ring.size() > 1)
	{
		for (int j = 1; j < m; ++j)
		{
			++it;
			if (it == ring.end())
				it = ring.begin();
		}
		list<int>::iterator next = ++it;
		if (next == ring.end())
			next = ring.begin();
		--it;
		ring.erase(it);
		it = next;
	}
	return (*it);
}

//判断是否带环，如果带环，返回入口点
Node *MeetingNode(Node* phead)
{
	if (NULL == phead)
		return phead;
	Node *slow = phead->_Pnext;
	if (NULL == slow)
		return NULL;
	Node *fast = phead->_Pnext;
	while (fast != NULL && slow != NULL)
	{
		if (slow == fast)
			return fast;
		slow = slow->_Pnext;
		if (fast->_Pnext != NULL)
			fast = fast->_Pnext->_Pnext;
		else
			return NULL;
	}
	return NULL;
}

Node *GetEnterNode(Node *phead)
{
	Node *meetNode = MeetingNode(phead);
	if (NULL == meetNode)
		return NULL;

	int ringnode = 1;
	Node *pnode = meetNode->_Pnext;
	while (pnode != meetNode)
	{
		++ringnode;
		pnode = pnode->_Pnext;
	}
	Node* fast = phead;
	Node* slow = phead;
	for (int i = 0; i < ringnode; ++i)
	{
		fast = fast->_Pnext;
	}
	while (fast != slow)
	{
		fast = fast->_Pnext;
		slow = slow->_Pnext;
	}
	return slow;
}

void DelSameNode(Node*& phead)
{
	Node* ppre = NULL;
	Node* pnode = phead;
	while (pnode != NULL)
	{
		bool needdel = false;
		Node *pnext = pnode->_Pnext;
		if (pnext != NULL && pnext->_data == pnode->_data)
			needdel = true;
		if (!needdel)
		{
			ppre = pnode;
			pnode = pnext;
		}
		else
		{
			int value = pnode->_data;
			Node *pdel = pnode;
			while (pnode != NULL && pnode->_data == value)
			{
				pnode = pnode->_Pnext;
				delete pdel;
				pdel = pnode;
			}
			if (ppre == NULL)
			{
				ppre = pnode;
				phead = ppre;
			}
			else
				ppre->_Pnext = pnode;
		}
	}
}

Node* Resver_2(Node *phead)
{
	if (NULL == phead || phead->_Pnext == NULL)
		return phead;
	Node *pTailHead = NULL;
	Node *ppre = NULL;
	Node *pnode = phead;
	while (pnode)
	{
		Node* pnext = pnode->_Pnext;
		if (pnext == NULL)
			pTailHead = pnode;
		pnode->_Pnext = ppre;
		ppre = pnode;
		pnode = pnext;
	}
	return pTailHead;
}

void Test1()
{
	Node *Phead1 = NULL;
	Node *Phead2 = NULL;
	PushBack(Phead1, 1);
	PushBack(Phead1, 2);
	PushBack(Phead1, 2);
	PushBack(Phead1, 3);
	PushBack(Phead1, 4);
	PushBack(Phead1, 4);
	PushBack(Phead1, 5);
	PushBack(Phead1, 5);
	PushBack(Phead1, 5);
	PushBack(Phead1, 6);
	PushBack(Phead1, 6);
	PushBack(Phead1, 6);
	PushBack(Phead1, 7);
	PushBack(Phead1, 8);
	Phead1 = Resver_2(Phead1);
	printList(Phead1);

}

int main()
{
	Test1();
	return 0;
}