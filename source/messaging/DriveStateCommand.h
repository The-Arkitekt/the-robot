#ifndef DRIVE_STATE_COMMAND_H
#define DRIVE_STATE_COMMAND_H

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
  const uint8_t             identifier() const;
  const uint32_t            size() const;
  const ArrayList<uint8_t>& pack();
  void                      unpack(const ArrayList<uint8_t>& data);

  //------------------------
  // Message fields
  int8_t xDirection;
  int8_t yDirection;
  int8_t zDirection;

private:
  
  static const uint8_t  IDENTIFIER = 1U;
  static const uint32_t SIZE       = 4U;
  ArrayList<uint8_t>    packedBytes;

};

}

#endif // DRIVE_STATE_COMMAND_H
