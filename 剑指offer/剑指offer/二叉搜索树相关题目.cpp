#include <iostream>
using namespace std;

template <class K, class V>
struct BSTNode {
	BSTNode(const K& key, const V& value = V())
		:_pLeft(NULL)
		, _pRight(NULL)
		, _key(key)
		, _value(value)
	{}

	BSTNode  *_pLeft;
	BSTNode  *_pRight;
	K   _key;
	V   _value;
};

template <class K, class V>
class BinarySearchTree {
public:
	typedef BSTNode<K, V>  Node;
	typedef BinarySearchTree<K, V>  BSTree;
public:
	BinarySearchTree()
		:_pRoot(NULL)
	{}

	BinarySearchTree(const BSTree& bst)
	{
		if (bst._pRoot)
		{
			_CopyBSTree(_pRoot, bst._pRoot);
		}
	}

	BSTree& operator = (const BSTree& bst)
	{
		if (this != &bst)
		{
			Node* temp;
			_CopyBSTree(temp, bst._pRoot);
			_Destroy(_pRoot);
			_pRoot = temp;
		}
		return (*this);
	}


	~BinarySearchTree()
	{
		_Destroy(_pRoot);
	}

	bool Find(const K& key)
	{
		return _Find(_pRoot, key);
	}

	Node* GetRoot()
	{
		return _pRoot;
	}

	bool Find_Nor(const K& key)
	{
		return _Find_Nor(_pRoot, key);
	}

	bool Insert(const K& key, const V& value)
	{

		if (NULL == _pRoot)
		{
			_pRoot = new Node(key, value);
			return true;
		}

		if (Find(key))
		{
			return false; //���йؼ���Ϊkey�Ľڵ㣬�����룬����false
		}
		//_Insert(_pRoot, key, value);
		_Insert_Nor(_pRoot, key, value);
	}

	bool Remove(const K& key)
	{
		if (NULL == _pRoot)
			return false;   //��������false
		if (!Find(key))
			return false;   //����û��key������false
							//_Remove_Nor(_pRoot, key);  //�ǵݹ�ɾ��
		_Remove(_pRoot, key);  //�ݹ�ɾ��
	}

	void Inorder()
	{
		_InderOrder(_pRoot);
		cout << endl;
	}

	Node *CovertToList(Node *proot)
	{
		Node *pTail = NULL;
		CovertNode(proot, pTail);

		Node *pHead = pTail;
		while (pHead && pHead->_pLeft != NULL)
			pHead = pHead->_pLeft;
		return pHead;
	}

	Node *GetpRoot()
	{
		return _pRoot;
	}

protected:
	void _CopyBSTree(Node* &proot, const Node* bstnode)
	{
		if (NULL == bstnode)
			return;
		proot = new Node(bstnode->_key, bstnode->_value);
		_CopyBSTree(proot->_pLeft, bstnode->_pLeft);
		_CopyBSTree(proot->_pRight, bstnode->_pRight);
	}


	void _Destroy(Node* &proot)
	{
		if (NULL == proot)
			return;
		_Destroy(proot->_pLeft);
		_Destroy(proot->_pRight);
		delete proot;
	}


private:

	void CovertNode(Node *pNode, Node *& pTail)
	{
		if (NULL == pNode)
			return;
		Node *pCur = pNode;
		if (pCur->_pLeft != NULL)
			CovertNode(pCur->_pLeft, pTail);
		pCur->_pLeft = pTail;
		if (pTail != NULL)
			pTail->_pRight = pCur;
		pTail = pCur;
		if (pCur->_pRight != NULL)
			CovertNode(pCur->_pRight, pTail);
	}

	bool _Find(Node *proot, const K& key)           //�ݹ����
	{
		if (NULL == proot)
			return false;
		if (key == proot->_key)
			return true;
		else if (key > proot->_key)
			_Find(proot->_pRight, key);
		else
			_Find(proot->_pLeft, key);
	}

	bool _Find_Nor(Node *proot, const K& key)  //�ǵݹ����
	{
		while (proot)
		{
			if (key == proot->_key)
				return true;
			else if (key > proot->_key)
				proot = proot->_pRight;
			else
				proot = proot->_pLeft;
		}
		return false;
	}

	bool _Insert(Node* &proot, const K& key, const V& value)  //�ݹ����
	{
		if (key > proot->_key)
		{
			if (NULL == proot->_pRight)
			{
				proot->_pRight = new Node(key, value);
				return true;  //����ɹ�
			}
			else
				_Insert(proot->_pRight, key, value);
		}

		if (key < proot->_key)
		{
			if (NULL == proot->_pLeft)
			{
				proot->_pLeft = new Node(key, value);
				return true;   //����ɹ�
			}
			else
				_Insert(proot->_pLeft, key, value);
		}
	}

	bool _Insert_Nor(Node* proot, const K& key, const V& value) //�ǵݹ����
	{
		while (proot)
		{
			if (key > proot->_key)
			{
				if (NULL == proot->_pRight)
				{
					proot->_pRight = new Node(key, value);
					return true;
				}
				else
					proot = proot->_pRight;
			}

			else if (key < proot->_key)
			{
				if (NULL == proot->_pLeft)
				{
					proot->_pLeft = new Node(key, value);
					return true;
				}
				else
					proot = proot->_pLeft;
			}
		}
	}

	bool _Remove_Nor(Node *&proot, const K& key)
	{
		//�ҵ�Ҫɾ���Ľڵ�
		Node *DelNode = proot;
		Node *ParentNode = NULL;
		while (true)
		{
			if (key == DelNode->_key)
				break;
			else if (key < DelNode->_key)
			{
				ParentNode = DelNode;
				DelNode = DelNode->_pLeft;
			}
			else
			{
				ParentNode = DelNode;
				DelNode = DelNode->_pRight;
			}
		}

		//��ɾ���ڵ��޺��ӽڵ�ֱ��ɾ��(���Թ�Ϊ��������)
		//��ɾ���ڵ�ֻ�����ӣ�������ɾ��������ڵ㣩
		if (NULL == DelNode->_pRight)
		{
			if (NULL == ParentNode)
				proot = DelNode->_pLeft;
			else if (DelNode == ParentNode->_pLeft)
			{
				ParentNode->_pLeft = DelNode->_pLeft;
			}
			else
			{
				ParentNode->_pRight = DelNode->_pLeft;
			}
			delete DelNode;
			return true;
		}
		//��ɾ���ڵ�ֻ���Һ��ӣ����Һ��Ӵ��汻ɾ���ڵ㣩
		else if (NULL == DelNode->_pLeft)
		{
			if (NULL == ParentNode)
				proot = DelNode->_pRight;
			else if (DelNode == ParentNode->_pLeft)
			{
				ParentNode->_pLeft = DelNode->_pRight;
			}
			else
			{
				ParentNode->_pRight = DelNode->_pRight;
			}
			delete DelNode;
			return true;
		}
		//��ɾ���ڵ������Һ��ӣ�����ɾ���ڵ��������е���С�ؼ�ֵ������Ȼ��ɾ���������Ľڵ�
		//���ýڵ��Ǳ�ɾ���ڵ�����������������ĵ�һ���ڵ㣩
		else
		{
			Node* firstNode = DelNode;
			ParentNode = DelNode;
			DelNode = DelNode->_pRight;
			while (DelNode->_pLeft)
			{
				ParentNode = DelNode;
				DelNode = DelNode->_pLeft;
			}
			std::swap(firstNode->_key, DelNode->_key);
			std::swap(firstNode->_value, DelNode->_value);
			if (DelNode->_pRight)
			{
				if (ParentNode->_pLeft == DelNode)
					ParentNode->_pLeft = DelNode->_pRight;
				else
					ParentNode->_pRight = DelNode->_pRight;
			}
			else
				ParentNode->_pLeft = NULL;
			delete DelNode;
			return true;
		}
	}

	bool _Remove(Node* &proot, const K& key)
	{
		if (key < proot->_key)
		{
			_Remove(proot->_pLeft, key);
		}
		else if (key > proot->_key)
		{
			_Remove(proot->_pRight, key);
		}
		else
		{
			if (proot->_pRight == NULL)
			{
				Node* pDel = proot;
				proot = proot->_pLeft;
				delete pDel;
				return true;
			}
			else if (proot->_pLeft == NULL)
			{
				Node* pDel = proot;
				proot = proot->_pLeft;
				delete pDel;
				return true;
			}
			else
			{
				Node* pDel = proot;
				pDel = pDel->_pRight;
				while (pDel->_pLeft)
				{
					pDel = pDel->_pLeft;
				}
				proot->_key = pDel->_key;
				proot->_value = pDel->_value;

				_Remove(proot->_pRight, proot->_key);
				return true;
			}
		}

	}

	void _InderOrder(Node *proot)
	{
		if (NULL == proot)
			return;
		_InderOrder(proot->_pLeft);
		cout << proot->_key << " ";
		_InderOrder(proot->_pRight);

	}

private:
	Node *_pRoot;
};

bool IsBSTree(int *arr, int sz)
{
	if (NULL == arr || sz < 1)
		return false;
	int root = arr[sz - 1];

	int i = 0;
	for (; i < sz - 1; ++i)
	{
		if (arr[i] > root)
			break;
	}
	int j = i;
	for (; j < sz - 1; ++j)
	{
		if (arr[j] < root)
			return false;
	}
	bool left = true;
	bool right = true;
	if (i > 0)
		left = IsBSTree(arr,i);
	if (sz - j > 1)
		right = IsBSTree(arr, i);
	return (left && right);
}

void ConvertoList(BSTNode<int,int> *root, BSTNode<int,int> *&ptail)
{
	if (NULL == root)
		return;
	if (root->_pLeft != NULL)
		ConvertoList(root->_pLeft, ptail);
	root->_pLeft = ptail;
	if (ptail != NULL)
		ptail->_pRight = root;
	ptail = root;
	if (root->_pRight != NULL)
		ConvertoList(root->_pRight, ptail);
}

BSTNode<int,int>* TreeToList(BSTNode<int,int> *root)
{
	if (NULL == root)
		return NULL;
	BSTNode<int,int> *pTailList = NULL;
	ConvertoList(root, pTailList);
	while (pTailList && pTailList->_pLeft!= NULL)
		pTailList = pTailList ->_pLeft;
	return pTailList;
}

//int main()
//{
//	int arr[] = {7,4,6,5,3,9,8,2,1,10,12};
//	BinarySearchTree<int,int> tree;
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//		tree.Insert(arr[i],arr[i]);
//	BSTNode<int, int> *root = TreeToList(tree.GetRoot());
//	while (root != NULL)
//	{
//		cout << root->_key << " ";
//		root = root->_pRight;
//	}
//	cout << endl;
//}