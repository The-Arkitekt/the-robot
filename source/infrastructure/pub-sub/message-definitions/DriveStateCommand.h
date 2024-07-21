#ifndef MESSAGES_DRIVE_STATE_COMMAND_H
#define MESSAGES_DRIVE_STATE_COMMAND_H

#include "Message.h"
#include <cstdint>

namespace Messages
{

class DriveStateCommand : public PubSub::Message
{
public:

  DriveStateCommand();
  DriveStateCommand(const int8_t xDirection,
                    const int8_t yDirection,
                    const int8_t zDirection);
  ~DriveStateCommand();

  void                      initialize();
  unsigned int              getId() const;
  Utils::ArrayList<uint8_t> pack();
  void                      unpack(const Utils::ArrayList<uint8_t>& data);

  //------------------------
  // Message fields
  int8_t xDirection;
  int8_t yDirection;
  int8_t zDirection;

private:
  
  static const unsigned int IDENTIFIER = 1U;
  static const unsigned int ID_SIZE    = sizeof(IDENTIFIER);
  static const unsigned int NUM_BYTES  = ID_SIZE + 3U; // includes identifier

  Utils::ArrayList<uint8_t> packedBytes;

};

}

#endif // MESSAGES_DRIVE_STATE_COMMAND_H
