#include <stdio.h>

void swap(int* num1, int* num2 )
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
bool isodd (int num )
{
	return (num & 0x1);
}

void  setOrder(int* arr,int right,bool (*fun)(int))
{
	if ((NULL == arr) || (right <= 0))
		return ;
	int left = 0;
	while (left < right)
	{
		while ( fun(arr[left]) && left < right)
		    left ++;
		while ( !fun(arr[right]) && left < right)
			right --;
		if (left < right) 
			swap(&arr[left],&arr[right]) ;
	}
}

int main()
{
	int arr[7] = {0,1,4,3,6,7,8};
	int right = sizeof(arr)/sizeof(arr[0]) - 1;
	setOrder(arr,right,isodd);
	return 0;
}