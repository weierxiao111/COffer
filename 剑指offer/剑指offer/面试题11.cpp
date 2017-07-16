#include <iostream>
using namespace std;

bool equal(double n1, double n2)
{
	const double ESP = 0.000000001;
	if (n1 - n2 < ESP && n2 - n1 < ESP)
		return true;
	return false;
}

double _Pow_Nor(double base, int n)
{
	double ret = base;
	for (int i = 2; i <= n; ++i)
		ret *= base;
	return ret;
}

double _Pow(double base, int n)
{
	if (n == 1)
		return base;
	double ret = _Pow(base, n >>1);
	ret *= ret;
	if ((n & 0x1) == 0)
		return ret;
	else
		return ret*base;
}

double Pow(double base, int n)
{
	bool invalied = true;
	if (equal(base, 0.0) && n <= 0)
	{
		invalied = false;
		return 0.0;
	}
	double ret = 1.0;
	if (n < 0)
	{
		n = -n;
		ret = 1 / _Pow(base, n);
	}
	else if (n>0)
	{
		ret = _Pow(base, n);
	}
	return ret;
}
//
//int main()
//{
//	cout << Pow(-6.23,-12);
//	return 0;
//}