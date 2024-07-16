#ifndef QUEUE_H
#define QUEUE_H

#include <cstdint>
#include "LinkedList.h"

namespace utils
{

template<typename T>
class Queue
{
public:

  Queue();
  Queue(const uint64_t maxObjects, const T& defaultValue);
  ~Queue();

  uint64_t size() const;
  uint64_t capacity() const;
  void     setCapacity(const uint64_t newCap);
  void     push(const T& object);
  const T  pop();
  void     clear();

private:

  uint64_t       maxObjects;
  T              defaultObject;
  T              defaultReturn;
  uint64_t       numObjects;
  LinkedList<T>  linkedList;
};

}

#include "Queue.cpp"

#endif // QUEUE_H
