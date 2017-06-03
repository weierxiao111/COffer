#pragma once 
#include <iostream>
using namespace std;
int GetfirstK(int *arr,int len, int K, int start, int end)
{
	if (NULL == arr || len <= 0 )
		return -1;
	while (start <= end)
	{
		int mid = start + ((end - start) >> 1);

		if (arr[mid] == K)
		{
			if (mid == 0 || arr[mid - 1] != K)
				return mid;
			else
				end = mid - 1;
		}
		else if (arr[mid] > K)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int GetlastK(int *arr, int len, int K, int start, int end)
{
	if (NULL == arr || len <= 0)
		return -1;
	while (start <= end)
	{
		int mid = start + ((end - start) >> 1);

		if (arr[mid] == K)
		{
			if (mid == len-1 || arr[mid + 1] != K)
				return mid;
			else
				start = mid + 1;
		}
		else if (arr[mid] > K)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int GetNumberOfK(int *arr, int len, int K)
{
	int first = GetfirstK(arr, len, K, 0, len - 1);
	if (first == -1)
		return 0;	
	return  GetlastK(arr, len, K, 0, len - 1)-first+1;
}