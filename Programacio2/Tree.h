#ifndef _Tree_
#define _Tree_

#include "LinkedList.h"

template<class TYPE>
struct tNode
{
	TYPE value;
	tNode<TYPE>* father;
	SList<tNode>* sons;

	inline tNode(const TYPE& _value)
	{
		value = _value;
		next = prev = NULL;
	}

	~tNode()
	{}
};

template<class TYPE>
class Tree
{
	tNode* root;

public:

	Tree(TYPE value)
	{
		root->value = value;
	}

	tNode Add(TYPE value, tNode* father)
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
			tmp->father = root;
			root->sons->add(tmp);
		}
		
		return tmp;
	}
};

#endif