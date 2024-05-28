#include "SingletonBrokerSubscriber.h"
#include "SingletonMessageBroker.h"

const uint8_t SingletonBrokerSubscriber::MAX_MESSAGES_PER_SUBSCRIBER = 255U;

SingletonBrokerSubscriber::SingletonBrokerSubscriber(char const * const topicName):
  numMessages(0U),
  messageData(nullptr)
{
  SingletonMessageBroker::registerSubscriber(topicName, *this);
}

SingletonBrokerSubscriber::~SingletonBrokerSubscriber()
{
  clear();
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

  // Create new ByteString object to hold the message data
  ByteString * newByteData = new (std::nothrow) ByteString(message.pack(), message.size());
  if (nullptr == newByteData)
  {
    delete[] newMessageData;
    return;
  }

  // Make sure ByteString was created successfully
  if ((nullptr == newByteData.bytes) || (0U == newByteData.size))
  {
    delete[] newMessageData;
    delete[] newByteData;
    return;
  }

  // Replace queue
  ByteString * newMessagesData = new (std::nothrow) ByteString[numMesages + 1U];
  if (nullptr == newMessagesData)
  {
    delete[] newMessageData;
    delete[] newByteData;
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
    delete[] messagesData;
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
  ByteString * newMessagesData = new (std::nothrow) ByteString[numMessages - 1U];
  if (nullptr == newMessagesData)
  {
    return;
  }

  // Replace all but the first element
  for (uint8_t i = 1U; i < numMessages; ++i)
  {
    newMessagesData[i] = messagesData[i];
  }

  delete[] messagesData;
  messagesData = newMessagesData;
  numMessages--;
}

void SingletonBrokerSubscriber::clear()
{
  for (uint8_t i = 0U; i < numMessages; ++i)
  {
    delete messagesData[i];
  } 
  
  delete(messagesData);
  messagesData = nullptr;
}

