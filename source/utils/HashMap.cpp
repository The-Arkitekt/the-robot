#include "HashMap.h"

namespace utils
{

template<typename KEY, typename VALUE>
HashMap<KEY, VALUE>::HashMap(const uint64_t capacity):
  numValues      (0U),
  occupiedIndices(capacity),
  arrayList      (capacity)
{
  clear();
}

template<typename KEY, typename VALUE>
HashMap<KEY, VALUE>::~HashMap()
{
}

template<typename KEY, typename VALUE>
const VALUE& HashMap<KEY, VALUE>::operator [](const KEY& key) const
{
  uint64_t index = hash(key);

  if (occupiedIndices[index])
  {
    // Check for collision 
    if (key != arrayList[index])
    {
      index = resolveCollision(index, key);
      if ((index < occupiedIndices.size()) &&
          (true == occupiedIndices[index]))
      {
        return arrayList[index];
      }
    }
  }

  // Done fucked up
  VALUE ret;
  return ret;       
}

template<typename KEY, typename VALUE>
VALUE& HashMap<KEY, VALUE>::operator [](const KEY& key)
{
  const VALUE& ret = this->[key];
  
  return ret;
}

template<typename KEY, Typename VALUE>
void HashMap<KEY, VALUE>::set(const KEY& key, const VALUE& value)
{
  uint64_t index = hash(key);
  
  // Handle collision
  if (occupiedIndices[index])
  {
    index = resolveCollision(index, key);
    if ((index < occupiedIndices.size()) &&
        (false == occupiedIndices[index]))
    {
      arrayList[index]       = value;
      occupiedIndices[index] = true;
      ++numValues;
    }
  }
}

template<typename KEY, typename VALUE>
uint64_t HashMap<KEY, VALUE>::size() const
{
  return numValues;
}

template<typename KEY, typename VALUE>
void HashMap<KEY, VALUE>::clear()
{
  for (uint_64_t i = 0U; i < occupiedIndices.size(); ++i)
  {
    occupiedIndices[i] = false;
  }
}

template<typename KEY, typename VALUE>
uint64_t HashMap<KEY, VALUE>::hash(const KEY& key) const
{
  // Probably a pretty bad hash function but whatever
  return static_cast<uint64_t>(&key) % arrayList.size();
}

template<typename KEY, typename VALUE>
uint64_t resolveCollision(const uint64_t index, const KEY& key) const
{
  const uint64_t capacity = arrayList.size();
  for (uint64_t i = 0U; i < capacity; ++i)
  {
    if (!occupiedIndices[index] ||
        (arrayList[index] == key))
    {
      return index;
    }

    ++index;
    if(capacity <= index)
    {
      index = 0U;
    }
  }

  // return index out of range
  return capacity;
}

}
