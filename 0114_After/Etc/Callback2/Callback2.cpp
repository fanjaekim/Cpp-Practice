﻿#include <iostream>
using namespace std;

// Server //
void For_each(int *begin, int *end, void(*pf)(int))
{
	while (begin != end)
	{
		pf(*begin++); // Client 함수 호출(Callback)
	}
}
void Print1(int n)
{
	cout << n << ' ';
}

void Print2(int n)
{
	cout << n * n << " ";
}

void Print3(int n)
{
	cout << "정수 : " << n << endl;
}

int main()
{
	int arr[5] = { 10, 20, 30, 40 ,50 };

	For_each(arr, arr + 5, Print1); // Print1() 콜백 함수의 주소를 전달
	cout << endl << endl;
	For_each(arr, arr + 5, Print2); // Print2() 콜백 함수의 주소를 전달
	cout << endl << endl;
	For_each(arr, arr + 5, Print3); // Print3() 콜백 함수의 주소를 전달

	return 0;
}