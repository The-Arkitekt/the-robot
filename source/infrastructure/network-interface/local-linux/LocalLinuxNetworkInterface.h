#ifndef LOCAL_LINUX_NETWORK_INTERFACE_H
#define LOCAL_LINUX_NETWORK_INTERFACE_H

#include "NetworkInterface.h"

namespace NetworkInterface
{

class LocalLinuxNetworkInterface : public NetworkInterface
{
public:

  LocalLinuxNetworkInterface();
  ~LocalLinuxNetworkInterface();

  unsigned int generateUniqueId();
  void setupServer(const unsigned int serverId, Observer<Utils::ArrayList<uint8_t> >& observer);
  void sendToServer(const unsigned int serverId, const Utils::ArrayList<uint8_t>& data)

}

}

#endif // LOCAL_LINUX_NETWORK_INTERFACE_H
