#ifndef _LinkedList_
#define _LinkedList_

#include <stdio.h>

template<struct TYPE>
struct node
{
	TYPE value;
	node* next;
};

template<class TYPE>
class SList
{
	node* start;
	SList() : start(NULL){}
	void add(TYPE value)
	{
		node* newNode = new node;
		newNode->value = value;
		newNode->next = NULL;
		node* tmp = start;

		if (tmp != NULL){
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
		}
		tmp->next = newNode;
	}

	void del(node* delNode)
	{
		if (delNode != NULL)
		{
			if (delNode != start && start != NULL)
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
			}
			else
			{
				start = start->next;
			}
			delete delNode;
		}
	}

	void del(unsigned int x)
	{
			if (start != NULL)
			{
				node* tmp = start;
				node* tmp2;
				if (x == 0)
				{
					start = start->next;
					delete tmp;
				}
				for (unsigned int i = 1; i < x; i ++)
				{
					if (tmp == NULL)
					{
						delete delNode;
						return;
					}
					tmp = tmp->next;
				}
				tmp2 = tmp->next;
				tmp->next = tmp2->next;
			}
			else
			{
				start = start->next;
			}
			delete tmp2;
	}

	void delAll()
	{
		if (start != NULL)
		{
			node* tmp = start;
			while (start != NULL)
			{
				tmp = start;
				start = start->next;
				delete tmp;
			}
			delete start;
		}
	}

	unsigned int count() const
	{
		unsigned int result = 0;
		node* tmp = start;
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
				result++;
			}
		}
		return (result);
	}

};



#endif