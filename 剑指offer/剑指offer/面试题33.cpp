#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

const int LEN = 10;
char *comparenum1 = new char[2*LEN+1];
char *comparenum2 = new char[2*LEN+1];

int Compare(const void* num1, const void* num2)
{
	strcpy(comparenum1, *(const char**)num1);
	strcat(comparenum1, *(const char**)num2);

	strcpy(comparenum2, *(const char**)num2);
	strcat(comparenum2, *(const char**)num1);

	return strcmp(comparenum1, comparenum2);
}

void MinMergeNum(int arr[], int sz)
{
	if (NULL == arr || sz < 1)
		return ;

	char **nums = new char*[sz];
	for (int i = 0; i < sz; ++i)
	{
		nums[i] = new char[LEN+1];
		sprintf(nums[i], "%d", arr[i]);
	}
    
	qsort(nums, sz, sizeof(char*), Compare);
	for (int j = 0; j < sz; ++j)
	{
		cout << nums[j] << " ";
	}
	cout << endl;
	for (int k = 0;k < sz; ++k)
	{
		delete [](nums[k]);
	}
	delete []nums;
	delete[]comparenum1;
	delete[]comparenum2;
}

//int main()
//{
//	int arr[] = { 34,21,456,324,878,434,2323,434,123,545,323,5467,3231 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	MinMergeNum(arr,sz);
//	return 0;
//}