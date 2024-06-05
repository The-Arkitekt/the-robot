#include <new>

namespace utils
{

template<typename T>
ArrayList<T>::ArrayList(const uint64_t startingSize):
  numObjects(0U),
  arr       (nullptr)
{
  arr = (std::nothrow) new T[startingSize];

  if (nullptr != arr)
  {
    numObjects = startingSize);
  }
}

template<typename T>
ArrayList<T>::~ArrayList()
{
  delete[] arr;
}

template<typename T>
T& ArrayList<T>::operator [](const uint64_t index)
{
  // Give em some garbage if out of bounds
  if (numObjects <= index)
  {
    T ret;
    return ret;
  }

  return arr[index];
}

template<typename T>
const T& ArrayList<T>::operator [](const uint64_t index) const
{
  // Give em some garbage if out of bounds
  if (numObjects <= index)
  {
    const T ret;
    return ret;
  }

  return arr[index];
}

template<typename T>
void ArrayList<T>::resize(const uint64_t newSize)
{
  T * newArr = (std::nothrow) new T[newSize];

  if (nullptr == newArr)
  {
    return;
  }

  for (uint64_t i = 0U; i < numObjects; ++i)
  {
    newArr[i] = arr[i];
  }

  delete[] arr;

  numObjects = newSize;
  arr        = newArr;
}
