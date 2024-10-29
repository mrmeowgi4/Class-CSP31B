#include "LinkedList.h"

template<typename G>
class Queue : public LinkedList<G>
{
private:
	Node<G>* upper;
	Node<G>* back;
	int size;

public:

	Queue()
	{
		this->upper = nullptr;
		this->back = nullptr;
		this->size = 0;
	}

	void enqueue(const G& value)
	{
		Node<G>* _new = new Node<G>(value);
		
		if (isEmpty())
		{
			upper = _new;
			back = _new;
		}
		else {
			back->next = _new;
			back = _new;
		}

		++size;
	}

	G& pop()
	{
	
		Node<G>* copy = upper;
		G frontElement = copy->element;
		
		upper = copy->next;
		
		delete copy;

		--size;

		return frontElement;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	int getSize()
	{
		return size;
	}

};