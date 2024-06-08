#ifndef UTILS_OBSERVER_H
#define UTILS_OBSERVER_H

namespace utils
{

template<typename T>
class Observer
{
public:

  virtual void update(const T& object) = 0;

};

}

#endif // UTILS_OBSERVER_H
