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

//方法一，快速排序的变形，index将数组分为两部分，如果index
//恰好是mid/2，说明arr[index]是排在中间的数，在验证arr[index]
//的数是否超过一半即可（这种方法会改变数组元素的顺序）
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

//方法二，计数法，ret与下一次数相同加一，不同更新ret.
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