#include "LinkedList.h"

#include <stdio.h>

void SList::add(int value)
{
	node* newNode = new node;
	newNode->value = value;
	newNode->next = NULL;
	node* tmp = start;
	tmp->next = newNode;

	if (tmp != NULL){
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
	}
}

void SList::del(int i)
{

}

unsigned int SList::count() const
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