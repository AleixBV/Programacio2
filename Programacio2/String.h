#ifndef _String_
#define _String_

#include <string.h>


class String
{
	int size;//de memoria
	char* string;

public:

	String()
	{
		size = 1; //pel 0 de la cadena buida
		string = new char[size];
		string[0] = '\0';//escriu en la posicio 0?
	}

	String(const char* x)
	{
		size = strlen(x) + 1;
		string = new char[size];
		strcpy_s(string, size, x);
	}

	String(const char* format, ...)
	{

	}

	String(const String&)
	{
		
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