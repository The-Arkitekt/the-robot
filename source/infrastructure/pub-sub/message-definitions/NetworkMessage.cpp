#include "NetworkMessage.h"

namespace Messages
{

NetworkMessage::NetworkMessage():
  senderId   (0U),
  recipientId(0U),
  messageData(0U),
  packedBytes(0U)
{
}

NetworkMessage::NetworkMessage(const unsigned int               senderId,
                               const unsigned int               recipientId,
                               const Utils::ArrayList<uint8_t>& messageData):
  senderId   (senderId),
  recipientId(recipientId),
  messageData(messageData),
  packedBytes(0U)
{
}

NetworkMessage::~NetworkMessage()
{
}

void NetworkMessage::initialize()
{
  senderId    = 0U;
  recipientId = 0U;
  messageData.clear();
  packedBytes.clear();
}

unsigned int NetworkMessage::getId() const
{
  return IDENTIFIER;
}

Utils::ArrayList<uint8_t> NetworkMessage::pack()
{
  const unsigned int dataSize   = messageData.size();
  const unsigned int numBytes   = ID_SIZE + SENDER_ID_SIZE + RECIPIENT_ID_SIZE + dataSize;
  unsigned int       arrayIndex = 0U;
  uint8_t *          byteArray  = nullptr;

  packedBytes.resize(numBytes);
  
  unsigned int identifier = IDENTIFIER;
  byteArray = static_cast<uint8_t*>(static_cast<void*>(&identifier));
  for (unsigned int i = 0U; i < ID_SIZE; ++i)
  {
    packedBytes[arrayIndex++] = byteArray[i];
  }

  byteArray = static_cast<uint8_t*>(static_cast<void*>(&senderId));
  for (unsigned int i = 0U; i < SENDER_ID_SIZE; ++i)
  {
    packedBytes[arrayIndex++] = byteArray[i];
  }

  byteArray = static_cast<uint8_t*>(static_cast<void*>(&recipientId));
  for (unsigned int i = 0U; i < RECIPIENT_ID_SIZE; ++i)
  {
    packedBytes[arrayIndex++] = byteArray[i];
  }

  for (unsigned int i = 0U; i < dataSize; ++i)
  {
    packedBytes[arrayIndex++] = messageData[i];
  }

  return packedBytes;
}

void NetworkMessage::unpack(const Utils::ArrayList<uint8_t>& data)
{
  if ((NUM_BYTES_MINIMUM > data.size()) || (IDENTIFIER != data[0U]))
  {
    return;
  }

  const unsigned int messageDataSize = (data.size() - (ID_SIZE + SENDER_ID_SIZE + RECIPIENT_ID_SIZE));
  unsigned int       arrayIndex      = ID_SIZE;  

  initialize();
  messageData.resize(messageDataSize);

  for (unsigned int i = 0U; i < SENDER_ID_SIZE; ++i)
  {
    senderId |= (static_cast<unsigned int>(data[arrayIndex++]) << i);
  }

  for (unsigned int i = 0U; i < RECIPIENT_ID_SIZE; ++i)
  {
    recipientId |= (static_cast<unsigned int>(data[arrayIndex++]) << i);
  }

  
  for (unsigned int i = 0U; i < messageDataSize; ++i)
  {
    messageData[i] = data[arrayIndex++];
  }

}

}
