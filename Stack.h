#pragma once 
#include <iostream>
#include <math.h>
using namespace std;

#define MaxLen 201

template <class T>
class TStack
{
private:
	int MaxSize;
	int Index; // количество элементов в стеке в данный момент 
	T *mas;
public:
	TStack(int len = 10);
	~TStack(); // деструктор 
	TStack(const TStack& s);
	TStack& operator=(const TStack& s);
	bool IsEmpty();
	bool IsFull();
	T Top();
	T Pop();
	void Push(const T& n);
	int DetectorOfBrackets2007(char *str);
	void Clear()
	{
		Index = -1;
	}
};

template <class T>
TStack <T>::TStack(int len = 10)
{
	MaxSize = 10;
	Index = -1;
	if (len <= 0) throw len;
	mas = new T[MaxSize];
}

template <class T>
TStack <T>:: ~TStack()
{
	delete[]mas;
}

template <class T>
TStack <T>::TStack(const TStack& s)
{
	MaxSize = s.MaxSize;
	Index = s.Index;
	mas = new T[MaxSize];
	for (int i = 0; i <= Index; i++)
		mas[i] = s.mas[i];
}

template <class T>
TStack <T>& TStack<T>::operator=(const TStack& s)
{
	if (MaxSize != s.MaxSize)
	{
		delete[]mas;
		MaxSize = s.MaxSize;
	}
	Index = s.Index;
	for (int i = 0; i <= Index; i++)
		mas[i] = s.mas[i];
	return *this;
}

template <class T>
bool TStack <T>::IsEmpty()
{
	return Index == -1;
}

template <class T>
bool TStack <T>::IsFull()
{
	return Index == MaxSize-1;
}

template <class T>
T TStack <T>::Top()
{
	if (Index <0)
		throw Index;
	return mas[Index];
}

template <class T>
T TStack <T>::Pop()
{
	if (Index < 0)
		cout<<"kek";
	return mas[Index--];
}

template <class T>
void TStack <T>::Push(const T& n)
{
	if (Index == MaxSize - 1)
		throw Index;
	mas[++Index] = n;

}

template <class T>
int TStack <T>::DetectorOfBrackets2007(char *str)
{
	TStack <char> S(10);
	int i = 0;
	while (str[i] != "\0")
	{
		if (str[i] == "(")
			s.Push("(");
		if (str[i] == ")")
		{
			if (IsEmpty)
				return 0;
			s.Pop()
		};
		i++
	};
	if (s.IsEmpty())
		return 1;
	else return 0;
}

//----------------------------------------------------------------------------------

class TParser
{
private:
	TStack<char> st_c;
	TStack<double> st_d;
	char inf[MaxLen];
	char post[MaxLen];
public:
	TParser(char *s):st_d(100),st_c(100)
	{
		if (s == NULL) 
			inf [0] = '\0';
		else 
			strcpy_s(inf,s);
	}
	int Priority(char ch)
	{
		int n;
		switch (ch)
		{
		case '(': return 0;
		case ')': return 0;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		default: return -1;
		}
	}
	bool IsOper(char ch)
	{
		if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^'))
			return true;
		else return false;
	}
	bool IsNumber(char ch)
	{
		if ((ch>='0' && ch<='9'))
			return true;
		else return false;
	}
	double ExNumber(char *s, int& len)
	{
		int i = 0;
		double tmp = atof(s);
		while (s[i]!='\0')
			if (IsNumber(s[i]))
				i++;
			else break;
			len = i;
			return tmp;
	}

	void InfToPost()
	{
		int i = 0; int j = 0;
		st_c.Push('=');
		while (inf[i]!='\0')
		{
			if (IsNumber(inf[i]))
			{
				post[j] = inf[i];
				j++;
			}
			else if (inf[i] == '(')
				st_c.Push(inf[i]);
			else if (inf[i]==')')
			{
				char tmp = st_c.Pop();
				while (tmp!='(')
				{
					post[j] = tmp;
					j++;
					tmp = st_c.Pop();
				}
			}
			else if(IsOper(inf[i]))
			{
				char tmp = st_c.Pop();
				while (Priority(tmp)>=Priority(inf[i]))
				{
					post[j] = tmp;
					i++;
					tmp = st_c.Pop();
				}
				st_c.Push(tmp);
				st_c.Push(inf[i]);
			}
			i++;
		}
	}

	double CalcPost()
	{
		int i = 0; st_d.Clear();
		while ((post[i]!='\0')&&(post[i]!='='))
		{
			if (IsNumber(post[i]))
				st_d.Push(post[i] - '0');
			if (IsOper(post[i]))
			{
				double op1,op2;
				op2 = st_d.Pop();
				op1 = st_d.Pop();
				switch (post[i])
				{
				case '+': st_d.Push(op1+op2);
						break;
					case '-': st_d.Push(op1-op2);
						break;
					case '*': st_d.Push(op1*op2);
						break;
					case '/': st_d.Push(op1/op2);
						break;
					case '^': st_d.Push(pow(op1,op2));
						break;
				}
			}
			i++;
		}
		return st_d.Pop();
	}


	double CalcP()
	{
		st_d.Clear();
		st_c.Clear();
		st_c.Push('=');
		int i = 0;
		int len;
		while (inf[i]!='\0')
		{
			if (IsNumber(inf[i]))
			{
				double tmp = ExNumber(&inf[i], len);
				st_d.Push(tmp);
				i+=len - 1;
			}
			else if (inf[i]=='(')
				st_c.Push(inf[i]);
			else if (inf[i]==')')
			{
				char tmpc = st_c.Pop();
				while (tmpc!='(')
				{
					double op2 = st_d.Pop();
					double op1 = st_d.Pop();
					switch (tmpc)
					{
					case '+': st_d.Push(op1+op2);
						break;
					case '-': st_d.Push(op1-op2);
						break;
					case '*': st_d.Push(op1*op2);
						break;
					case '/': st_d.Push(op1/op2);
						break;
					case '^': st_d.Push(pow(op1,op2));
						break;
					}
					tmpc = st_c.Pop();
				}
			}
			else if (IsOper(inf[i]))
			{
				char tmpch = st_c.Pop();
				while (Priority(tmpch)>=Priority(inf[i]))
				{
					double op2 = st_d.Pop();
					double op1 = st_d.Pop();
					switch (tmpch)
					{ 
						case '+': st_d.Push(op1+op2);
						break;
					case '-': st_d.Push(op1-op2);
						break;
					case '*': st_d.Push(op1*op2);
						break;
					case '/': st_d.Push(op1/op2);
						break;
					case '^': st_d.Push(pow(op1,op2));
						break;
					}
					tmpch = st_c.Pop();
				}
				st_c.Push(tmpch);
				st_c.Push(inf[i]);
			}
			i++;
		}
		char tmpch = st_c.Pop();
		while (tmpch!='=')
		{
			double op2 = st_d.Pop();
			double op1 = st_d.Pop();
			switch (tmpch)
			{
				case '+': st_d.Push(op1+op2);
						break;
					case '-': st_d.Push(op1-op2);
						break;
					case '*': st_d.Push(op1*op2);
						break;
					case '/': st_d.Push(op1/op2);
						break;
					case '^': st_d.Push(pow(op1,op2));
						break;
			}
			tmpch = st_c.Pop();
		}
		return st_d.Pop();
}
	};