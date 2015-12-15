// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>
#include <locale.h>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	char st[100];
	int p;
	for (;;)
	{
		cout<<"1 - Ввод выражения\n";
		cout<<"2 - Преобразовать в постфиксную форму записи\n";
		cout<<"3 - Вычислить\n";
		cin>>p;
		switch (p)
		{
		case 1:
			{
			cin>>st;
			break;
			}
		case 2:
			{
			cout<<"Постфиксная форма: \n";
			TParser infin(st);
			infin.InfToPost();
			cout<<infin<<"\0";
			break;
			}
		case 3: 
			{
				TParser infin(st);
				cout<<"\nРезультат выражения: "<<infin.CalcP()<<'\0'<<"\n";
			break;
		}
		}
	}
	return 0;
}
	/*cin>>st;
	TParser infin(st);
	TParser infin1(st);
	cout<<"инфиксная форма записи: "<<st<<endl;
	infin.InfToPost();
	cout<<infin<<"\0";
	double d;
	d = infin.CalcP();
	cout<<"\nРезультат: "<<d<<'\0';
	return 0;
}
*/ 