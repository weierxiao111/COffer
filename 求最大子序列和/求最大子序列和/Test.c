#include <stdio.h>

//int maxsquenceSum1(int *arr, int N)
//{
//	int thissum, maxsum;
//	int i, j;
//	maxsum = 0;
//	for (i = 0; i<= N; i++)
//	{
//		thissum = 0;
//		for (j = i; j <= N; j++)
//		{
//			thissum += arr[j];
//			if (thissum > maxsum)
//			{
//				maxsum = thissum;
//			}
//		}
//	}
//
//	return maxsum;
//}
int Max(int sum1, int sum2, int sum3)
{
	if (sum1 > sum2)
		return (sum3>sum1)?sum3:sum1;
	else 
		return (sum3>sum2)?sum3:sum2;
}

int maxsquenceSum2(int *arr, int left, int right)
{
	int maxleftSum, maxrightSum;
	int maxleftborderSum ,maxrightborderSum;
	int leftborderSum, rightborderSum;
	int i;
	int mid = left + ((right-left)>>1);
	if (left == right)
	{
		if (arr[left] < 0)
			return 0;
		else 
			return arr[left];
	}
	
	maxleftSum = maxsquenceSum2(arr,left,mid);
	maxrightSum = maxsquenceSum2(arr,mid+1,right);
	maxleftborderSum = 0;
	leftborderSum = 0;
	for ( i = mid; i>= 0; --i)
	{
		leftborderSum += arr[i];
		if (leftborderSum > maxleftborderSum)
		{
			maxleftborderSum = leftborderSum;
		}
	}

	maxrightborderSum = 0;
	rightborderSum = 0;
	for (i = mid+1; i<= right; ++i)
	{
		rightborderSum += arr[i];
		if (rightborderSum > maxrightborderSum)
		{
			maxrightborderSum = rightborderSum;
		}
	}

	return Max(maxleftSum, maxrightSum, maxleftborderSum+maxrightborderSum);
}
//
//int maxsquenceSum3(int *arr, int N)
//{
//	int thissum, maxsum;
//	int i;
//	thissum = 0;
//	maxsum = 0;
//	for (i = 0; i<= N; ++i)
//	{
//		thissum += arr[i];
//		if (thissum < 0)
//		{
//			thissum = 0;
//		}
//		if (thissum >= maxsum)
//		{
//			maxsum = thissum;
//		}
//	}
//
//	return maxsum;
//}

int main()
{
	int arr[] = {5, -3, 6, -10, -1, 2, 6, -2};
	int ret = maxsquenceSum2(arr,0, 7);
	printf("%d\n",ret);
	return 0;
}