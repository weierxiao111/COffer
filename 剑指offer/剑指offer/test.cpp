
//int Add(int num1, int num2)
//{
//	if (num2 == 0)
//		return num1;
//	int temp = num1;
//	num1 = num1^num2;
//	num2 = (temp & num2)<< 1;
//	return Add(num1, num2);
//}
//
//class Temp {
//public:
//    Temp()
//	{
//		Num++;
//		Sum += Num;
// 	}
//
//	static void  Init()
//	{
//		Num = 0;
//		Sum = 0;
//	}
//
//	static size_t  GetSum()
//	{
//		return Sum;
//	}
//private:
//	static size_t Num;
//	static size_t Sum;
//};
//
//size_t Temp::Num = 0;
//size_t Temp::Sum = 0;
//
//size_t Sum_matain(size_t n)
//{
//	Temp::Init();
//	Temp* t = new Temp [n];
//	delete[]t;
//	return Temp::GetSum();
//}
#include <iostream>
using namespace std;
#include <assert.h>
#include <stdlib.h>

int numofone(int n);

int fun(int n)
{
	int num = 0;
	for (int i = 1; i <= n; ++i)
		num += numofone(i);
	return num;
}

int numofone(int n)
{
	int num = 0;
	while (n)
	{
		if (n % 10 == 1)
			num += 1;
		n = n / 10;
	}
	return num;
}

size_t _numberHasOne(char* num);
size_t numberHasOne(int num)
{
	if (num < 0)
		return 0;

	char *strnum = new char[50];
	_itoa_s(num, strnum,50, 10);
	size_t ret = _numberHasOne(strnum);
	delete[]strnum;
	return ret;
}

size_t _numberHasOne(char* num)
{
	if (NULL == num || *num == '\0')
		return 0;
	size_t len = strlen(num);
	if (len == 1)
		return 1;
	size_t firstlen = 0;
	if (*num == '1')
		firstlen = atoi(num + 1) + 1;
	else
		firstlen = pow(10 , len - 1);
	size_t secondlen = (*num - '0')*pow(10, len - 2)*(len-1);
	return firstlen + secondlen+_numberHasOne(num + 1);
}

int main()
{
	cout << numberHasOne(21345) << endl;
	return 0;
}
