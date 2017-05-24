#include <stdio.h>
#define ESP 0.0000001

typedef enum bool{
	false = 0,
	true = 1
}bool;        

bool value_num = false;   //定义一个全局变量用来区分正确时返回的0和错误时返回的0
double PowWithunsignedexp(double Base, unsigned int exp);
bool equal(double One, double Two);

double MyPow (double Base, int exp)
{
	bool value_num = true;
	double result;
	unsigned int unsignedexp;
	if ( equal(Base,0.0) && exp == 0)
	{
		value_num = false;
		return 0.0;              //指数和底数都是0时返回0，value_num为false说明传值错误
	}
	if (exp == 0)
    	return 1.0;
	 else if (exp < 0)
		 unsignedexp = (unsigned int)(-exp);    //指数为负数时取绝对值
	 else 
         unsignedexp =  (unsigned int)(exp);

	 result = PowWithunsignedexp (Base,unsignedexp);   

	 if(exp < 0)  
		 return (1/result);
	 else
		 return result;
}

double PowWithunsignedexp(double Base, unsigned int exp)  //用递归求幂，因为指数为大于0的指数，有奇数和偶数两种情况
{
	if (exp == 1)
		return Base;
	else if (exp%2 == 0)
		return PowWithunsignedexp(Base,exp/2)*PowWithunsignedexp(Base,exp/2);   
	else 
		return PowWithunsignedexp(Base,exp/2)*PowWithunsignedexp(Base,(exp/2+1));

}

bool equal(double One, double Two)   //比较浮点数的大小
{
	if ((One - Two) <= ESP && (Two - One) <= ESP)
		return true;
	return 
		false;
}


int main()
{
	double ret;
	ret = MyPow(-1.0,3);
	ret = MyPow(0.0,3);
	ret = MyPow(0.0,0);
	ret = MyPow(-2.0,4);
	ret = MyPow(-3.0,3);
	ret = MyPow(5.0,3);
	ret = MyPow(5.0,-3);
	
	return 0;
}


