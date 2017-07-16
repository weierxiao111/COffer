#include <iostream>
using namespace std;

int  _Min(int *arr, int left, int right)
{
	if (NULL == arr || left < 0 || right < 0 || left > right)
		throw new exception("参数错误");
	for (int i = left+1; i <= right; ++i)
	{
		if (arr[left] > arr[i])
			arr[left] = arr[i];
	}
	return arr[left];
}

int Min(int *arr, int sz)
{
	if (NULL == arr || sz < 0)
		throw new exception("参数错误");
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	while (arr[left] >=  arr[right])
	{
		 mid = left + ((right - left) >> 1);
		if (right - left == 1)
		{
			arr[mid] = arr[right];
			break;
		}

		if (arr[left] == arr[right] &&
			arr[left] == arr[mid])
		{
			return _Min(arr, left, right);
		}
		else if (arr[mid] >= arr[right])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return arr[mid];
}

//int main()
//{
//	int arr[] = {5,6,0,1,2,3,4,5};
//	int min = Min(arr,sizeof(arr)/sizeof(arr[0]-1));
//	cout << min << endl;
//	return 0;
//}