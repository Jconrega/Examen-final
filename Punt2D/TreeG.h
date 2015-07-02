#ifndef __TREEG__H_
#define __TREEG__H_

#include "List2P.h"
#include "Stack.h"

template <class Type>
struct nodeT{
public: 
	Type data;
	nodeT<Type>* parent;
	List2P<Type> child;
	
};


template <class Type>
class TreeG{
public:
	nodeT<Type>* rootNode;

	TreeG(){ rootNode = NULL; }
	TreeG(const Type& _data){ rootNode->data = _data; rootNode->parent = NULL; }
	

	nodeT<Type>* Add(const Type& data, nodeT<Type>* _parent){
		nodeT<Type>*item = new nodeT<Type>;
		if (_parent)
		{
			item->parent = _parent;
		}
		else
		{
			rootNode = item;
			item->parent = NULL;
		}
		item->data = data;

		rootNode->child.Add(item->data);

		return item;
	}


	nodeT<Type>* Add(const Type& _data){
		nodeT<Type>* item = new nodeT<Type>;

		item->parent = rootNode;
		item->data = _data;

		rootNode->child.Add(item->data);

		return item;
	}

	void VisitAllNodes(List2P<Type>* list) const{

		nodeT<Type>* item = rootNode;
		list->Add(rootNode->data);

		for (int i = 0; i < item->child.Count(); i++)
		{
			if (item->child[i]->data)
			{
				list->Add(item->child[i]->data);
				printf("%s", item->child[i]->data);
			}
				
			else
				VisitAllNodes(item->child[i]);

		}
	}

	void InOrder(List2P<Type>* list) const{
		nodeT<Type>* item = rootNode;
		Stack<Type> s;
		for (int i = 0; i < item->child.Count(); i++)
		{
			if (item->child[i]->data)
				s.Push(item->child[i]->data);

			else
			{

			}
				
		}
	}

};


#endif // !__TREEG__H_

