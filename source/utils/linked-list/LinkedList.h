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
  LinkedList(const T& defaultValue);
  LinkedList(const LinkedList<T>& other);
  ~LinkedList();

  LinkedList<T>& operator =(const LinkedList<T>& rhs);  

  Node<T>&       head();
  Node<T>&       tail();
  const Node<T>& head() const;
  const Node<T>& tail() const;
  void           pushToBack(const T& object);
  const T        popFromFront();
  void           clear();

private:

  Node<T>   defaultNode;
  Node<T>   defaultReturn;
  Node<T> * headPointer;
  Node<T> * tailPointer;

};

}

#include "LinkedList.cpp"

#endif // UTILS_LINKED_LIST_H
