#include <iostream>
using namespace std;

//n个数范围在0~n-1之间，求重复元素
//注：每次移动会把元素移动到与其下标对应的位置，直到找到重复元素，
//所以没有相同元素最多移动n次,时间复杂度O(N)
bool repeatnum(int *arr, int sz)
{
	if (NULL == arr || sz < 2)
		return false;

	for (int i = 0; i < sz;++i)
	{
		while (arr[i] != i)  //不等于下标交换位置
		{
			//待交换位置上的元素与当前元素相同，找到重复元素
			if (arr[i] == arr[arr[i]])  
			{
				cout << arr[i] << endl;
				return true;
			}
			swap(arr[i], arr[arr[i]]); //移动元素位置
		}
	}
	return false;  //没找到重复元素
}
//int main()
//{
//	int arr[] = {2,4,1,0,3,5,6};
//	int size = sizeof(arr) / sizeof(arr[0]);
//	if (repeatnum(arr, size))
//		cout << "yes" << endl;
//	return 0;
//}