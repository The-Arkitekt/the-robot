#include "SingletonBrokerSubscriber.h"

const uint8_t SingletonBrokerSubscriber::MAX_MESSAGES_PER_SUBSCRIBER = 255U;

SingletonBrokerSubscriber::SingletonBrokerSubscriber(char const * const topicName):
  numMessages(0U),
  messageData(nullptr)
{
}

SingletonBrokerSubscriber::~SingletonBrokerSubscriber()
{
  if (nullptr != messageData)
  {
    for (uint8_t i = 0U; i < numMessages; ++i)
    {
      if (nullptr != messageData[i].bytes)
      {
        delete(messageData[i].bytes);
        messageData[i].bytes = nullptr;
      }
    }
    
    delete(messageData);
    messageData = nullptr;
  }
}

uint8_t SingletonBrokerSubscriber::size() const
{
  return numMessages;
}

void SingletonBrokerSubscriber::push(Message& message)
{
  if ((MAX_MESSAGES_PER_SUBSCRIBER == numMessages) ||
      (0U == message.size())
  {
    return;
  }

  // Get byte data from message
  uint8_t * messageBytes = message.pack();
  if (nullptr == messageBytes)
  {
    return;
  }

  // Create byte string to add to queue
  uint8_t * newMessageData = new (message.size(), std::nothrow) uint8_t;
  if (nullptr == newMessageData)
  {
    return;
  }

  // Populate new Byte string with message data
  for (uint8_t i = 0U; i < message.size(); ++i)
  {
    newMessageData[i] = messageBytes[i];
  }

  ByteString * newByteData = new (std::nothrow) ByteString(newMessageData, message.size());
  if (nullptr == newByteData)
  {
    delete(newMessageData);
    return;
  }

  // Replace queue
  ByteString ** newMessagesData = new ((numMessages + 1), std::nothrow) ByteString *;
  if (nullptr == newMessagesData)
  {
    delete(newMessageData);
    delete(newByteData);
    return;
  }

  for (uint8_t i = 0U; i < numMessages; ++i)
  {
    newMessagesData[i] = messagesData[i];
  }

  // Add new ByteString to the end
  newMessagesData[numMessages++] = newByteData;

  if (nullptr != messagesData)
  {
    delete(messgesData);
    messagesData = nullptr;
  }

  messagesData = newMessagesData;
}

void SingletonBrokerSubscriber::pop(Message& message)
{
  if (0U == numMessages)
  {
    return;
  }

  message.unpack(messagesData[0U].bytes, messagesData[0U].size);

  // Replace Queue
  ByteString ** newMessagesData = new ((numMessages - 1), std::nothrow) ByteString *;
  if (nullptr == newMessagesData)
  {
    return;
  }

  // Replace all but the first element
  for (uint8_t i = 1U; i < numMessages; ++i)
  {
    newMessagesData[i] = messagesData[i];
  }

  delete(messagesData);
  messagesData = newMessagesData;
  numMessages--;
}

void SingletonBrokerSubscriber::clear()
{
  if (nullptr != messagesData)
  {
    for (uint8_t i = 0U; i < numMessages; ++i)
    {
      if (nullptr != messagesData[i].bytes)
      {
        delete(messagesData[i].bytes;
        messagesData[i].bytes = nullptr;
      }
    }
  
    delete(messagesData);
    messagesData = nullptr;
  }
}

