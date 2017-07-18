#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include <stack>

template <typename T>
struct TreeNode{
	TreeNode()
	{}
	TreeNode(const T& value)
		:_value(value)
		,_pLeft(NULL)		
		,_pRight(NULL)
		{}
	TreeNode<T> *_pLeft;
	TreeNode<T> *_pRight;
	T _value;
	};

template <typename T>
class BinaryTree{
	typedef TreeNode<T> Node;
public:
	BinaryTree()
		:_pRoot(NULL)
	{}

	BinaryTree(const T* arr, int sz,const T& invalied)  //传入一个顺序为前序的数组，invalied意味节点为NULL
	{
		int index = 0;
		createTree(arr, _pRoot, sz, invalied, index);
	}

	BinaryTree(const BinaryTree<T>& t)
	{
		_pRoot = _CopyTree(t._pRoot);
	}

	Node* GetRoot()
	{
		return _pRoot;
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t) 
	{
		_DestroyTree(_pRoot);
		_pRoot = _CopyTree(t._pRoot);
		return *this;
	}

	void PreOrder()  //前序访问
	{
		cout<<"前序访问：";
	   _PreOrder(_pRoot);
	   cout<<"end"<<endl;
	}

	void InOrder() //中序访问
	{
		cout<<"中序访问：";
		_InOrder(_pRoot);
		cout<<"end"<<endl;
	}

	void PostOrder() //后序访问
	{
		cout<<"后序访问：";
		_PostOrder(_pRoot);
		cout<<"end"<<endl;
	}

	void LeverOrder() //层序访问
	{
		cout<<"层序访问：";
		queue<Node*> q;
		if (_pRoot)	
		{
			q.push(_pRoot);
			_LeverOrder(_pRoot, q);
		}
	}


	void PreOrder_Nor()   //前序遍历(不用递归)
	{
		if (_pRoot)
			_PreOrder_Nor(_pRoot);
	}

	void InOrder_Nor()   //中序遍历（不用递归）
	{
		if (_pRoot)
			_InOrder_Nor(_pRoot);
	}

	void PostOrder_Nor()   //后序遍历（不用递归）
	{
		if (_pRoot)
			_PostOrder_Nor(_pRoot);
	}



	~BinaryTree()
	{
		_DestroyTree(_pRoot);
	}

private:
	void createTree(const T* arr,Node* &proot ,size_t size,
		 const T& invalied, int& index)
	{
		if (index < size && arr[index] != invalied)
		{
			proot = new Node(arr[index]);
			createTree(arr, proot->_pLeft,size, invalied, ++index);
			createTree(arr, proot->_pRight,size, invalied, ++index);
		}
	}

	Node *_CopyTree(Node* proot)
	{
		if (proot)
		{
			Node *temp = new Node(proot->_value);
			temp ->_pLeft = _CopyTree(proot->_pLeft);
			temp ->_pRight = _CopyTree(proot->_pRight);
			return temp;
		}
		return NULL;
	}

	void _DestroyTree(Node *&proot)
	{
		if (proot)
		{
			_DestroyTree(proot->_pLeft);
			_DestroyTree(proot->_pRight);
			delete proot;
			proot = NULL;
		}
	}

private:
	Node *_pRoot;
};

TreeNode<int> *_Construct(int *preord, int *preend, int *inord, int *inend)
{
	TreeNode<int> *root = new TreeNode<int>();
	root->_value = preord[0];
	root->_pLeft = NULL;
	root->_pRight = NULL;

	if (preord == preend)
	{
		if (inord == inend && *preord == *inend)
			return root;
		else
			throw exception("no incorrect input");
	}
	int *inordroot = inord;
	while (inordroot != inend && *inordroot != root->_value)
		++inordroot;
	if (inord == inend && *inordroot != root->_value)
		throw exception("no incorrect input");
	int leftlen = inordroot - inord;
	if (leftlen > 0)
	{
		root->_pLeft = _Construct(preord+1, preord+leftlen,
			inord,inordroot-1);
	}
	if (leftlen < preend - preord)
	{
		root->_pRight = _Construct(preord+leftlen+1,preend,
			inordroot+1, inend);
	}
	return root;

}

TreeNode<int> *Construct(int* prearr, int *inarr, int sz)
{
	if (NULL == prearr || NULL == inarr || sz < 1)
		return NULL;
	return _Construct(prearr, prearr + sz - 1, inarr, inarr + sz - 1);
}

template <class T>
bool IsSubTree(TreeNode<T> *root1, TreeNode<T> *root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	if (root1->_value == root2->_value)
		return (IsSubTree(root1->_pLeft, root2->_pLeft) &&
			IsSubTree(root1->_pRight, root2->_pRight));
	else
		return false;
}

template <class T>
bool HasSubTree(TreeNode<T> *root1, TreeNode<T> *root2)
{
	bool ret = false;
	if (root1 != NULL && root2 != NULL)
	{
		if (root1->_value == root2->_value)
			ret = IsSubTree(root1, root2);
		if (!ret)
			ret = HasSubTree(root1->_pLeft, root2);
		if (!ret)
			ret = HasSubTree(root1->_pRight, root2);
	}
	return ret;
}

void MirrorTree(TreeNode<int>* root)
{
	if (NULL != root)
	{
		swap(root->_pLeft, root->_pRight);
		MirrorTree(root->_pLeft);
		MirrorTree(root->_pRight);
	}
}

void LeverPrint(TreeNode<int> *root)
{
	if (NULL == root)
		return;
	queue<TreeNode<int> *> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode<int> *temp = q.front();
		if (temp->_pLeft)
		{
			q.push(temp->_pLeft);
		}
		if (temp->_pRight)
		{
			q.push(temp->_pRight);
		}
		q.pop();
		cout << temp->_value << " ";
	}
	cout << endl;
}

void _FindPath(TreeNode<int> *root, int K, vector<int> &v, int cursum)
{
	if (NULL == root)
		return;
	cursum += root->_value;
	v.push_back(root->_value);
	bool isleaf = (root->_pLeft == NULL) && (root->_pRight == NULL);
	if (isleaf && (cursum == K))
	{
		vector<int>::iterator it = v.begin();
		for (; it != v.begin(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
		return;
	}
	if (root->_pLeft != NULL)
		_FindPath(root->_pLeft, K, v, cursum);
	if (root->_pRight != NULL)
		_FindPath(root->_pRight, K, v, cursum);
	v.pop_back();
}

void FindPath(TreeNode<int>  *root, int K)
{
	if (NULL == root)
		return;
	vector<int> v;
	int cursum = 0;
	_FindPath(root, K, v, cursum);
}



//int main()
//{
//	int arr[] = {8,8,9,0,0,2,4,0,0,7,0,0,7};
//	BinaryTree<int> tree1(arr, sizeof(arr)/sizeof(arr[0]), 0);
//	LeverPrint(tree1.GetRoot());
//	MirrorTree(tree1.GetRoot());
//	int arr2[] = {8,2};
//	BinaryTree<int> tree2(arr2, sizeof(arr2) / sizeof(arr2[0]), 0);
//	cout<< HasSubTree(tree1.GetRoot(), tree2.GetRoot())<<endl;
//
//    return 0;
//}