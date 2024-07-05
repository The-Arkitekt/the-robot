#ifndef QUEUE_H
#define QUEUE_H

#include <cstdint>
#include "ArrayList.h"

namespace utils
{

Template<typename T>
class Queue
{
public:

  Queue(const T& defaultValue, const uint64_t capacity);
  ~Queue();

  uint64_t size() const;
  void     push(const T& object);
  const T& pop();
  void     clear();

private:

  T              defaultObject;
  const uint64_t capacity;
  uint64_t       numObjects;
  uint64_t       headIndex;
  uint64_t       tailIndex;
  ArrayList<T>   arrayList;
};

}

#include "Queue.cpp"

#endif // QUEUE_H
