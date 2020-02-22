#include "pch.h"        //����ԭ�͵�ͷ�ļ�
#include <iostream>
#include <cstdlib>      //system����
#include <cstdio>
#include <iomanip>     //��ʽ�����
#include <windows.h>

void showMenu(int n)
{
	system("cls");

	printf("������ v0.1      Test Version\n\n");
	printf("******************************\n");
	printf("1. +                         *\n");
	printf("2. -                         *\n");
	printf("3. *                         *\n");
	printf("4. /                         *\n");
	printf("5. mod��ģ����               *\n");
	printf("6. ��x��y����                *\n");
	printf("7. ��x��ƽ����               *\n");
	printf("8. ��x�ľ���ֵ               *\n");
	printf("******************************\n\n");

	if (n == 0)
		return;
	read();
}


//��ȡ����
void read()
{
	char oper; //����
	double a = 0, b = 0; //������
	int j = 0; //������
	
	//�������
	do
	{
		printf("������������ţ�______\b\b\b\b\b\b\a");
		std::cin >> oper;

		if (j) //j��0���������
		{
			printf("�����������������������룡\n");
			system("pause");
			showMenu(0);
		}
		j++; //����������1
	} 
	while (oper > '9' || oper < '1');

	//���������
	printf("�������������\n1.�������Ϊ1-6 ����������������\n2.�������Ϊ6-8 ������һ��������\n");
	if (oper > '6')
		std::cin >> a;
	else
		std::cin >> a >> b;
	
	//���ݷ��ŵ�����Ӧ����
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


//�ӷ�����
template <typename T>
void add(T a, T b)
{
	std::cout << a + b << std::endl;
	system("pause");
}

//��������
template <typename T>
void sub(T a, T b)
{
	std::cout << a - b << std::endl;
	system("pause");
}

//�˷�����
template <typename T>
void multi(T a, T b)
{
	std::cout << a * b << std::endl;
	system("pause");
}

//��������
template <typename T>
void _div(T a, T b)
{
	using namespace std;
	if (b == 0)     //�жϳ����Ƿ��0
		printf("��������Ϊ0��\n");
	else
		cout << fixed << setprecision(6) << a * 1.0 / b << endl;
	system("pause");
}

//mod����
void _mod(long long a, long long b)
{
	std::cout << a % b << std::endl;
	system("pause");
}

//���ݺ���
template <typename T>
void _pow(T a, T b)
{
	double ans = 1;
	
	for (int i = 0; i < b; i++)
		ans *= a;
	
	std::cout << ans << std::endl;
	system("pause");
}

//��ƽ��������
template <typename T>
void _sqrt(T a)
{
	bool pd = false;           //�ж��Ƿ���ƽ����

	for (int i = 0; i <= a; i++)
		if (i * i == a)
		{
			printf("%d %d\n", i, -i);
			pd = true;
			break;
		}

	if (!pd)
		printf("����û��ƽ����\n\n");
	system("pause");
}

template <typename T>
void _abs(T a)
{
	if (a >= 0)       //��0��ֱ�����
		std::cout << a << std::endl;

	else              //��0������෴��
		std::cout << -a << std::endl;
	system("pause");
}

void fac(int a)
{
	unsigned long long ans = 1; //��Ž��

	for (int i = 1; i <= a; i++) //����
		ans *= i;

	std::cout << ans << std::endl; //���
	system("pause");
}



void work()
{
	for (int i = 1; true; i++)
	{
		showMenu(i);

		bool pd = _test();  //�ж��Ƿ����

		if (!pd)
			break;
	}

	printf("�����˳�������...\n\n");
	Sleep(1000);

	return;  //�����˳�
}

bool _test()
{
	printf("����Ҫ�˳���������\n");
	printf("�˳��밴0�������밴1.\n");

	int n;

	std::cin >> n;

	return n;
}