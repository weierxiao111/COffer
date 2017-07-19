#include <iostream>
#include <set>
using namespace std;

int partition_(int *arr, int left, int right)
{
	int slow = left - 1;
	for (int fast = left; fast < right; ++fast)
	{
		if (arr[fast] < arr[right])
		{
			slow++;
			if (slow != fast)
				swap(arr[slow], arr[fast]);
		}
	}
	++slow;
	swap(arr[slow], arr[right]);

	return slow;
}
//����һ�� ͬ29���ÿ�������˼�룬��ı�����˳��
void SmallKnum(int *arr, int sz, int K)
{
	if (NULL == arr || sz < K)
		return;
	int left = 0;
	int right = sz - 1;
	int index = partition_(arr, left, right);
	while (index != K)
	{
		if (index < K)
		{
			left = index + 1;
			index = partition_(arr, left, right);
		}
		else
		{
			right = index - 1;
			index = partition_(arr, left, right);
		}
	}

	for (int i = 0; i < index; ++i)
		cout << arr[i] << " ";
	cout << endl;
}


class greater{
public:
	bool operator()(const int& num1, const int &num2)
	{
		return  (num1 >= num2);
	}
};
//������  ��multiset���ײ�������/��� ����K����Сֵ����ֵС��multiset��
//����ʱ����,multiset,ע���Լ�д�Ƚ���ʱ������ >= ���������ͬԪ�ػᱼ��  
typedef multiset<int, greater>  Set;
typedef multiset<int, greater>::iterator Setit;

void SmallKnum_(int *arr, int sz, int K)
{
	if (NULL == arr || sz < 1 || sz < K)
		return;
	Set myset;
	Setit it = myset.begin();
	for (int i = 0; i < sz; ++i)
	{

		if (myset.size() < K)
		{
			myset.insert(arr[i]);
		}
		else
		{
			Setit it  = myset.begin();
			if (arr[i] < *myset.begin())
			{
				myset.erase(it);
				myset.insert(arr[i]);
			}
		}
	}

	for (it = myset.begin() ; it != myset.end(); ++it)
		cout << *it << " ";
	cout << endl;

}


//int main()
//{
//	int arr[] = {6,8,4,3,4,10,10,1,2,6,3,7,3,1,3,8,6,4,2,4,1,6,2,1,5,6};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	SmallKnum_(arr, sz , 6);
//	return 0;
//}