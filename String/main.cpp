//String
#include "stdafx.h"

class String
{
private:
	char* str;
	int size;
public:
	const char* get_str()const
	{
		return str;
	}
	const int get_size()const
	{
		return size;
	}
	void set_str(char* str)
	{
		this->str = str;
	}
	void set_size(int size)
	{
		this->size = size;
	}


	String(int size = DEFAULT_SIZE)
	{
		str = new char[size] {};
		this->size = size;
		cout << "DefaultConstractor:\t" << this << endl;
	}
	String(const char* str)
	{
		int size = 0; for (size = 0; str[size] != '\0'; size++){}
		this->size = ++size;
		this->str = new char[this->size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		cout << "Constractor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destractor:\t" << this << endl;
	}

	void print()const
	{
		cout << str << endl;
	}
};

String operator+(String& left, String& right)
{
	int size = 0; 
	for (;*(left.get_str() + size) != '\0'; size++);
	for (int i = 0; *(right.get_str() + i) != '\0'; size++, i++);
	char* str = new char[++size] {};
	int i = 0;
	for (; *(left.get_str() + i) != '\0'; i++)
		*(str + i) = *(left.get_str() + i);
	for (int j = 0; *(right.get_str() + j) != '\0'; j++)
		* (str + i + j) = *(right.get_str() + j);
	String result(str);
	return result;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	cout << obj.get_str();
	return os;
}
std::istream& operator>>(std::istream& is, String& obj)
{
	char* buf_str = new char[256] {};
	is.getline(buf_str, 256);
	int size = 0;
	for (; buf_str[size] != '\0'; size++);
	obj.set_size(size);
	delete[] obj.get_str();
	obj.set_str(buf_str);
	return is;
}
void main()
{	
	setlocale(0, "");
	String str;
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
}