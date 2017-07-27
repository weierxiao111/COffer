#include <iostream>
using namespace std;

//方法一，运用构造函数
class SUM{
public:
	SUM()
	{
		n++;
		sum += n;
	}

	static size_t ret()
	{
		return sum;
	}
private:
	static size_t sum;
	static size_t n;
};

size_t SUM::sum = 0;
size_t SUM::n = 0;

//方法二，用两个函数模板递归
template <size_t n>
struct SUM2 {
	enum sum {N = SUM2<n-1>::N + n};
};

template <>
struct SUM2<1>{
	enum sum  { N = 1 };
};

//方法三  运用函数指针 fun[2] 以及fun[!!n]的判断方法选择函数
size_t SUM3_ret(size_t n)
{
	return 0;
}
size_t SUM3(size_t n)
{
	size_t(*f[2])(size_t) = {SUM3_ret,SUM3};
	return f[!!n](n - 1)+n;
}

//int main()
//{
//	SUM a[100];
//	cout << SUM::ret() << endl;
//	cout << SUM2<100>::N << endl;
//	cout << SUM3(100)<< endl;
//	return 0;
//}