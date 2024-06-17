//String
#include "stdafx.h"

class String
{
private:
	char* str;
	int size;
public:
	const char* get_str()const;
	char* get_str();
	const int get_size()const;
	void set_str(char* str);
	void set_size(int size);


	explicit String(int size = DEFAULT_SIZE);
	String(const char* str);
	String(const String& Str);
	~String();

	String& operator=(const String& right);

	void print()const;
};

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
	//str = new char[size] {};
	//this->size = size;
	cout << "DefaultConstractor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	/*int size = 0; for (size = 0; str[size] != '\0'; size++){}
	this->size = ++size;
	this->str = new char[this->size] {};
	for (int i = 0; i < size; i++) this->str[i] = str[i];*/
	cout << "Constractor:\t" << this << endl;
}
String::String(const String& Str) :String(Str.str)
{
	/*this->size = Str.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = Str.str[i];*/
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


String operator+(const String& left, const String& right);

bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);
bool operator >(const String& left, const String& right);
bool operator <(const String& left, const String& right);
bool operator >=(const String& left, const String& right);
bool operator <=(const String& left, const String& right);

std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);

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