#include <iostream>
using namespace std;

void PrintProbities(int n)
{
	const int value = 6;
	//probities�Ǻ�Ϊindex���ֵĴ�����+1����ʹ�±��Ӧ
	int *probities[2];
	probities[0] =  new int[value*n + 1]; 
	probities[1] = new int[value*n + 1];

	for (int i = 0; i < value*n+1; ++i)
	{
		probities[0][i] = 0;
		probities[1][i] = 0;
	}

	//��1��1~6�Ĵ���Ϊ1 
	int flag = 0;
	for (int i = 1; i <= value; ++i)
		probities[flag][i] = 1;
	//2��n��
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)  //i��ɫ����СֵΪi
			probities[1 - flag][j] = 0;
		for (int k = i; k <= value*i; ++k)  //�͵Ĵ�С��i��value*i��ֵ
		{
			probities[1 - flag][k] = 0;
			for (int m = 1; m <= k&&m <= value; ++m)
			{
				//��Ϊk���������Ǻ�Ϊk-1,k-2,...k-6�ܺ�
				probities[1 - flag][k] += probities[flag][k - m];
			}
		}
		flag = 1 - flag;
	}

	double total = pow(value, n);
	for (int i = n; i <= n*value; ++i)
	{
		cout << "��Ϊi���ֵĸ�����" << probities[flag][i] / total << endl;
	}
	delete []probities[0];
	delete []probities[1];
}

//int main()
//{
//	PrintProbities(6);
//	return 0;
//}