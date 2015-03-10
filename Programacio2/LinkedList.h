#ifndef _LinkedList_
#define _LinkedList_

#include <stdio.h>

struct node
{
	int value;
	node* next;
};

class SList
{
	node * start;
	SList() : start(NULL){}
	void add(int);
	void del(int);
	unsigned int count() const;
};



#endif