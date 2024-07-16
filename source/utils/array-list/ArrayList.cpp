#include <new>

namespace utils
{

template<typename T>
ArrayList<T>::ArrayList():
  numObjects   (0U),
  defaultObject(T()),
  defaultReturn(defaultObject),
  arr          (nullptr)
{
}

template<typename T>
ArrayList<T>::ArrayList(const T& defaultValue):
  numObjects   (0U),
  defaultObject(defaultValue),
  defaultReturn(defaultValue),
  arr          (nullptr)
{
}

template<typename T>
ArrayList<T>::ArrayList(const uint64_t startingSize, const T& defaultValue):
  numObjects   (0U),
  defaultObject(defaultValue),
  defaultReturn(defaultValue),
  arr          (nullptr)
{
  arr = new(std::nothrow) T[startingSize];

  if (nullptr != arr)
  {
    numObjects = startingSize;
    for (uint64_t i = 0U; i < numObjects; ++i)
    {
      arr[i] = defaultObject;
    }
  }
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other):
  numObjects   (0U),
  defaultObject(other.defaultObject),
  defaultReturn(other.defaultObject),
  arr          (nullptr)
{
  arr = new(std::nothrow) T[other.numObjects];

  if (nullptr == arr)
  {
    return;
  }

  numObjects = other.numObjects;

  for (uint64_t i = 0U; i < numObjects; ++i)
  {
    arr[i] = other.arr[i];
  }
}  

template<typename T>
ArrayList<T>::~ArrayList()
{
  clear();
}

template<typename T>
T& ArrayList<T>::operator [](const uint64_t index)
{
  // Give em some garbage if out of bounds
  if (numObjects <= index)
  {
    defaultReturn = defaultObject;
    return defaultReturn;
  }

  return arr[index];
}

template<typename T>
const T& ArrayList<T>::operator [](const uint64_t index) const
{
  // Give em some garbage if out of bounds
  if (numObjects <= index)
  {
    // Can return the default object here because const
    return defaultObject;
  }

  return arr[index];
}

template<typename T>
ArrayList<T>& ArrayList<T>::operator =(const ArrayList<T>& rhs)
{
  if (this != &rhs)
  {
    clear();
    resize(rhs.numObjects);

    for (uint64_t i = 0U; i < numObjects; ++i)
    {
      arr[i] = rhs.arr[i];
    }
  }

  return *this;
}

template<typename T>
const uint64_t ArrayList<T>::size() const
{
  return numObjects;
}

template<typename T>
void ArrayList<T>::resize(const uint64_t newSize)
{
  T * newArr = new(std::nothrow) T[newSize];

  // If newSize is 0U, this early return will trigger. This is 
  // expected behavior. Sizing to 0U should be done with
  // the clear() function.
  if (nullptr == newArr)
  {
    return;
  }

  // Copy contents and set rest to default if necessary
  for (uint64_t i = 0U; i < newSize; ++i)
  {
    if (i < numObjects)
    {
       newArr[i] = arr[i];
    }
    else
    {
       newArr[i] = defaultObject;
    }
  }

  delete[] arr;

  numObjects = newSize;
  arr        = newArr;
}

template<typename T>
void ArrayList<T>::clear()
{
  delete[] arr;
  arr        = nullptr;
  numObjects = 0U;
}

}

