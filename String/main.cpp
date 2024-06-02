//String
#include "stdafx.h"

class String
{
private:
	char* str;
public:
	char* get_str()
	{
		return str;
	}
	void set_str(char* str)
	{
		this->str = str;
	}

	String()
	{
		str = new char[40];
		cout << "DefaultConstractor:\t" << this << endl;
	}
	String(const char* str)
	{
		int size = 0; for (size = 0; str[size] != '\0'; size++){}
		this->str = new char[++size];
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		cout << "Constractor:\t" << this << endl;
	}
	String(int size)
	{
		this->str = new char[size + 1];
		this->str[size] = '\0';
		cout << "SizeConstractor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destractor:\t" << this << endl;
	}

	void print()const
	{
		for (int i = 0; str[i] != '\0'; i++)
			cout <<  str[i];
		cout << endl;
	}
};

String operator+(String& left, String& right)
{
	int size = 0; 
	for (;*(left.get_str() + size) != '\0'; size++);
	for (int i = 0; *(right.get_str() + i) != '\0'; size++, i++);
	String result(size);
	int i = 0;
	for (; *(left.get_str() + i) != '\0'; i++)
		*(result.get_str() + i) = *(left.get_str() + i);
	for (int j = 0; *(right.get_str() + j) != '\0'; j++)
		* (result.get_str() + i + j) = *(right.get_str() + j);
	return result;
}

void main()
{	
	setlocale(0, "");
	String str;
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	str3.print();
}