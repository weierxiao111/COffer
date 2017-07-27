#include <iostream>
using namespace std;
//抑或可以模拟没有进位的加法   &计算出需要进的位左移一位  递归或者循环
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