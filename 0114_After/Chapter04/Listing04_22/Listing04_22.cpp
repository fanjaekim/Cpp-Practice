﻿#include <iostream>
#include <cstring>			// 또는 string.h

#pragma warning (disable:4996)

using namespace std;
char *getname(void);		// 함수 원형
int main()
{
	char *name;				// 포인터를 만들지만 메모리는 대입하지 않는다.

	name = getname();		// 문자열의 주소를 name에 대입한다.
	cout << (int *)name << ": " << name << "\n";
	delete[] name;			// 메모리를 해제한다.

	name = getname();		// 해제한 메모리를 다시 사용한다.
	cout << (int *)name << ": " << name << "\n";
	delete[] name;			// 메모리를 다시 해제한다.
	return 0;
}

char *getname()				// 새 문자열을 가리키는 포인터를 리턴한다.
{
	char temp[80];			// 임시 배열
	cout << "이름을 입력하십시오 : ";
	cin >> temp;
	char *pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);		// 문자열을 더 작은 공간으로 복사한다.

	return pn;				// 함수가 종료될 때 임시배열인 temp는 소멸한다.
}