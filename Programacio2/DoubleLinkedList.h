#ifndef _LinkedList_
#define _LinkedList_
/*
#include <stdio.h>

template<class TYPE>
struct node
{
	TYPE value;
	node<TYPE>* next;
	node<TYPE>* previous;

	inline node(const TYPE& _value)
	{
		data = _value;
		next = previous = NULL;
	}

	~node(){}
};

template<class TYPE>
class DSList
{
public:

	node<TYPE>* start;
	node<TYPE>* end;

private:

	unsigned int size;

public:

	//Constructor
	DSList() : start(NULL), end(NULL){}

	//Destructor
	~DSList()
	{
		delAll();
	}

	//Get Size
	unsigned int count()
	{
		return size;
	}

	//Add new item
	unsigned int add(const TYPE& value)
	{
		node<TYPE>* newNode = new node<TYPE>;
		newNode->value = value;

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
		return(++size);
	}

	//Deletes an item from the list
	bool del(node<TYPE>* delNode)
	{
		if (delNode == NULL || start == NULL || end == NULL)
		{
			return false;
		}
		else
		{
			if (delNode != start || delNode != end)
			{
				node* tmp = start;
				while (tmp->next != delNode)
				{
					if (tmp == NULL)
					{
						delete delNode;
						return;
					}
					tmp = tmp->next;
				}
				tmp->next = delNode->next;
				tmp = tmp->next;
				tmp->previous = delNode->previous;
			}
			else if (delNode == start)
			{
				start = start->next;
				start->previous = NULL;
			}
			else
			{
				end = end->previous;
				end->next = NULL;
			}
			delete delNode;
			--size;
			return(true);
		}
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

*/

#endif