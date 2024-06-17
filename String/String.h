//String.h
#pragma once
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

String operator+(const String& left, const String& right);

bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);
bool operator >(const String& left, const String& right);
bool operator <(const String& left, const String& right);
bool operator >=(const String& left, const String& right);
bool operator <=(const String& left, const String& right);

std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);
