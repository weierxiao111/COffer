#include <iostream>
using namespace std;

void PrintRingMartix(int arr[][7], int clo, int row)
{
	if (NULL == arr || clo <= 0 || row <= 0)
		return;
	int start = 0;
	int i = 0;
	int j = 0;
	int end = (row > clo) ? (row>>1) : (clo >> 1);
	for (; start < end; ++start)
	{	
		for ( j = start; j < row - start; ++j)
			cout << arr[start][j]<<" ";
		j--;

		if (clo < row)
		for (i = start + 1; i < clo - start; ++i)
			cout << arr[i][j]<<" ";
		i--;
		if (start != end-1)
		for (j = j - 1; j >= start; --j)
			cout << arr[i][j] << " ";
		j++;
		if (start != end-1)
		for (i = i - 1; i > start; --i)
			cout << arr[i][j] << " ";
	}
	cout << endl;
}

//int main()
//{
//	int arr[][7] = { {1, 2, 3, 4, 5, 6, 7},
//					 {20,21,22,23,24,25,8},
//					 {19,32,33,34,35,26,9},
//					 {18,31,30,29,28,27,10},
//					 {17,16,15,14,13,12,11} };
//	PrintRingMartix(arr, 5, 7);
//	return 0;
//}