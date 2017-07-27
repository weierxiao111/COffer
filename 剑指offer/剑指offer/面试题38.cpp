#include <iostream>
using namespace std;

int GetFirstK(int *arr, int sz, int K)
{
	if (NULL == arr || sz < 1)
		return -1;
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] > K)
		{
			right = mid - 1;
		}
		else if (arr[mid] < K)
		{
			left = mid + 1;
		}
		else
		{
			if (mid == 0)
				return mid;
			else if (arr[mid - 1] != K)
				return mid;
			else
				right = mid - 1;
		}
	}

	return -1;
}

int GetLastK(int *arr, int sz, int K)
{
	if (NULL == arr || sz < 1)
		return -1;
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] > K)
		{
			right = mid - 1;
		}
		else if (arr[mid] < K)
		{
			left = mid + 1;
		}
		else
		{
			if (mid == sz-1)
				return mid;
			else if (arr[mid + 1] != K)
				return mid;
			else
				left = mid + 1;
		}
	}

	return -1;
}

int HasMoreK(int *arr, int sz, int K)
{
	int lastK = GetLastK(arr, sz, K);
	int firstK = GetFirstK(arr, sz, K);
	if (lastK == -1 || firstK == -1)
		return 0;
	return lastK - firstK + 1;
}

//int main()
//{
//	int arr[] = { 1,2,3,4,4,5 };
//	cout << HasMoreK(arr, sizeof(arr) / sizeof(arr[0]), 6) << endl;
//	return 0;
//}