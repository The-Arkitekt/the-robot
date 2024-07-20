#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

namespace Utils
{

template<typename T>
class Queue
{
public:

  Queue();
  Queue(const unsigned int maxObjects, const T& defaultValue);
  ~Queue();

  unsigned int size() const;
  unsigned int capacity() const;
  void         setCapacity(const unsigned int newCap);
  void         push(const T& object);
  const T      pop();
  void         clear();

private:

  unsigned int   maxObjects;
  T              defaultObject;
  T              defaultReturn;
  unsigned int   numObjects;
  LinkedList<T>  linkedList;
};

}

#include "Queue.cpp"

#endif // QUEUE_H
