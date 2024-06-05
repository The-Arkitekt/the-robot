#include "Node.h"

namespace utils
{

template<typename T>
Node<T>::Node():
  object(),
  child (nullptr)
{
}

template<typename T>
Node<T>::Node(const T& object):
  object(object),
  child (nullptr)
{
}

template<typename T>
Node<T>::~Node()
{
}

}
