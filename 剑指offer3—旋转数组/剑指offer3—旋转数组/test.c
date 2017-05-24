#include <stdio.h>
#include <assert.h>
int Min(const int* arr,int right)
{
	int left = 0;
	assert(arr);
	if (right == 0)
		return arr[0];

	while (left < right)
	{
		int mid = left+ ((right-left)>>1);
		if (arr [left] == arr [mid] &&
			arr [right] == arr [mid])
			return findmin(arr,left,right);

		if (arr[left] < arr [mid])
		{
            left = mid;
		}
		else if (arr[left] > arr[mid])
		{
			right = mid;
		}
		else 
		{
			return arr[right];
		}
	}

}

int findmin(const int* arr, int left, int right)
{
	int min = arr[left];
	assert(arr);
	while (left < right)
	{
		left++;
		if (arr[left] < min)
			min =arr [left];
	}
	return min;
}


int main()
{
	int arr[5]= {3,4,5,1,2};
	int right = sizeof (arr)/sizeof(arr[0])-1;
	int ret = Min(arr,right);
	printf("%d\n",ret);
	
	return 0;
}