#ifndef MESSAGING_TOPICS_H
#define MESSAGING_TOPICS_H

#include <cstdint>

namespace messaging
{

enum Topic
{
  DRIVE_STATE_COMMAND
};

static const uint8_t NUM_TOPIC_VALUES = 1U;

}

#endif // MESSAGING_TOPICS_H
