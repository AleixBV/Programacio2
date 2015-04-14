#ifndef _Tree_
#define _Tree_

#include "DoubleLinkedList.h"
#include "Stack.h"

template<class TYPE>
struct tNode
{
	TYPE value;
	tNode<TYPE>* father;
	DSList<tNode<TYPE>*> sons;

	inline tNode(const TYPE& _value)
	{
		value = _value;
		father = NULL;
	}

	~tNode()
	{}
};

template<class TYPE>
class Tree
{
	tNode<TYPE>* root;

public:

	Tree() : root(NULL){}

	Tree(const TYPE& value)
	{
		root->value = value;
	}

	tNode<TYPE> add(const TYPE& value, tNode<TYPE>* father)
	{
		tNode<value>* tmp = new tNode<value>;
		tmp->value = value;
		
		if (father != NULL)
		{
			tmp->father = father;
			tmp->father->sons->add(tmp);
		}

		else
		{
			root = tmp;
		}
		
		return tmp;
	}

	void visitAllNodesPreOrder(DSList<tNode<TYPE>*>* list) const
	{
		list->add(value);

		node<tNode<TYPE>*>* tmp = sons.start;

		for (tmp; tmp != NULL; tmp = tmp->next)
		{
			tmp->value->visitAllNodesPreOrder(list);
		}
	}

	void visitAllNodesPostOrder(DSList<tNode<TYPE>*>* list) const
	{
		node<tNode<TYPE>*>* tmp = sons.start;

		for (tmp; tmp != NULL; tmp = tmp->next)
		{
			tmp->value->visitAllNodesPostOrder(list);
		}
		list->add(value);
	}
	
};

#endif