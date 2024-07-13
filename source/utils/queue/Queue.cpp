#include <new>

namespace utils
{

template<typename T>
Queue<T>::Queue(const uint64_t maxObjects, const T& defaultValue):
  maxObjects   (maxObjects),
  defaultObject(defaultValue),
  numObjects   (0U),
  linkedList   (defaultValue)
{
}

template<typename T>
Queue<T>::~Queue()
{
}

template<typename T>
uint64_t Queue<T>::size() const
{
  return numObjects;
}

template<typename T>
uint64_t Queue<T>::capacity() const
{
  return maxObjects;
}

template<typename T>
void Queue<T>::push(const T& object)
{
  // Do nothing if queue is full
  if (maxObjects == numObjects)
  {
    return;
  }
 
  linkedList.pushToBack(object);

  ++numObjects;
}

template<typename T>
const T Queue<T>::pop()
{
  // Return default object if queue is empty
  if (0U == numObjects)
  {
    return defaultObject;
  }

  --numObjects;

  return linkedList.popFromFront();
}

template<typename T>
void Queue<T>::clear()
{
  numObjects = 0U;
  linkedList.clear();
}

}
