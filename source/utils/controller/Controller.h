#ifndef UTILS_CONTROLLER_H
#define UTILS_CONTROLLER_H

#include <cstdint>

namespace utils
{

class Controller
{

  virtual int32_t calculateControl(const int32_t desired, const int32_t actual) = 0;

};

}

#endif // UTILS_CONTROLLER_H
