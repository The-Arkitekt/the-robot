#ifndef UTILS_LINEAR_SEARCH_MAP_H
#define UTILS_LINEAR_SEARCH_MAP_H

#include "Map.h"
#include "ArrayList.h"
#include "Pair.h"

namespace utils
{

template<typename K, typename V>
class LinearSearchMap : public Map<K,V>
{
public:

  LinearSearchMap();
  LinearSearchMap(const V& defaultValue);
  LinearSearchMap(const LinearSearchMap& other);
  ~LinearSearchMap();

  V&                    operator [](const K& key);
  const V&              operator [](const K& key) const;
  LinearSearchMap<K,V>& operator =(const LinearSearchMap<K,V>& rhs);

  const ArrayList<K> getKeys() const; 
  void               clear();

private:

  V                     defaultObject;
  V                     defaultReturn;
  ArrayList<Pair<K,V> > pairs;

};

}

#include "LinearSearchMap.cpp"

#endif // UTILS_LINEAR_SEARCH_MAP_H
