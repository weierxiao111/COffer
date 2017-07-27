#include <iostream>
using namespace std;

void _Print(int small, int big, int K)
{
	cout << "和为K的连续序列: ";
	for (; small <= big; ++small)
		cout << small << " ";
	cout << endl;
}
void PrintAddKsquece(int K)
{
	int small = 1;
	int big = 2;
	int sum = small + big;
	while (big - small != 1 || big + small <= K)  //注意循环方法
	{

	    if (sum < K)
		{
			big++;
			sum += big;
		}
		else
		{
			if (sum == K)
			{
				_Print(small, big, K);
			}
			small++;
			big = small + 1;
			sum = big + small;
		}
	}
}

//int main()
//{
//	PrintAddKsquece(100);
//	return 0;
//}