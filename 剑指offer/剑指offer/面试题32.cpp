#include <iostream>
//1到n中X出现的次数

int Xcount(int n, int X)
{
	if (n < 1 || X<0 || X > 9)
		return 0;
	int count = 0;
	int k = 0;
	for (int i = 1; k = n / i; i *= 10)
	{
		int high = k / 10;
		if (X == 0)
		{
			if (high)
				high--;
			else
				break;
		}
		count += high*i;
		int cur = k % 10;
		if (cur > X)
		{
			cur += i;
		}
		else if (cur == X)
		{
			count += n - k*i + 1;
		}
	}
	return count;
}

int main()
{
	std::cout << Xcount(1,1)<<std::endl;
	std::cout << Xcount(11, 1) << std::endl;
	std::cout << Xcount(10, 1) << std::endl;
	std::cout << Xcount(12, 1) << std::endl;
	std::cout << Xcount(21345, 1) << std::endl;
	std::cout << Xcount(100, 0) << std::endl;
	return 0;
}