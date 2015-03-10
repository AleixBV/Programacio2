#ifndef _LinkedList_
#define _LinkedList_

#include <stdio.h>

struct node
{
	int value;
	node* next;
	node* before;
};

class DSList
{
	node * start;
	DSList() : start(NULL){}
	void add(int value)
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