#ifndef UTILS_PAIR_H
#define UTILS_PAIR_H

namespace utils
{

template<typename FIRST, typename SECOND>
class Pair
{
public:

  Pair();
  Pair(const FIRST& first, const SECOND& second);
  ~Pair();

  FIRST  first;
  SECOND second;

};

}

#include "Pair.cpp"

#endif // UTILS_PAIR_H
