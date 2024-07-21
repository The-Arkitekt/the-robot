#ifndef MESSAGES_NETWORK_MESSAGE_H
#define MESSAGES_NETWORK_MESSAGE_H

#include "Message.h"
#include <cstdint>

namespace Messages
{

class NetworkMessage : public PubSub::Message
{
public:

  NetworkMessage();
  NetworkMessage(const unsigned int               senderId,
                 const unsigned int               recipientId,
                 const Utils::ArrayList<uint8_t>& messageData);
  ~NetworkMessage();

  void                      initialize();
  unsigned int              getId() const;
  Utils::ArrayList<uint8_t> pack();
  void                      unpack(const Utils::ArrayList<uint8_t>& data);

  //------------------------
  // Message fields
  unsigned int              senderId;
  unsigned int              recipientId;
  Utils::ArrayList<uint8_t> messageData;

private:
  
  static const unsigned int IDENTIFIER        = 0U;
  static const unsigned int ID_SIZE           = sizeof(IDENTIFIER);
  static const unsigned int SENDER_ID_SIZE    = sizeof(senderId);
  static const unsigned int RECIPIENT_ID_SIZE = sizeof(recipientId);
  static const unsigned int NUM_BYTES_MINIMUM = ID_SIZE + SENDER_ID_SIZE + RECIPIENT_ID_SIZE + 1U;
  
  Utils::ArrayList<uint8_t> packedBytes;

};

}

#endif // MESSAGES_NETWORK_MESSAGE_H
