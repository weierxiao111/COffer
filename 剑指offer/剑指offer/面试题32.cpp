#include <iostream>
//1��n��X���ֵĴ���

int Xcount(int n)  //21345
{
	int count = 0;//1�ĸ���
	int i = 1;//��ǰλ
	int current = 0, after = 0, before = 0;
	while ((n / i) != 0) {      //  21345
		current = (n / i) % 10; //��ǰλ����   5 4 3 1 2
		before = n / (i * 10); //��λ����  2134 213 21 2 0
		after = n - (n / i)*i; //��λ����   0 5 45 345  1345
	  //���Ϊ0,����1�Ĵ����ɸ�λ����,���ڸ�λ���� * ��ǰλ��
		if (current == 0)
			count += before*i;     
		//////���Ϊ1,����1�Ĵ����ɸ�λ�͵�λ����,��λ*��ǰλ+��λ+1
		else if (current == 1)
			count += before * i + after + 1;
		//�������1,����1�Ĵ����ɸ�λ����,//����λ����+1��* ��ǰλ��
		else {
			count += (before + 1) * i;
		}
		//ǰ��һλ
		i = i * 10;
	}
	return count;  //+2135+2140 + 2200+2346 + 10000
}


//int main()
//{
//	std::cout << Xcount(1)<<std::endl;
//	std::cout << Xcount(11) << std::endl;
//	std::cout << Xcount(10) << std::endl;
//	std::cout << Xcount(12) << std::endl;
//	std::cout << Xcount(21345) << std::endl;
//	std::cout << Xcount(100) << std::endl;
//	return 0;
//}