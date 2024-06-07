#ifndef UTILS_ARRAY_LIST_H
#define UTILS_ARRAY_LIST_H

#include <cstdint>

namespace utils
{

template<typename T>
class ArrayList
{
public:
 
  ArrayList();
  ArrayList(const uint64_t startingSize);
  ~ArrayList();

  T&       operator [](const uint64_t index);
  const T& operator [](const uint64_t index) const;

  const uint64_t size() const;
  void           resize(const uint64_t newSize);

private:

  T        defaultObject;
  uint64_t numObjects;
  T *      arr;

};

}

#include "ArrayList.cpp"

#endif // UTILS_ARRAY_LIST_H
