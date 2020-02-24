#pragma once
#ifndef _PCH_H_
#define _PCH_H_

void showMenu(int n);
void read();
void work();
bool _test();

template <typename T>
void add(T a, T b);

template <typename T>
void sub(T a, T b);

template <typename T>
void multi(T a, T b);

template <typename T>
void _div(T a, T b);

void _mod(long long a, long long b);

template <typename T>
void _pow(T a, T b);

template <typename T>
void _sqrt(T a);

template <typename T>
void _abs(T a);

void fac(int a);

#endif