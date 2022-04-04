#include <iostream>
#include "Node.h"
#include "Exception.h"

using namespace std;
using namespace Exception;

template <typename T>
class List
{
    private:
        Node<T>* head;
        Node<T>* tmp;
        int element;
    public:
        List();
        int getSize();
        T getValue(int index);
        void verifyHead();
        void add(T val);
        void addInHead(T val);
        void addInPosition(T val, int position);
        void remove();
        void removeInHead();
        void removeInPosition(int position);
        void setValue(T value, int position);
        List<T> reverse();
};

template <typename T>
List<T>::List()
{
    head = NULL;
    element = 0;
}

template <typename T>
int List<T>::getSize()
{
    return element;
}

template <typename T>
T List<T>::getValue(int index)
{
    if(index < 0 || index > element-1)
    {
        throw PositionException();
    }
    tmp = head;
    for(int i=0; i<index; i++)
    {
        tmp = tmp->getLink();
    }
    return tmp->getVal();
}

template <typename T>
void List<T>::verifyHead()
{
    if(head == NULL)
    {
        throw ListNotInitException();
    }
}

template <typename T>
void List<T>::add(T val)
{
    Node<T>* n = new Node<T>(val);
    if(head == NULL)
    {
        head = n;
    }
    else
    {
        tmp = head;
        while(tmp->getLink() != NULL)
        {
            tmp = tmp->getLink();
        }
        tmp->setLink(n);
    }
    element++;
}

template <typename T>
void List<T>::addInHead(T val)
{
    Node<T>* n = new Node<T>(val);
    if(head == NULL)
    {
        head = n;
    }
    else
    {
        n->setLink(head);
        head = n;
    }
    element++;
}

template <typename T>
void List<T>::addInPosition(T val, int position)
{
    verifyHead();
    if(position < 1 || position > element)
    {
        throw PositionException();
    }
    Node<T>* n = new Node<T>(val);
    tmp = head;
    for(int i=0; i<position-1; i++)
    {
        tmp = tmp->getLink();
    }
    n->setLink(tmp->getLink());
    tmp->setLink(n);
    element++;
}

template <typename T>
void List<T>::remove()
{
    verifyHead();
    tmp = head;
    for(int i=0; i<element-2; i++)
    {
        tmp = tmp->getLink();
    }
    tmp->setLink(NULL);
    element--;
}

template <typename T>
void List<T>::removeInHead()
{
    verifyHead();
    head = head->getLink();
    element--;
}

template <typename T>
void List<T>::removeInPosition(int position)
{
    verifyHead();
    if(position < 1 || position >= element)
    {
        throw PositionException();
    }

    tmp = head;
    Node<T>* tmp2 = head;
    for(int i=0; i<position-1; i++)
    {
        tmp = tmp->getLink();
    }
    for(int i=0; i<position; i++)
    {
        tmp2 = tmp2->getLink();
    }

    tmp->setLink(tmp2->getLink());
    element--;
}

template <typename T>
void List<T>::setValue(T val, int position)
{
    tmp = head;
    for(int i=0; i<position; i++)
    {
        tmp = tmp->getLink();
    }
    tmp->setVal(val);
}

template <typename T>
List<T> List<T>::reverse()
{
    List<T>* l = new List<T>();
    tmp = head;
    l->addInHead(head->getVal());
    while(tmp->getLink() != NULL)
    {
        tmp = tmp->getLink();
        l->addInHead(tmp->getVal());
    }
    return *l;
}