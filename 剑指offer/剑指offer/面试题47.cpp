#include <iostream>
using namespace std;
//�ֻ����ģ��û�н�λ�ļӷ�   &�������Ҫ����λ����һλ  �ݹ����ѭ��
int ADD(int num1, int num2)
{
	int sum = 0;
	sum = num1 ^ num2;
	int add = (num1 & num2)<<1;
	if (add == 0)
		return sum;
	else
		return ADD(sum,add);
}

//int main()
//{
//	cout << ADD(-23,17)<<endl;
//	return 0;
//}