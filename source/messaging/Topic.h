#ifndef TOPIC_H
#define TOPIC_H

#include "Subscriber.h"
#include "Message.h"

class Topic
{
public:

  static const uint8_t MAX_SUBSCRIBERS_PER_TOPIC;

  Topic(char const * const name);
  ~Topic();

  char const * const name() const;
  void               addSubscriber(Subscriber& subscriber);
  void               update(Message& message) const;

private:

  uint8_t            numSubscribers;
  char const * const topicName;
  Subscriber **      subscribers;

};

#endif // TOPIC_H
