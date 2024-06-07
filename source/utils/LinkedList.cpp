namespace utils
{

template<typename T>
const uint64_t LinkedList<T>::MAX_LINKED_LIST_SIZE = 25U;

template<typename T>
LinkedList<T>::LinkedList():
  defaultNode(),
  numNodes   (0U),
  headPointer(nullptr)
{
}

template<typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template<typename T>
uint64_t LinkedList<T>::size() const
{
  return numNodes;
}

template<typename T>
void LinkedList<T>::push(const T& object)
{
  //-----------------------------
  // Case 1: Max capacity
  if (MAX_LINKED_LIST_SIZE == numNodes)
  {
    return;
  }

  Node<T> * node = new(std::nothrow) Node<T>(object);
  if (nullptr == node)
  {
    return;
  }

  //-----------------------------
  // Case 2: First Link
  if ((nullptr == headPointer) &&
      (nullptr == tailPointer))
  {
    headPointer        = node;
    tailPointer        = node;
    headPointer->child = tailPointer;
  }

  //----------------------------
  // Case 3: Subsequent Links
  else
  {
    if (nullptr == tailPointer)
    {
      delete node;
      return;
    }
    
    tailPointer->child = node;
    tailPointer        = node;
  }
}

template<typename T>
Node<T>& LinkedList<T>::head()
{
  if (nullptr == headPointer)
  {
    return defaultNode;
  }

  return * headPointer;
}

template<typename T>
const Node<T>& LinkedList<T>::head() const
{
  if (nullptr == headPointer)
  {
    return defaultNode;
  }

  return * headPointer;
}

template<typename T>
Node<T>& LinkedList<T>::tail()
{
  if (nullptr == tailPointer)
  {
    return defaultNode;
  }

  return * tailPointer;
}

template<typename T>
const Node<T>& LinkedList<T>::tail() const
{
  if (nullptr == tailPointer)
  {
    return defaultNode;
  }

  return * tailPointer;
}

template<typename T>
void LinkedList<T>::clear()
{
  Node<T> * currentNode = headPointer;

  if (nullptr == currentNode)
  {
    return;
  }

  Node<T> * nextNode = headPointer->child;

  while (nullptr != nextNode)
  {
    delete currentNode;
    currentNode = nextNode;
    nextNode = currentNode->child;
  }

  delete currentNode;
}

}
