#ifndef UTILS_DATA_BROKER_H
#define UTILS_DATA_BROKER_H

#include <cstdint>
#include "Observer.h"
#include "LinearSearchMap.h"
#include "LinkedList.h"

namespace utils
{

template<typename S, typename D>
class DataBroker
{
public:

  DataBroker();
  ~DataBroker();

  // An observer can be registered multiple times. If it is, its update
  // will be called multiple times as well
  void registerObserver(const S& subject, Observer<D>& observer);
  void update(const S& subject, D& data);

private:

  LinearSearchMap<S, LinkedList<Observer<D> * > > observers;

};

}

#include "DataBroker.cpp"

#endif // UTILS_DATA_BROKER_H
