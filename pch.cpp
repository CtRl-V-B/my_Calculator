#include "pch.h"        //函数原型的头文件
#include <iostream>
#include <cstdlib>      //system函数
#include <cstdio>
#include <iomanip>     //格式化输出
#include <windows.h>

void showMenu(int n)
{
	system("cls");

	printf("计算器 v0.1      Test Version\n\n");
	printf("******************************\n");
	printf("1. +                         *\n");
	printf("2. -                         *\n");
	printf("3. *                         *\n");
	printf("4. /                         *\n");
	printf("5. mod求模运算               *\n");
	printf("6. 求x的y次幂                *\n");
	printf("7. 求x的平方根               *\n");
	printf("8. 求x的绝对值               *\n");
	printf("******************************\n\n");

	if (n == 0)
		return;
	read();
}


//读取函数
void read()
{
	char oper; //符号
	double a = 0, b = 0; //操作数
	int j = 0; //计数器
	
	//输入符号
	do
	{
		printf("请输入运算符号：______\b\b\b\b\b\b\a");
		std::cin >> oper;

		if (j) //j非0则输入错误
		{
			printf("运算符号输入错误！请重新输入！\n");
			system("pause");
			showMenu(0);
		}
		j++; //计数器递增1
	} 
	while (oper > '9' || oper < '1');

	//输入操作数
	printf("请输入操作数：\n1.运算符号为1-6 请输入两个操作数\n2.运算符号为6-8 请输入一个操作数\n");
	if (oper > '6')
		std::cin >> a;
	else
		std::cin >> a >> b;
	
	//根据符号调用相应函数
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
		_div(a, b);
		break;

	case '5':
		_mod(a, b);
		break;

	case '6':
		_pow(a, b);
		break;

	case '7':
		_sqrt(a);
		break;

	case '8':
		_abs(a);
		break;
	}

}


//加法函数
template <typename T>
void add(T a, T b)
{
	std::cout << a + b << std::endl;
	system("pause");
}

//减法函数
template <typename T>
void sub(T a, T b)
{
	std::cout << a - b << std::endl;
	system("pause");
}

//乘法函数
template <typename T>
void multi(T a, T b)
{
	std::cout << a * b << std::endl;
	system("pause");
}

//除法函数
template <typename T>
void _div(T a, T b)
{
	using namespace std;
	if (b == 0)     //判断除数是否非0
		printf("除数不能为0！\n");
	else
		cout << fixed << setprecision(6) << a * 1.0 / b << endl;
	system("pause");
}

//mod函数
void _mod(long long a, long long b)
{
	std::cout << a % b << std::endl;
	system("pause");
}

//求幂函数
template <typename T>
void _pow(T a, T b)
{
	double ans = 1;
	
	for (int i = 0; i < b; i++)
		ans *= a;
	
	std::cout << ans << std::endl;
	system("pause");
}

//求平方根函数
template <typename T>
void _sqrt(T a)
{
	bool pd = false;           //判断是否有平方根

	for (int i = 0; i <= a; i++)
		if (i * i == a)
		{
			printf("%d %d\n", i, -i);
			pd = true;
			break;
		}

	if (!pd)
		printf("此数没有平方根\n\n");
	system("pause");
}

template <typename T>
void _abs(T a)
{
	if (a >= 0)       //≥0，直接输出
		std::cout << a << std::endl;

	else              //＜0，输出相反数
		std::cout << -a << std::endl;
	system("pause");
}

void fac(int a)
{
	unsigned long long ans = 1; //存放结果

	for (int i = 1; i <= a; i++) //计算
		ans *= i;

	std::cout << ans << std::endl; //输出
	system("pause");
}



void work()
{
	for (int i = 1; true; i++)
	{
		showMenu(i);

		bool pd = _test();  //判断是否继续

		if (!pd)
			break;
	}

	printf("正在退出计算器...\n\n");
	Sleep(1000);

	return;  //进程退出
}

bool _test()
{
	printf("您想要退出计算器吗？\n");
	printf("退出请按0，继续请按1.\n");

	int n;

	std::cin >> n;

	return n;
}