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
  
  virtual void setupServer(const unsigned int serverId, Observer<Utils::ArrayList<uint8_t> >& observer) = 0;
  virtual void sendToServer(const unsigned int serverId, const Utils::ArrayList<uint8_t>& data)         = 0;

}

}

#endif // NETWORK_INTERFACE_H
