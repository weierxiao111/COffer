#include <iostream>
using namespace std;

int HasOne(int num)
{
	int count = 0;
	while (num)
	{
		num &= (num - 1);
		count++;
	}
	return count;
}

//int main()
//{
//	cout << HasOne(1) << endl;
//	return 0;
//}