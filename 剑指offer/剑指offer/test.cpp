#include <iostream>
using namespace std;

const int max_value = 6;
void Probality(int num, int *proarr);
void Probality(int num, int cur, int sum, int* proarr);
void PrintProbablity(int n)
{
	if (n < 1)
		return;
	int maxProbality = max_value*n;
	int *ProbalityArr = new int[maxProbality - n + 1];
	/*memset(ProbalityArr, 0, sizeof(int)*(maxProbality - n + 1));*/
	for (int j = n; j <= maxProbality; ++j)
		ProbalityArr[j - n] = 0;

	Probality(n, ProbalityArr);
	float  total = pow(max_value, n);

	for (int i = n; i <= maxProbality; ++i)
	{
		cout << "和为" << n << "的出现的概率为" << ProbalityArr[i - n] / total << " ";
		cout << endl;
	}
	cout << endl;
	delete []ProbalityArr;
}

void Probality(int num, int *proarr)
{
	for (int i = 1; i <= max_value; ++i)
		Probality(num, num, i, proarr);
}

void Probality(int num, int cur, int sum, int* proarr)
{
	if (cur == 1)
		proarr[sum - max_value]++;
	else
	{
		for (int i = 1; i <= max_value; ++i)
			Probality(num, cur-1, i+sum, proarr);
	}
}
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


int main()
{
	PrintProbablity(3);
	system("pause");
	return 0;
}
