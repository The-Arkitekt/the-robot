#ifndef UTILS_LINKED_LIST_H
#define UTILS_LINKED_LIST_H

namespace utils
{

static const uint64_t MAX_LINKED_LIST_SIZE;

template<typename T>
class LinkedList
{
public:

  LinkedList();
  ~LinkedeList();

  uint64_t       size() const;
  void           push(const T& object);
  const Node<T>& head() const;
  const Node<T>& tail() const;
  void           clear();

private:

  uint64_t  numNodes;
  Node<T> * headPointer;
  Node<T> * tailPointer;

};

#include "LinkedList.cpp"

}

#endif // UTILS_LINKED_LIST_H
