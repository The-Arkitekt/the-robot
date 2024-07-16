namespace utils
{

template<typename T>
Node<T>::Node():
  object(T()),
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

template<typename T>
Node<T>& Node<T>::operator =(const Node<T>& rhs)
{
  if (this != &rhs)
  {
    object = rhs.object;
    child  = rhs.child;
  }

  return *this;
}

}
