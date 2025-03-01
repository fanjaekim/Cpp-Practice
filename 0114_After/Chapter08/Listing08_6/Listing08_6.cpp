﻿// 구조체에 대한 참조
#include <iostream>
#include <string>
struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws &ft);
void set_pc(free_throws &ft);
free_throws & accmulate(free_throws &target, const free_throws &source);

int main()
{
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Max", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };

	// 초기화하지 않음.
	free_throws dup;
	set_pc(one);
	display(one);
	accmulate(team, one);
	display(team);

	// 리턴 값을 매개변수로 사용한다.
	display(accmulate(team, two));
	accmulate(accmulate(team, three), four);
	display(team);

	// 리턴 값을 대입 값으로 사용한다.
	dup = accmulate(team, five);
	std::cout << "team 출력 : \n";
	display(team);
	std::cout << "대입 이후 dup 출력: \n";
	display(dup);
	set_pc(four);

	// 문제의 소지가 있는 대입
	accmulate(dup, five) = four;
	// five의 데이터를 dup에 더한다.
	// four의 내용으로 dup의 내용을 덮어쓴다.

	std::cout << "문제 소지가 있는 대입 이후 dup 출력 : \n";
	display(dup);
	return 0;
}

void display(const free_throws &ft)
{
	using std::cout;
	cout << "Name : " << ft.name << '\n';
	cout << "Made : " << ft.made << '\t';
	cout << "Attempts : " << ft.attempts << '\t';
	cout << "Percent : " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
	{
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	}
	else
	{
		ft.percent = 0;
	}
}

free_throws &accmulate(free_throws &target, const free_throws &source) 
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}
