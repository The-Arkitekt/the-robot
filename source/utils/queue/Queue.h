#ifndef QUEUE_H
#define QUEUE_H

#include <cstdint>
#include "ArrayList.h"

namespace utils
{

template<typename T>
class Queue
{
public:

  Queue(const T& defaultValue, const uint64_t maxObjects);
  ~Queue();

  uint64_t size() const;
  uint64_t capacity() const;
  void     push(const T& object);
  const T& pop();
  void     clear();

private:

  T              defaultObject;
  const uint64_t maxObjects;
  uint64_t       numObjects;
  uint64_t       headIndex;
  uint64_t       tailIndex;
  ArrayList<T>   arrayList;
};

}

#include "Queue.cpp"

#endif // QUEUE_H
