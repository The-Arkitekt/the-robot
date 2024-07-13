#include <new>

namespace utils
{

template<typename T>
Queue<T>::Queue(const T& defaultValue, const uint64_t maxObjects):
  defaultObject(defaultValue),
  maxObjects   (maxObjects),
  numObjects   (0U),
  headIndex    (0U),
  tailIndex    (0U),
  arrayList    (defaultValue, maxObjects)
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
  //-------------------------------
  // Case 1: Queue is full
  if (maxObjects == numObjects)
  {
    return;
  }
  
  //--------------------------------
  // Case 1: Queue is empty
  if (0U == numObjects)
  {
    arrayList[tailIndex] = object;
  }

  //-------------------------------
  // Case 2: Queue is NOT empty
  //         Wrap tail index if necessary
  else
  {
    if (maxObjects == ++tailIndex)
    {
      tailIndex = 0U;
    }

    arrayList[tailIndex] = object;
  }

  ++numObjects;
}

template<typename T>
const T& Queue<T>::pop()
{
  //-----------------------------
  // Case 1: Empty queue
  if (0U == numObjects)
  {
    defaultObject;
  }

  //-----------------------------
  // Case 2: Pop object from queue
  const uint64_t popIndex = headIndex++;

  // Wrap head index if necessary
  if (maxObjects == headIndex)
  {
    headIndex = 0U;
  }

  // Decrement num objects if pop successful
  --numObjects;
  return arrayList[popIndex];
}

template<typename T>
void Queue<T>::clear()
{
  numObjects = 0U;
  headIndex  = 0U;
  tailIndex  = 0U;

  for(uint64_t i = 0U; i < arrayList.size(); ++i)
  {
    arrayList[i] = defaultObject;
  }
}

}
