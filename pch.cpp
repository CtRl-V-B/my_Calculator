// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

void showMenu(int n)
{
	using std::cout;
	using std::endl;

	if (n == 1)
		cout << "欢迎来到计算器！\n";
	cout << "************************\n";
	cout << "1. +                   *\n";
	cout << "2. -                   *\n";
	cout << "3. *                   *\n";
	cout << "4. /                   *\n";
	cout << "5. 求x的y次幂           *\n";
	cout << "6. |x|                 *\n";
	cout << "7. !x                  *\n";
	cout << "8. x的平方根            *\n";
	cout << "************************\n";

	if (n == 0)
		return;
	read();
}

void read()
{
	char oper;
	double a = 0, b = 0;
	int i = 0;

	std::cout << "\n请输入运算符号：\n";
	do
	{
		if (i != 0)
			std::cout << "\n运算符号错误，请重新输入！\n";
		std::cin >> oper;
		
		i++;
	} while (oper > '8' || oper < '1');

	std::cout << "\n请输入操作数：\n1-5 请输入两个操作数\n6-8 请输入一个操作数\n";
	std::cin >> a;
	if (oper <= '5')
		std::cin >> b;

	switch (oper)
	{
	case '1':
		add(a, b);
		break;

	case '2':
		sub(a, b);
		break;

	case '3':
		multi(a, b);
		break;

	case '4':
		_Div(a, b);
		break;

	case '5':
		_Pow(a, int(b));
		break;

	case '6':
		_Abs(a);
		break;

	case '7':
		_Fac(int(a));
		break;

	case '8':
		_Sqrt(int(a));
		break;

	default:
		std::cout << "Error!\n";
		break;
	}

	system("pause");
}

void work()
{
	for (int i = 1;; i++)
	{
		system("cls");

		showMenu(i);

		if (!pd())
		{
			std::cout << "正在退出计算器";
			Sleep(500);
			std::cout << ".";
			Sleep(500);
			std::cout << ".";
			Sleep(500);
			std::cout << ".";
			Sleep(500);
			
			system("cls");
			return;
		}

		system("cls");
	}
}

bool pd()
{
	int n, i = 0;
	system("cls");

	std::cout << "\n您想退出计算器程序吗？\n1.继续\n0.退出\n";
	do
	{
		if (i)
			std::cout << "输入错误，请重新输入！\n";
		std::cin >> n;

		i++;
	} while (n != 0 && n != 1);

	return n;
}


void add(double a, double b)
{
	std::cout << a + b << std::endl;
}

void sub(double a, double b)
{
	std::cout << a - b << std::endl;
}

void multi(double a, double b)
{
	std::cout << a * b << std::endl;
}

void _Div(double a, double b)
{
	using namespace std;

	if (b == 0)
		cout << "除数不能为0!\n";
	else
		cout << fixed << setprecision(6) << a * 1.0 / b << endl;
}

void _Pow(double a, int b)
{
	double ans = 1;

	if (b > 0)
		for (int i = 1; i <= b; i++)
			ans *= a;
	if (b == 0 && a != 0)
		ans = 1;
	if (b == 0 && a == 0)
		ans = 0;

	std::cout << ans << std::endl;
}

void _Abs(double a)
{
	std::cout << ((a > 0) ? a : -a) << std::endl;
}

void _Fac(int a)
{
	double ans = 1;

	for (int i = 1; i <= a; i++)
		ans *= i;

	std::cout << ans << std::endl;
}

void _Sqrt(int a)
{
	if (a < 0)
	{
		std::cout << "负数没有平方根！\n";
		return;
	}
	if (a == 0)
	{
		std::cout << 0 << std::endl;
		return;
	}

	for (int i = 1; i <= a; i++)
		if (i * i == a)
		{
			std::cout << i << ' ' << -i << std::endl;
			return;
		}
}
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
