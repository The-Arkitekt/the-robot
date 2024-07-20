#ifndef UTILS_CONTROLLER_H
#define UTILS_CONTROLLER_H

namespace Utils
{

class Controller
{

  virtual int calculateControl(const int desired, const int actual) = 0;

};

}

#endif // UTILS_CONTROLLER_H
