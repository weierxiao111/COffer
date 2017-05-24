#include <stdio.h>
#define ESP 0.0000001

typedef enum bool{
	false = 0,
	true = 1
}bool;        

bool value_num = false;   //����һ��ȫ�ֱ�������������ȷʱ���ص�0�ʹ���ʱ���ص�0
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
		return 0.0;              //ָ���͵�������0ʱ����0��value_numΪfalse˵����ֵ����
	}
	if (exp == 0)
    	return 1.0;
	 else if (exp < 0)
		 unsignedexp = (unsigned int)(-exp);    //ָ��Ϊ����ʱȡ����ֵ
	 else 
         unsignedexp =  (unsigned int)(exp);

	 result = PowWithunsignedexp (Base,unsignedexp);   

	 if(exp < 0)  
		 return (1/result);
	 else
		 return result;
}

double PowWithunsignedexp(double Base, unsigned int exp)  //�õݹ����ݣ���Ϊָ��Ϊ����0��ָ������������ż���������
{
	if (exp == 1)
		return Base;
	else if (exp%2 == 0)
		return PowWithunsignedexp(Base,exp/2)*PowWithunsignedexp(Base,exp/2);   
	else 
		return PowWithunsignedexp(Base,exp/2)*PowWithunsignedexp(Base,(exp/2+1));

}

bool equal(double One, double Two)   //�Ƚϸ������Ĵ�С
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


