#include <iostream>
using namespace std;

int Fib(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fib(n-1) + Fib(n - 2);
}

int Fib_Nor(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	int second = 0;
	int last = 1;
	int ret = 0;
	while (n >1)
	{
		ret = second + last;
		second = last;
		last = ret;
		n--;
	}
	return ret;
}

//int main()
//{
//	cout << Fib(10) << " " << Fib_Nor(10) << endl;
//	return 0;
//}