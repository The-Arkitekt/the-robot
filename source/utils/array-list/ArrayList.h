#ifndef UTILS_ARRAY_LIST_H
#define UTILS_ARRAY_LIST_H

namespace Utils
{

template<typename T>
class ArrayList
{
public:

  ArrayList();
  ArrayList(const T& defaultValue);
  ArrayList(const unsigned int startingSize, const T& defaultValue);
  ArrayList(const ArrayList& other);
  ~ArrayList();

  T&            operator [](const unsigned int index);
  const T&      operator [](const unsigned int index) const;
  ArrayList<T>& operator =(const ArrayList<T>& rhs);

  const unsigned int size() const;
  void               resize(const unsigned int newSize);
  void               clear();

private:

  unsigned int numObjects;
  T            defaultObject;
  T            defaultReturn;
  T *          arr;

};

}

#include "ArrayList.cpp"

#endif // UTILS_ARRAY_LIST_H
