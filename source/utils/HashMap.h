#ifndef UTILS_HASH_MAP_H
#define UTILS_HASH_MAP_H

#include <cstdint>
#include "ArrayList.h"

namespace utils
{

template<typename KEY, typename VALUE>
class HashMap
{
public:

  HashMap(const uint64_t capacity);
  ~HashMap();

  const VALUE& operator [](const KEY& key) const;
  VALUE& operator [](const KEY& key);

  
  void     set(const KEY& key, const VALUE& value);
  uint64_t size() const;
  void     clear();

private:

  uint64_t hash(const KEY& key) const;
  uint64_t resolveCollision(const uint64_t index, const KEY& key) const;
  
  VALUE            defaultValue;
  uint64_t         numValues;
  ArrayList<bool>  occupiedIndices;
  ArrayList<VALUE> arrayList;
};

}

#include "HashMap.cpp"

#endif // UTILS_HASH_MAP_H
