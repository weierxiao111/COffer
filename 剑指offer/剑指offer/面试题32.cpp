#include <iostream>
//1到n中X出现的次数

int Xcount(int n)  //21345
{
	int count = 0;//1的个数
	int i = 1;//当前位
	int current = 0, after = 0, before = 0;
	while ((n / i) != 0) {      //  21345
		current = (n / i) % 10; //当前位数字   5 4 3 1 2
		before = n / (i * 10); //高位数字  2134 213 21 2 0
		after = n - (n / i)*i; //低位数字   0 5 45 345  1345
	  //如果为0,出现1的次数由高位决定,等于高位数字 * 当前位数
		if (current == 0)
			count += before*i;     
		//////如果为1,出现1的次数由高位和低位决定,高位*当前位+低位+1
		else if (current == 1)
			count += before * i + after + 1;
		//如果大于1,出现1的次数由高位决定,//（高位数字+1）* 当前位数
		else {
			count += (before + 1) * i;
		}
		//前移一位
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