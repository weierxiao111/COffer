#include <iostream>
using namespace std;

bool isEven(int num)
{
	return ((num & 0x1) == 0);
}

void _Reorder(int arr[], int sz,bool (*fun)(int))
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		while (left < right && !fun(arr[left]))
			left++;
		while (left < right && fun(arr[right]))
			right--;
		if (left < right)
			swap(arr[left++], arr[right--]);
	}
}

void Reorder(int *arr, int sz)
{
	if (NULL == arr || sz < 1)
		return;

	_Reorder(arr, sz, isEven);
}


//int main()
//{
//	int arr[] = { 1,2,4,5,6,8,9,5,3,2,3,5,7,8,5,4,3,2,7,8,9,2 };
//	Reorder(arr,sizeof(arr)/sizeof(arr[0]));
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//		cout << arr[i] << " ";
//	return 0;
//}