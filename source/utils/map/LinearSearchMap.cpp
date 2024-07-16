#include <new>

namespace utils
{

template<typename K, typename V>
LinearSearchMap<K,V>::LinearSearchMap(const V& defaultValue):
  defaultObject(defaultValue),
  defaultReturn(defaultValue),
  pairs        (Pair<K,V>(K(), defaultValue))
{
}

template<typename K, typename V>
LinearSearchMap<K,V>::LinearSearchMap(const LinearSearchMap& other):
  defaultObject(other.defaultObject),
  defaultReturn(other.defaultObject),
  pairs        (other.pairs)
{
}  

template<typename K, typename V>
LinearSearchMap<K,V>::~LinearSearchMap()
{
  clear();
}

template<typename K, typename V>
V& LinearSearchMap<K,V>::operator [](const K& key)
{
  const uint64_t numPairs = pairs.size();
  for (uint64_t i = 0U; i < numPairs; ++i)
  {
    if (key == pairs[i].first)
    {
      return pairs[i].second;
    }
  }

  // Add the new pair and return the value to be modified
  pairs.resize(numPairs + 1U);
  pairs[numPairs].first = key;

  return pairs[numPairs].second;
}

template<typename K, typename V>
const V& LinearSearchMap<K,V>::operator [](const K& key) const
{
  const uint64_t numPairs = pairs.size();
  for (uint64_t i = 0U; i < numPairs; ++i)
  {
    if (key == pairs[i].first)
    {
      return pairs[i].second;
    }
  }

  // can return default object here because const
  return defaultObject;
}

template<typename K, typename V>
Map<K,V>& LinearSearchMap<K,V>::operator =(const Map<K,V>& rhs)
{
  if (this != &rhs)
  {
    clear();
    ArrayList<K> keys = rhs.getKeys();
    uint64_t numKeys  = keys.size();
    
    pairs.resize(numKeys);

    for (uint64_t i = 0U; i < numKeys; ++i)
    {
      pairs[i].first  = keys[i];
      pairs[i].second = rhs[keys[i]];
    }
  }

  return *this;
}

template<typename K, typename V>
const ArrayList<K> LinearSearchMap<K,V>::getKeys() const
{
  uint64_t numKeys = pairs.size();

  ArrayList<K> keys(numKeys, K());
  
  for(uint64_t i = 0U; i < numKeys; ++i)
  {
    keys[i] = pairs[i].first;
  }

  return keys;
}

template<typename K, typename V>
void LinearSearchMap<K,V>::clear()
{
  pairs.clear();
}

}

