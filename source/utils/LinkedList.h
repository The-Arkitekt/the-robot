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
  ~LinkedList();

  uint64_t       size() const;
  void           push(const T& object);
  Node<T>&       head();
  Node<T>&       tail();
  const Node<T>& head() const;
  const Node<T>& tail() const;
  void           clear();

  static const uint64_t MAX_LINKED_LIST_SIZE;

private:

  Node<T>   defaultNode;
  uint64_t  numNodes;
  Node<T> * headPointer;
  Node<T> * tailPointer;

};

}

#include "LinkedList.cpp"

#endif // UTILS_LINKED_LIST_H
