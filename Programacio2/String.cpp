#include "String.h"


String::String()
{
	size = 1;
	alloc(size);
	string[0] = '\0';
}

String::String(const char* format, ...)
{
	size = 0;

	if (format != NULL)
	{
		static char tmp[TMP_STRING_SIZE];
		static va_list ap;

		//Construct the string from variable arguments
		va_start(ap, format);
		int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);

		if (res > 0)
		{
			alloc(res + 1);
			strcpy_s(string, size, tmp);
		}
	}

	if (size == 0)
	{
		alloc(1);
		clear();
	}
}

String::String(const String& s)
{
	size = strlen(s.string) + 1;
	alloc(size);
	strcpy_s(string, size, s.string);
}

String::~String()
{
	delete[] string;
}

//Operators
bool String::operator== (const String& s)const
{
	return strcmp(s.string, string) == 0;
}

bool String::operator== (const char* s)const
{
	if (s != NULL)
	{
		return strcmp(s, string) == 0;
	}
	return false;
}

bool String::operator!=(const String& s)const
{
	return strcmp(s.string, string) != 0;
}

bool String::operator!=(const char* s)const
{
	if (s != NULL)
		return strcmp(s, string) != 0;
	return false;
}

String String::operator=(const String& s)
{
	if ((s.length() + 1) > size)
	{
		alloc(s.length() + 1);
	}
	else
		clear();
	strcpy_s(string, size, s.string);
	return (*this);
}

String String::operator=(const char* s)
{
	if (s != NULL)
	{
		if (strlen(s) + 1 > size)
		{
			alloc(strlen(s) + 1);
		}
		else
			clear();
		strcpy_s(string, size, s);
	}
	else
	{
		clear();
	}
	return (*this);
}

String String::operator+=(const String& s)
{
	size += (s.length() + 1);
	strcat_s(string, size, s.string);
	return (*this);
}

String String::operator+=(const char* s)
{
	if (s != NULL)
	{
		size += (strlen(s) + 1);
		strcat_s(string, size, s);
	}
	else
	{
		clear();
	}
	return (*this);
}

//Utility
int String::length() const
{
	return strlen(string);
}

int String::capacity() const
{
	return size;
}

char* String::getString() const
{
	return (string);
}

void String::clear()
{
	if (string != NULL)
	{
		delete[] string;
		string = new char[1];
	}

}

void String::alloc(unsigned int size)
{
	delete[] string;
	string = new char[size];
}