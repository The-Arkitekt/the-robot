#ifndef MESSAGING_DRIVE_STATE_COMMAND_H
#define MESSAGING_DRIVE_STATE_COMMAND_H

#include "Message.h"

namespace messaging
{

class DriveStateCommand : public Message
{
public:

  DriveStateCommand();
  DriveStateCommand(const int8_t xDirection,
                    const int8_t yDirection,
                    const int8_t zDirection);
  ~DriveStateCommand();

  void                      init();
  uint8_t                   identifier() const;
  utils::ArrayList<uint8_t> pack();
  void                      unpack(const utils::ArrayList<uint8_t>& data);

  //------------------------
  // Message fields
  int8_t xDirection;
  int8_t yDirection;
  int8_t zDirection;

private:
  
  static const uint8_t      IDENTIFIER = 1U;
  static const uint32_t     NUM_BYTES  = 4U; // includes identifier

  utils::ArrayList<uint8_t> packedBytes;

};

}

#endif // MESSAGING_DRIVE_STATE_COMMAND_H
