#include <iostream>
using namespace std;

//n������Χ��0~n-1֮�䣬���ظ�Ԫ��
//ע��ÿ���ƶ����Ԫ���ƶ��������±��Ӧ��λ�ã�ֱ���ҵ��ظ�Ԫ�أ�
//����û����ͬԪ������ƶ�n��,ʱ�临�Ӷ�O(N)
bool repeatnum(int *arr, int sz)
{
	if (NULL == arr || sz < 2)
		return false;

	for (int i = 0; i < sz;++i)
	{
		while (arr[i] != i)  //�������±꽻��λ��
		{
			//������λ���ϵ�Ԫ���뵱ǰԪ����ͬ���ҵ��ظ�Ԫ��
			if (arr[i] == arr[arr[i]])  
			{
				cout << arr[i] << endl;
				return true;
			}
			swap(arr[i], arr[arr[i]]); //�ƶ�Ԫ��λ��
		}
	}
	return false;  //û�ҵ��ظ�Ԫ��
}
//int main()
//{
//	int arr[] = {2,4,1,0,3,5,6};
//	int size = sizeof(arr) / sizeof(arr[0]);
//	if (repeatnum(arr, size))
//		cout << "yes" << endl;
//	return 0;
//}