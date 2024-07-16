#include <new>

namespace utils
{

template<typename T>
Queue<T>::Queue():
  maxObjects   (1U),
  defaultObject(T()),
  defaultReturn(defaultObject),
  numObjects   (0U),
  linkedList   (defaultObject)
{
}

template<typename T>
Queue<T>::Queue(const uint64_t maxObjects, const T& defaultValue):
  maxObjects   (maxObjects),
  defaultObject(defaultValue),
  defaultReturn(defaultValue),
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
void Queue<T>::setCapacity(const uint64_t newCap)
{
  maxObjects = newCap;
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
    defaultReturn = defaultObject;
    return defaultReturn;
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