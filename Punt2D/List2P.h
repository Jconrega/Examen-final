#ifndef __LIST2P_H__
#define __LIST2P_H__

template<class Type>
struct node{
	Type value;
	node<Type>* next;
	node<Type>* prev;
};

template<class Type>
class List2P{

public:
	node<Type>* start;
	node<Type>* end;

private:
	unsigned int size;

public:
		
	//Constructor

	List2P()
	{
		start = end = NULL;
		size = 0;
	}

	//Destructor

	~List2P()
	{
		DeleteAll();
	}

	//Methods

	unsigned int Count()
	{
		return size;
	}

	void Add(const Type data){

		node<Type>* item; 
		item = new node <Type>;
		item->value = data;

		if (start != NULL)
		{
			item->prev = end;
			end->next = item;
			end = item;
			item->next = NULL;
		}
		else
		{
			start = end = item;
			item->prev = item->next = NULL;
		}

		size++;

	}

	bool Delete(node<Type>* item){

		if (item == NULL)
			return false;

		if (item->prev != NULL)
		{
			item->prev->next = item->next;
			if (item->next != NULL)
			{
				item->next->prev = item->prev;
			}
			else
			{
				end = item->prev;
			}

		}
		else
		{
			if (item->next == NULL)
			{
				start = end = NULL;
			}
			else
			{
				start = item->next;
				item->next->prev = NULL;
			}
		}

		delete item;
		size--;
		return true;
	}

	void DeleteAll(){
		node<Type>* tmp;
		node<Type>* tmpNext;

		tmp = start;
		while (tmp != NULL){
			tmpNext = tmp->next;
			delete tmp;
			tmp = tmpNext;
		}

		size = 0;
		start = end = NULL;
	}

	const Type& operator[] (const unsigned int index) const
	{
		
		long position;

		node<Type>* item;
		item = start;
		position = 0;

		while (item!=NULL)
		{
			if (position == index)
				break;
			++position;
			item = item->next;
		}

		assert(item);
		return item->value;
		
	}
	Type& operator[] (const unsigned int index)
	{
		long position;

		node<Type>* item;
		item = start;
		position = 0;

		while (item != NULL)
		{
			if (position == index)
				break;
			++position;
			item = item->next;
		}

		//assert(item);
		return item->value;

	}
	int Bubble(){
			
		int counter = 0;
		node<Type>* item;
		item = start;

		bool done = false;
		while (!done)
		{
			done = true;
		
			for (int i = 0; i < Count(); i++)
			{
				counter++;
				if (item->value > item->next->value)
				{
					SWAP(item->value, item->next->value);
					done = false;
				}
			}
			item = item->next;
		}

		return counter;
	}

	void SWAP(node<Type>*& a, node<Type>*& b)
	{
		if (a->next != NULL)
			a->next->prev = a;
		if (a->prev != NULL)
			a->prev->next = a;
		if (b->next != NULL)
			b->next->prev = b;
		if (b->prev != NULL)
			b->prev->next = b;
	}
	const List2P<Type>& operator +=(const List2P<Type>& b){

		node<Type>* item = b.start;

		while (item)
		{
			Add(item->value);
			item = item->next;
		}
		return *this;

		
	}

	void InsertAfter(unsigned int position, node<Type>& list)
	{
		
		node<Type>* p_my_list = At(position);
		node<Type>* p_other_list = list.start;

		while (p_other_list != NULL)
		{
			List2P<Type>* p_new_item = new List2P<Type>(p_other_list->data);
			  NULL;

			if (p_new_item->next = p_my_list)
				 p_my_list->next;
			if (p_new_item->next != NULL)
				p_new_item->next->prev = p_new_item;
			else
				end = p_new_item;
			p_new_item->prev = p_my_list;
			if (p_new_item->prev != NULL)
				p_new_item->prev->next = p_new_item;
			else
				start = p_new_item;
			p_my_list = p_new_item;
			p_other_list = p_other_list->next;
		}
	}
	
};


#endif

