#include <iostream>
using namespace std;

//������������������ظ������֣��ȷ�Ϊ�������飬���ֻ�
void GetTwoDiffNum(int *arr, int sz, int &num1, int &num2)
{
	if (NULL == arr || sz < 2)
		return;
	int diffbit = 0;

	//diffbit ������û�г������ε����ֻ�Ľ��������Ϊ0
	for (int i = 0; i < sz; ++i)
	{
		diffbit ^= arr[i]; 
	}

	int n = 0;
	//diffbit�����ƶ�nλΪ1������������λ�϶���ͬ����Ϊ�ж�׼��
	while ((diffbit & 0x1) != 1)  
	{
		diffbit >>= 1;  //ע�� �� >>=
		n++;
	}
	num1 = 0;
	num2 = 0;
	//�ֳ������ֽ����ֻ�
	for (int j = 0; j < sz; ++j)
	{
		if ((arr[j] >> n) & 0x1)
		{
			num1 ^= arr[j];
		}
		else
			num2 ^= arr[j];
	}
}

//int main()
//{
//	int num1, num2;
//	int arr[] = { 1,1,2,2,3,3,4,5,5,6,6,8,8,9,9,7 };
//	GetTwoDiffNum(arr, sizeof(arr) / sizeof(arr[0]), num1, num2);
//	cout << num1 << " " << num2 << endl;
//	return 0;
//}