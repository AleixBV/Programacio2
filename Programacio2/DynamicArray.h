#include <stdio.h>
#include <assert.h>


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
		int* tmpArray = new int[newMemorySize];
		allocatedMemory = newMemorySize;
		for (int i = 0; i < allocatedMemory; i++)
		{
			tmpArray[i] = data[i];
		}
		delete[]data;
		data = tmpArray;
	}

	void pushBack(int value)
	{
		if (numElements > 0)
		{

		}
	}

	int pop()
	{
		if (numElements > 0)
		{
			numElements--;
		}
	}

	void insert(int value, unsigned int position)
	{

	}

	void clear()
	{
		if (data != NULL)
		{
			numElements = 0;
		}
	}

	int& operator[] (unsigned int index) //modificar
	{

	}

	const int& operator[] (unsigned int index) const //lectura
	{
		assert (index < numElements);
		return data[index];
	}
};