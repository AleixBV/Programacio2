#include <stdio.h>


class DynArray
{
private:
	int* data;
	unsigned int allocatedMemory;
	unsigned int numElements;

public:
	DynArray() : data(NULL), allocatedMemory('\0'), numElements('\0'){}

	DynArray(unsigned int memSize) : data(NULL), numElements('\0')
	{
		reallocate(memSize);
	}

	~DynArray()
	{
		if (data != NULL)
		delete[] data;
	}

	
	void reallocate(unsigned int newMemorySize)
	{

	}

	void pushBack(int value)
	{

	}

	int pop()
	{

	}

	void insert(int value, unsigned int position)
	{

	}

	int& operator[] (unsigned int index) //modificar
	{

	}

	const int& operator[] (unsigned int index) const //lectura
	{

	}
};