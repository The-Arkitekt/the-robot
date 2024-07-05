#ifndef UTILS_ARRAY_LIST_H
#define UTILS_ARRAY_LIST_H

#include <cstdint>

namespace utils
{

template<typename T>
class ArrayList
{
public:
 
  ArrayList(const T& defaultValue);
  ArrayList(const T& defaultValue, const uint64_t startingSize);
  ArrayList(const ArrayList& other);
  ~ArrayList();

  T&            operator [](const uint64_t index);
  const T&      operator [](const uint64_t index) const;
  ArrayList<T>& operator =(const ArrayList<T>& rhs);

  const uint64_t size() const;
  void           resize(const uint64_t newSize);
  void           clear();

private:

  T        defaultObject;
  uint64_t numObjects;
  T *      arr;

};

}

#include "ArrayList.cpp"

#endif // UTILS_ARRAY_LIST_H
