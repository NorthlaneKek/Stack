#pragma once 

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
	T Top();
	void Push(const T& n);
	int DetectorOfBrackets2007(char *str);
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
TStack <T>::TStack& operator=(const TStack& s)
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
		throw Index;
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