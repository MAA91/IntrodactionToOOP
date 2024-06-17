//String
#include "stdafx.h"
#include "String.h"

#define CAT_CHECK
//#define CONSTRAKTORS_CHEK

void main()
{	
	setlocale(0, "");
#ifdef CAT_CHECK
	String str1 = "Hello";
	cout << str1 << endl;
#endif // CAT_CHECK

#ifdef CONSTRAKTORS_CHEK

#endif // CONSTRAKTORS_CHEK
}

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