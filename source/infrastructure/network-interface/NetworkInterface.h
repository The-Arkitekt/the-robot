#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include "Observer.h"
#include "ArrayList.h"
#include <cstdint>

namespace NetworkInterface
{

class NetworkInterface
{
public:

  virtual void configure(const char* configFilePath)                                                        = 0;
  virtual void registerSubscriber(const unsigned int subscriberId, unsigned int topicId)                    = 0;
  virtual void setupServer(const unsigned int subscriberId, Observer<Utils::ArrayList<uint8_t> >& observer) = 0;

}

}

#endif // NETWORK_INTERFACE_H
