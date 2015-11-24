// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	char st[8] = {'(', '3','+','5',')','*','4','\0'};
	TParser infin(st);
	TParser infin1(st);
	double d;
	d = infin.CalcP();
	cout<<d<<'\0';
	return 0;
}