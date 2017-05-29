#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
	if (num2 == 0)
		return num1;
	int temp = num1;
	num1 = num1^num2;
	num2 = (temp & num2)<< 1;
	return Add(num1, num2);
}

class Temp {
public:
    Temp()
	{
		Num++;
		Sum += Num;
 	}

	static void  Init()
	{
		Num = 0;
		Sum = 0;
	}

	static size_t  GetSum()
	{
		return Sum;
	}
private:
	static size_t Num;
	static size_t Sum;
};

size_t Temp::Num = 0;
size_t Temp::Sum = 0;

size_t Sum_matain(size_t n)
{
	Temp::Init();
	Temp* t = new Temp [n];
	delete[]t;
	return Temp::GetSum();
}



int main()
{
	cout << Sum_matain(10) << endl;
	system("pause");
	return 0;
}
