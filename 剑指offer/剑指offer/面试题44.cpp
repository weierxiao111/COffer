#include <iostream>
using namespace std;

int partition_2(int *arr, int left, int right)
{
	int slow = left - 1;
	for (int i = left; i < right; ++i)
	{
		if (arr[i] < arr[right])
		{
			slow++;
			if (slow != i)
				swap(arr[i], arr[slow]);
		}
	}
	++slow;
	swap(arr[slow], arr[right]);
	return slow;
}

void qSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int index = partition_2(arr, left, right);
		qSort(arr, left, index - 1);
		qSort(arr, index + 1, right);
	}
}

//�Ѵ�������0
bool IsContinue(int *arr, int sz)
{
	if (NULL == arr || sz < 1)
		return false;

	qSort(arr,0,sz-1);
	//0����Ŀ
	int zeronums = 0;
	for (int i = 0; i < sz; ++i)
	{
		if (0 == arr[i])
			zeronums++;
		else
			break;
	}
	//��һ����Ϊ0���±�
	int small = zeronums;
	int big = small + 1;

	int difference = 0;
	while (big < sz) 
	{
		//������һ����Ϊ˳��
		if (arr[big] == arr[small])
			return false;
		//�������ڿ�Ƭ����Ĳ�
		difference += (arr[big] - arr[small] - 1);
		small++;
		big++;
	}
	//����Ĳ��Ƿ�����0���
	return (difference  <= zeronums );
}

//int main()
//{
//	int arr[] = { 1,5,0,0,3 };
//	cout << IsContinue(arr, 5) << endl;
//	return 0;
//}