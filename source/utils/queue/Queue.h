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

  Queue(const uint64_t maxObjects, const T& defaultValue);
  ~Queue();

  uint64_t size() const;
  uint64_t capacity() const;
  void     push(const T& object);
  const T  pop();
  void     clear();

private:

  uint64_t       maxObjects;
  T              defaultObject;
  uint64_t       numObjects;
  LinkedList<T>  linkedList;
};

}

#include "Queue.cpp"

#endif // QUEUE_H
