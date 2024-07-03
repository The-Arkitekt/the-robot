#ifndef UTILS_DATA_BROKER_H
#define UTILS_DATA_BROKER_H

#include <cstdint>
#include "Observer.h"
#include "LinkedList.h"

namespace utils
{

template<typename SUBJECT, typename DATA>
class DataBroker
{
public:

  DataBroker();
  ~DataBroker();

  void registerObserver(const SUBJECT& subject, Observer<DATA>& observer);
  void update(const SUBJECT& subject, DATA& data);

private:

  ArrayList<SUBJECT>                     subjects;
  ArrayList<LinkedList<Observer<DATA>*>> observers;

};

}

#include "DataBroker.cpp"

#endif // UTILS_DATA_BROKER_H
