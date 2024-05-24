#IFNDEF TOPIC_H
#DEFINE TOPIC_H

#include "Subscriber.h"
#include "Message.h"

class Topic
{
public:

  static const uint8_t MAX_SUBSCRIBERS_PER_TOPIC;

  Topic(char const * const name);
  ~Topic();

  char const * const name() const;
  const uint8_t      numSubscribers() const;
  void               addSubscriber(Subscriber& subscriber);
  void               update(Message& message) const;

private:

  uint8_t            numSubscribers;
  char const * const name;
  Subscriber **      subscribers;

}

#ENDIF // TOPIC_H
