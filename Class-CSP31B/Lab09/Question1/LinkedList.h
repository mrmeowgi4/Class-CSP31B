#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class Node
{
public:
    T element;  // Element contained in the node
    Node<T>* next; // Pointer to the next node

    // No-arg constructor
    Node()
    {
        next = NULL;
    }

    // Constructor
    Node(T element) {
        this->element = element;
        next = NULL;
    }
};

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    Iterator(Node<T>* p)
    {
        current = p;
    }

    Iterator operator++()
    {
        current = current->next;
        return *this;
    };

    T& operator*()
    {
        return current->element;
    }

    bool operator==(const Iterator<T>& iterator)
    {
        return current == iterator.current;
    }

    bool operator!=(const Iterator<T>& iterator)
    {
        return current != iterator.current;
    }

private:
    Node<T>* current;
};

template<typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(LinkedList<T>& list);
    virtual ~LinkedList();
    void addFirst(T element);
    void addLast(T element);

    T getFirst() const;
    T getLast() const;
    T removeFirst();
    T removeLast();
    void add(T element);
    void add(int index, T element);
    void clear();
    bool contains(T element) const;
    T get(int index) const;
    int indexOf(T element) const;
    bool isEmpty() const;
    int lastIndexOf(T element) const;
    void remove(T element);
    int getSize() const;
    T removeAt(int index);
    T set(int index, T element);

    Iterator < T > begin()
    {
        return Iterator<T>(head);
    };

    Iterator < T > end()
    {
        return Iterator < T >(tail->next);
    };

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T>& list)
{
    head = tail = NULL;
    size = 0;

    Node<T>* current = list.head;
    while (current != NULL)
    {
        this->add(current->element);
        current = current->next;
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
    Node<T>* newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    size++;

    if (tail == NULL)
        tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
    if (tail == NULL)
    {
        head = tail = new Node<T>(element);
    }
    else
    {
        tail->next = new Node<T>(element);
        tail = tail->next;
    }

    size++;
}

template<typename T>
T LinkedList<T>::getFirst() const
{
    if (size == 0) throw runtime_error("Index out of range");
    else return head->element;
}

template<typename T>
T LinkedList<T>::getLast() const
{
    if (size == 0) throw runtime_error("Index out of range");
    else return tail->element;
}

template<typename T>
T LinkedList<T>::removeFirst()
{
    if (size == 0) throw runtime_error("No elements in the list");
    else
    {
        Node<T>* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        size--;
        T element = temp->element;
        delete temp;
        return element;
    }
}

template<typename T>
T LinkedList<T>::removeLast()
{
    if (size == 0) throw runtime_error("No elements in the list");
    else if (size == 1)
    {
        Node<T>* temp = head;
        head = tail = NULL;
        size = 0;
        T element = temp->element;
        delete temp;
        return element;
    }
    else
    {
        Node<T>* current = head;
        for (int i = 0; i < size - 2; i++)
            current = current->next;
        Node<T>* temp = tail;
        tail = current;
        tail->next = NULL;
        size--;
        T element = temp->element;
        delete temp;
        return element;
    }
}

template<typename T>
void LinkedList<T>::add(T element)
{
    addLast(element);
}

template<typename T>
void LinkedList<T>::add(int index, T element)
{
    if (index == 0) addFirst(element);
    else if (index >= size)
        addLast(element);
    else {
        Node<T>* current = head;
        for (int i = 1; i < index; i++)
            current = current->next;
        Node<T>* temp = current->next;
        current->next = new Node<T>(element);
        (current->next)->next = temp;
        size++;
    }
}

template<typename T>
void LinkedList<T>::clear()
{
    while (head != NULL)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    size = 0;
}

template<typename T>
T LinkedList<T>::get(int index) const
{
    if (index < 0 || index > size - 1) throw runtime_error("Index out of range");
    Node<T>* current = head;
    for (int i = 0; i < index; i++)
        current = current->next;
    return current->element;
}

template<typename T>
int LinkedList<T>::indexOf(T element) const
{
    // Implement it in this exercise
    Node<T>* current = head;
    for (int i = 0; i < size; i++)
    {
        if (current->element == element) return i;
        current = current->next;
    }
    return -1;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == NULL;
}

template<typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

template<typename T>
T LinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size) throw runtime_error("Index out of range");
    else if (index == 0) return removeFirst();
    else if (index == size - 1) return removeLast();
    else
    {
        Node<T>* previous = head;
        for (int i = 1; i < index; i++)
        {
            previous = previous->next;
        }

        Node<T>* current = previous->next;
        previous->next = current->next;
        size--;
        T element = current->element;
        delete current;
        return element;
    }
}

////////////////////////////// LAB //////////////////////////////
template<typename T>
void LinkedList<T>::remove(T element)
{
    Node<T>* c = head;
    Node<T>* p = NULL;

    while (c != 0)
    {
        if (c->element == element)
        {
            if (p == NULL)
            {
                head = c->next;
                if (head == 0)
                {
                    tail = 0;
                }
            }
            else
            {
                p->next = c->next;
                if (c == tail)
                {
                    tail = p;
                }
            }
            Node<T>* t = c;
            c = c->next;
            delete t;
            size--;
        }
        else
        {
            p = c;
            c = c->next;
        }
    }
}

template<typename T>
T LinkedList<T>::set(int index, T element)
{
    Node<T>* c = head;

    for (int i = 0; i < index; i++)
    {
        c = c->next;
    }

    T o = c->element;
    c->element = element;

    return o;
}

template<typename T>
bool LinkedList<T>::contains(T element) const
{
    Node<T>* c = head;

    while (c != 0)
    {
        if (c->element == element)
        {
            return true;
        }
        c = c->next;
    }

    return false;
}

template<typename T>
int LinkedList<T>::lastIndexOf(T element) const
{
    int index = -1;
    Node<T>* c = head;

    for (int i = 0; c != 0; i++)
    {
        if (c->element == element)
        {
            index = i;
        }
        c = c->next;
    }

    return index;
}
////////////////////////////// LAB //////////////////////////////

// The functions remove(T element), lastIndexOf(T element),
// contains(T element), and set(int index, T element) are
// left as an exercise 

// WRITE YOUR CODE HERE
// Implement the remove(T element) function here



#endif