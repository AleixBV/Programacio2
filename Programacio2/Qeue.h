#ifndef _Qeue_
#define _Qeue_

#include <stdio.h>

template<class TYPE>
struct node
{
	TYPE value;
	node<TYPE>* next;
	node<TYPE>* previous;

	inline node(const TYPE& _value)
	{
		value = _value;
		next = NULL;
	}

	~node(){}
};

template<class TYPE>
class Qeue
{
public:

node<TYPE>* start;
node<TYPE>* end;

private:

unsigned int size;

public:

//Constructor
inline Qeue()
{
	start = end = NULL;
	size = 0;
}

//Destructor
~Qeue()
{
delAll();
}

//Get Size
unsigned int count()
{
return size;
}

//push
void push(const TYPE& value)
{
	node<TYPE>* newNode = new node<TYPE>(value);
	//newNode->value = value;

	if (start == NULL)
	{
		start = end = newNode;
	}
	else
	{
		newNode->previous = end;
		end->next = newNode;
		end = newNode;
	}
	size++;
}

//pop
bool pop(TYPE& value)
{
	if (start == NULL || end == NULL)
	{
		return false;
	}
	else
	{
		node<TYPE>* tmp = start;
		start = start->next;
		start->previous = NULL;
		value = tmp->value;
		delete tmp;
		--size;
	}
	return(true);
}

bool del(unsigned int x)
{
	if (start == NULL || end == NULL)
	{
		return false;
	}
	else
	{
		if (x == 0)
		{
			start = start->next;
			return(true);
		}

		node* tmp = start;
		node* tmp2;

		for (unsigned int i = 1; i < x; i++)
		{
			if (tmp == NULL)
			{
				return(false);
			}
			tmp = tmp->next;
		}
		tmp2 = tmp->next;
		if (tmp2->next != NULL)
		{
			tmp->next = tmp2->next;
			tmp = tmp2->next;
			tmp->previous = tmp2->previous;
		}
		else
		{
			end = end->previous;
			end->next = NULL;
		}
	}
	delete tmp2;
	--size;
	return(true)
}


//Destroy and free all mem
void delAll()
{
	if (start != NULL)
	{
		node<TYPE>* tmp;
		while (start != NULL)
		{
			tmp = start;
			start = start->next;
			delete tmp;
		}
		start = end = NULL;
		size = 0;
	}
}

};



#endif