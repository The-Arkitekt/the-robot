namespace utils
{

template<typename T>
const uint64_t LinkedList<T>::MAX_LINKED_LIST_SIZE = 25U;

template<typename T>
LinkedList<T>::LinkedList():
  defaultNode(),
  numNodes   (0U),
  headPointer(nullptr),
  tailPointer(nullptr)
{
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other):
  defaultNode(),
  numNodes   (other.numNodes),
  headPointer(nullptr),
  tailPointer(nullptr)
{
  Node<T> * currentNode = other.headPointer;

  for (uint64_t i = 0U; i < other.numNodes; ++i)
  {
    if (nullptr == currentNode)
    {
      return;
    }
    
    push(currentNode->object);
    currentNode = currentNode->child;
  }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& rhs)
{
  if (this != &rhs)
  {
    clear();

    Node<T> * currentNode = rhs.headPointer;

    for (uint64_t i = 0U; i < rhs.numNodes; ++i)
    {
      if (nullptr == currentNode)
      {
        clear();
        return *this;
      }

      push(currentNode->object);
      currentNode = currentNode->child;
    }
  }

  return *this;
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
    tailPointer->child = node;   
    tailPointer        = tailPointer->child;
  }

  ++numNodes;
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
  numNodes = 0U;

  //--------------------------
  // Case 1: Empty list
  if (nullptr == headPointer)
  {
    return;
  }

  //--------------------------
  // Case 2: Single Node
  if (headPointer == tailPointer)
  {
    delete headPointer;
    headPointer = nullptr;
    tailPointer = nullptr;
    return;
  }

  //---------------------------
  // Case 3: Multiple Nodes
  Node<T> * currentNode = headPointer;
  Node<T> * nextNode    = nullptr;

  while (nullptr != currentNode)
  {
    nextNode = currentNode->child;
    delete currentNode;
    currentNode = nextNode;
  }

  headPointer = nullptr;
  tailPointer = nullptr;
}

}
