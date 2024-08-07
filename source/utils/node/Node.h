#ifndef UTILS_NODE_H
#define UTILS_NODE_H

namespace Utils
{

template<typename T>
class Node
{
public:

  Node();
  Node(const T& object);
  ~Node();

  Node<T>& operator =(const Node<T>& rhs);


  T object;
  Node<T> * child;

};

}

#include "Node.cpp"

#endif // UTILS_NODE_H
