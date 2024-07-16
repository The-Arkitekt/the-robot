#ifndef UTILS_MAP_H
#define UTILS_MAP_H

#include "ArrayList.h"

namespace utils
{

template<typename K, typename V>
class Map
{
public:

  virtual V&        operator [](const K& key)       = 0;
  virtual const V&  operator [](const K& key) const = 0;
  virtual Map<K,V>& operator =(const Map<K,V>& rhs) = 0;
  
  virtual const ArrayList<K> getKeys() const = 0;
  virtual void               clear()         = 0;

};

}

#endif // UTILS_MAP_H
