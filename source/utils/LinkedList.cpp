namespace utils
{

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
  headPointer(nullptr),
  tailPointer(nullptr)
{
  Node<T> * currentNode = other.headPointer;

  while (nullptr != currentNode)
  {
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
    
    while (nullptr != currentNode)
    {
      push(currentNode->object);
      currentNode = currentNode->child;
    }
  }

  return *this;
}

template<typename T>
void LinkedList<T>::push(const T& object)
{
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
