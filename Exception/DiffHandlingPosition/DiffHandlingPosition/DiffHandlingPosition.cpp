#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char *str)
{
	int len = strlen(str);
	int num = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] <'0' || str[i] >'9')
		{
			throw str[i];
		}
		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7'))); // 문자열을 정수의 형태로 변환하는 문장이다.
	}
	return num;
}

int main(void)
{
	char str1[100];
	char str2[200];

	while (1)
	{
		cout << "두개의 숫자 입력: ";
		cin >> str1 >> str2;

		try 
		{
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch (char ch)
		{
			cout << "문자 " << ch << "가 입력되었습니다." << endl;
			cout << "재입력 진행합니다." << endl << endl;
			// 예외발생시 catch에는 break문이 존재하지 않는다.
			// 예외가 발생하면 해당 영역을 재실행하게 된다.
		}
	}
	cout << "프로그램을 종료합니다." << endl;
	return 0;
}