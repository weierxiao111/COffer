#include <iostream>
using namespace std;

int partition(int *arr, int left, int right)
{
	int start = left - 1;
	for (int i = left; i < right; ++i)
	{
		if (arr[i] < arr[right])
		{
			++i;
			if (i != start)
				swap(arr[i], arr[start]);
		}
	}
	++start;
	swap(arr[start], arr[right]);
	return start;
}

bool invalied = false;

bool check(int *arr, int sz, int ret)
{
	int count = 0;
	for (int i = 0; i < sz; ++i)
	{
		if (arr[i] == ret)
			count++;
	}
	if (2 * count > sz)
	{
		invalied = true;
		return ret;
	}
	else return 0;
}

//����һ����������ı��Σ�index�������Ϊ�����֣����index
//ǡ����mid/2��˵��arr[index]�������м����������֤arr[index]
//�����Ƿ񳬹�һ�뼴�ɣ����ַ�����ı�����Ԫ�ص�˳��
int MoreThanHalf(int *arr, int sz)
{
	if (NULL == arr || sz < 1)
		return 0;
	int index = partition(arr, 0, sz - 1);
	int left = 0;
	int right = sz - 1;
	int mid = (sz >> 1);
	while (index != mid)
	{
		if (index > mid)
			index = partition(arr, left, index - 1);
		else
			index = partition(arr, index + 1, right);
	}

	int ret =check (arr,sz,arr[mid]);
	return ret;

}

//����������������ret����һ������ͬ��һ����ͬ����ret.
int MoreThanHalf_2(int *arr, int sz)
{
	invalied = false;
	if (NULL == arr || sz < 1)
		return 0;
	int result = arr[0];
	int times = 1;
	for (int i = 1; i < sz; ++i)
	{
		if (times == 0)
		{
			result = arr[i];
			times = 1;
		}
		else if (arr[i] == result)
			times ++ ;
		else 
			times--;
	}
	result = check(arr, sz, result);
	return result;
}

//int main()
//{
//	int arr[] = {3,1,1,1,2,1,1,1,2,1,2,1,1,3,1,1,6,3,1,0,6,2,3};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = MoreThanHalf_2(arr, sz);
//	if (invalied)
//		cout<<ret<< endl;
//	return 0;
//}