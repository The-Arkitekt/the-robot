#ifndef UTILS_LINKED_LIST_H
#define UTILS_LINKED_LIST_H

#include <cstdint>
#include "Node.h"

namespace utils
{

template<typename T>
class LinkedList
{
public:

  LinkedList();
  LinkedList(const LinkedList<T>& other);
  ~LinkedList();

  LinkedList<T>& operator =(const LinkedList<T>& rhs);  

  void           push(const T& object);
  Node<T>&       head();
  Node<T>&       tail();
  const Node<T>& head() const;
  const Node<T>& tail() const;
  void           clear();

private:

  Node<T>   defaultNode;
  Node<T> * headPointer;
  Node<T> * tailPointer;

};

}

#include "LinkedList.cpp"

#endif // UTILS_LINKED_LIST_H
