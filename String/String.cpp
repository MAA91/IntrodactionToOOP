//String.cpp
#include"String.h"

const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
const int String::get_size()const
{
	return size;
}
void String::set_str(char* str)
{
	this->str = str;
}
void String::set_size(int size)
{
	this->size = size;
}


String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefaultConstractor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++) this->str[i] = str[i];
	cout << "Constractor:\t" << this << endl;
}
String::String(const String& Str):String(Str.str)
{
	for (int i = 0; i < size; i++)
		this->str[i] = Str.str[i];
	cout << "Constractor:\t" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destractor:\t" << this << endl;
}

String& String::operator=(const String& right)
{
	if (this == &right) return *this;
	delete[] str;
	this->size = right.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		str[i] = right.str[i];
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}

void String::print()const
{
	cout << str << endl;
}