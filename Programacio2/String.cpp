#include "String.h"


String::String()
{
	size = 1;
	string = new char[size];
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
			string = new char[res + 1];
			strcpy_s(string, size, tmp);
		}
	}

	if (size == 0)
	{
		string = new char[1];
		clear();
	}
}

String::String(const String& s)
{
	size = strlen(s.string) + 1;
	string = new char[size];
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
		string = new char[s.length() + 1];
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
			string = new char[strlen(s) + 1];
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

String& String::operator+=(const String& a)
{
	if (size < strlen(string) + strlen(a.string))
	{
		char* string2 = new char[strlen(string) + 1];
		strcpy_s(string2, strlen(string) + 1, string);
		size = strlen(string) + strlen(a.string) + 1;
		delete[]string;
		string = new char[size];
		strcpy_s(string, strlen(string2), string2);
	}

	strcat_s(string, strlen(a.string), a.string);
	return (*this);
}

String& String::operator+=(const char* a)
{
	if (a != NULL)
	{
		if (size < strlen(string) + strlen(a))
		{
			char* string2 = new char[strlen(string) + 1];
			strcpy_s(string2, strlen(string) + 1, string);
			size = strlen(string) + strlen(a) + 1;
			delete[]string;
			string = new char[size];
			strcpy_s(string, strlen(string2), string2);
		}

		strcat_s(string, strlen(a), a);
	}
	return (*this);
}

//Utility
unsigned int String::length() const
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
		//delete[] string;
		//string = new char[1];
		string[0] = '\0';
	}

}

