#ifndef _String_
#define _String_

#include <string.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

#define TMP_STRING_SIZE 4096

class String
{
public:

	unsigned int size;//of memory
	char* string;


	String();

	String(const char* format, ...);

	String(const String& s);

	~String();

	//Operators
	bool operator==(const String& s) const;

	bool operator==(const char* s) const;

	bool operator!=(const String& s) const;

	bool operator!=(const char* s) const;

	const String operator=(const String& s);

	const String operator=(const char* s);

	const String& operator+=(const String& s);

	const String& operator+=(const char* s);

	//Utility
	unsigned int length() const;

	unsigned int capacity() const;

	const char* getString() const;

	void clear();
};

#endif