#include <new>

namespace utils
{

template<typename T>
Queue<T>::Queue(const T& defaultValue, const uint64_t capacity):
  defaultObject(defaultValue),
  capacity     (capacity),
  numObjects   (0U),
  headIndex    (0U),
  tailIndex    (0U),
  arrayList    (defaultValue, capacity)
{
}

template<typename T>
Queue<T>::~Queue()
{
}

template<typename T>
const uint8_t Queue<T>::size() const
{
  return numObjects;
}

template<typename T>
void Queue<T>::push(T& object)
{
  //--------------------------------
  // Case 1: Queue is empty
  if (0U == numObjects)
  {
    arrayList[tailIndex] = object;
    return;
  }

  //-------------------------------
  // Case 2: Queue is NOT empty
  //         Wrap tail index if necessary
  else 
  {
    if (capacity == ++tailIndex)
    {
      tailIndex = 0U;
    }

    arrayList[tailIndex] = object;
  }

  // Increment num objects if push is successful
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
  if (capacity == headIndex)
  {
    headIndex = 0U;
  }

  // Decrement num objects if pop successful
  --numObjects;
  return arrayList[popIndex];
}

void Queue::clear()
{
  numObjects = 0U;
  headIndex  = 0U;
  tailIndex  = 0U;

  for(uint64_t i = 0U; i < arrayList.size(); ++i)
  {
    arrayList[i] = T();
  }
}

}
