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
	char* get_str()
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


	explicit String(int size = DEFAULT_SIZE) :size(size), str(new char[size] {})
	{
		//str = new char[size] {};
		//this->size = size;
		cout << "DefaultConstractor:\t" << this << endl;
	}
	String(const char* str):size(strlen(str)), str(new char[size] {})
	{
		/*int size = 0; for (size = 0; str[size] != '\0'; size++){}
		this->size = ++size;
		this->str = new char[this->size] {};*/
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		cout << "Constractor:\t" << this << endl;
	}
	String(const String& Str):size(Str.size), str(new char[size] {})
	{
		/*this->size = Str.size;
		this->str = new char[size] {};*/
		for (int i = 0; i < size; i++)
			this->str[i] = Str.str[i];
		cout << "Constractor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destractor:\t" << this << endl;
	}

	String& operator=(const String& right)
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

	void print()const
	{
		cout << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size() - 1; i++)
		result.get_str()[i] = *(left.get_str() + i);
	for (int i = 0; i < right.get_size() - 1; i++)
		result.get_str()[left.get_size() + i - 1] = *(right.get_str() + i);
	return result;
}

bool operator==(const String& left, const String& right)
{
	if (left.get_size() != right.get_size())
		return false;
	for (int i = 0; i < left.get_size(); i++)
		if (*(left.get_str() + i) != *(right.get_str() + i))
			return false;
	return true;
}
bool operator!=(const String& left, const String& right)
{
	return !(left == right);
}
bool operator >(const String& left, const String& right)
{
	for (int i = 0; i < (left.get_size() > right.get_size() ? right.get_size() : left.get_size()); i++)
		if (*(left.get_str() + i) > *(right.get_str() + i))
			return true;
	return (left.get_size() > right.get_size() ? true : false);
}
bool operator <(const String& left, const String& right)
{
	return (!(left > right) && left != right);
}
bool operator >=(const String& left, const String& right)
{
	return (left > right || left == right);
}
bool operator <=(const String& left, const String& right)
{
	return (left < right || left == right);
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

//#define CAT_CHECK
#define CONSTRAKTORS_CHEK

void main()
{	
	setlocale(0, "");
#ifdef CAT_CHECK

#endif // CAT_CHECK

#ifdef CONSTRAKTORS_CHEK

#endif // CONSTRAKTORS_CHEK


}