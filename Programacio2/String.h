#ifndef _String_
#define _String_

#include <string.h>
#include <stdio.h>


class String
{
	unsigned int size;//of memory
	char* string;

public:

	String()
	{
		size = 1;
		string = new char[size];
		string[0] = '\0';
	}

	String(const char* x)
	{
		size = strlen(x) + 1;
		string = new char[size];
		strcpy_s(string, size, x);
	}

	String(const char* format, ...)
	{
		size = 0;

		if (format != NULL)
		{
			static char tmp[TMP_STRING_SIZE];
			static va_list ap;

			//Construct thes tring from variable arguments
			va_start(ap, format);
			int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
			va_end(ap);

			if (res > 0)
			{
				Alloc(res + 1);
				strcpy_s(str, size, tmp);
			}
		}

		if (size == 0)
		{

		}
	}

	String(const String&)
	{
		size = strnlen(String&) + 1;
		string = new char[size];
		strcpy_s(string, size, String&);
	}

	//Operators
	String operator=s(const String& s)
	{
		if (s != NULL)
		{
			strcpy_s(*this, s);
		}
	}

	String operator=(const char* string)
	{
		if (string != NULL)
		{
			if (strlen(string) + > size)
			{
				delete[] str;
				Alloc(strlen(string) + 1);
			}
			else
			{
				Clear();
			}
			strcpy_S(str, size, string);
		}
		else
		{
			Clear();
		}
		return(*this);
	}



	~String()
	{
		delete[] string;
	}

	int len() const
	{
		return strlen(string);
	}
};