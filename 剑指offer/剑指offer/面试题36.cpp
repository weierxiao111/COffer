#include <iostream>
using namespace std;

int _InverseMerge(int *arr, int *copy, int left, int right)
{
	if (left == right)
		return 0;
	int mid = (left + ((right - left) >> 1));   //ÎğÍüÀ¨ºÅ
	int leftPairs = _InverseMerge(arr, copy, left, mid);
	int rightPairs = _InverseMerge(arr, copy, mid+1, right);
	int end = right;
	int i = mid;
	int j = right;
	int Pairs = 0;
	while (left <= i && mid + 1 <= j)
	{
		if (arr[i] > arr[j])
		{
			Pairs += (j - mid);
			copy[right--] = arr[i];
			i--;
		}
		else
		{
			copy[right--] = arr[j];
			j--;
		}
	}
	if (left <= i) //ÎğÍü
	{
		copy[right--] = arr[i--];
	}
	if (mid + 1 <= j)  //ÎğÍü
	{
		copy[right--] = arr[j--];
	}

	for (; left <= end; ++left)
	{
		arr[left] = copy[left];
	}
	return Pairs + leftPairs + rightPairs;
}

int InversePairs(int arr[], int sz)
{
	if (NULL == arr || sz < 2)
		return 0;

	int *copy = new int[sz];
	return _InverseMerge(arr, copy, 0, sz-1);
	delete[]copy;
}
//int main()
//{
//	int arr[] = {4,5,6,7,8,6,9};
//	cout<<InversePairs(arr, 7)<<endl;
//	return 0;
//}