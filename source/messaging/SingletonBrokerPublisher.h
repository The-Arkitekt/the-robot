#ifndef SINGLETON_BROKER_PUBLISHER_H
#define SINGLETON_BROKER_PUBLISHER_H

#include "Publisher.h"

class SingletonBrokerPublisher : public Publisher
{
public:

  SingletonBrokerPublisher(char const * const  topicName);
  ~SingletonBrokerPublisher();

  void publish(Message& message);

private:

  char const * const topicName;

};

#endif // SINGLETON_BROKER_PUBLISHER_H
