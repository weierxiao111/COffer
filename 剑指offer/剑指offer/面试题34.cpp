//³óÊı  
#include <iostream>
using namespace std;

int Min(int n1, int n2, int n3)
{
	int min = (n1 < n2) ? n1 : n2;
	return ((min < n3) ? min : n3);
}
void PrintUglyNum(int n)
{
	if (n > 0)
	{
		int *nums = new int[n];
		nums[0] = 1;
		int *ugly2 = nums;
		int *ugly3 = nums;
		int *ugly5 = nums;
		int index = 1;
		while (index < n)
		{
			int min = Min(2 * (*ugly2),3 * (*ugly3),5 * (*ugly5)
				);
			nums[index] = min;
			++index;
			while (2 * (*ugly2) <= min)
				++ugly2;
			while (3 * (*ugly3) <= min)
				++ugly3;
			while (5 * (*ugly5) <= min)
				++ugly5;
		}

		for (int i = 0; i < n; ++i)
			cout << nums[i] << " ";
		cout << endl;
		delete[]nums;
	}
}

//int main()
//{
//	PrintUglyNum(10);
//	return 0;
//}