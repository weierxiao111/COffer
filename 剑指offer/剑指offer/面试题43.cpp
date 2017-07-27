#include <iostream>
using namespace std;

void PrintProbities(int n)
{
	const int value = 6;
	//probities是和为index出现的次数，+1可以使下标对应
	int *probities[2];
	probities[0] =  new int[value*n + 1]; 
	probities[1] = new int[value*n + 1];

	for (int i = 0; i < value*n+1; ++i)
	{
		probities[0][i] = 0;
		probities[1][i] = 0;
	}

	//第1次1~6的次数为1 
	int flag = 0;
	for (int i = 1; i <= value; ++i)
		probities[flag][i] = 1;
	//2到n次
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)  //i个色子最小值为i
			probities[1 - flag][j] = 0;
		for (int k = i; k <= value*i; ++k)  //和的大小从i到value*i有值
		{
			probities[1 - flag][k] = 0;
			for (int m = 1; m <= k&&m <= value; ++m)
			{
				//和为k的数次数是和为k-1,k-2,...k-6总和
				probities[1 - flag][k] += probities[flag][k - m];
			}
		}
		flag = 1 - flag;
	}

	double total = pow(value, n);
	for (int i = n; i <= n*value; ++i)
	{
		cout << "和为i出现的概率是" << probities[flag][i] / total << endl;
	}
	delete []probities[0];
	delete []probities[1];
}

//int main()
//{
//	PrintProbities(6);
//	return 0;
//}