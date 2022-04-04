#include <iostream>

using namespace std;

template <typename T>
class Node
{
    private:
        T val;
        Node<T>* link;
    public:
        Node(T val);
        T getVal();
        void setVal(T val);
        Node<T>* getLink();
        void setLink(Node<T>* link);
};

template <typename T>
Node<T>::Node(T val)
{
    this->val = val;
    link = NULL;
}

template <typename T>
T Node<T>::getVal()
{
    return val;
}

template <typename T>
void Node<T>::setVal(T val)
{
    this->val = val;
}

template <typename T>
Node<T>*  Node<T>::getLink()
{
    return link;
}

template <typename T>
void Node<T>::setLink(Node<T>* link)
{
    this->link = link;
}

