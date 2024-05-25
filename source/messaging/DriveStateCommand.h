#ifndef DRIVE_STATE_COMMAND_H
#define DRIVE_STATE_COMMAND_H

#include "Message.h"

class DriveStateCommand : public Message
{
public:

  DriveStateCommand();
  DriveStateCommand(const int8_t xDirection,
                    const int8_t yDirection,
                    const int8_t zDirection);
  ~DriveStateCommand();

  void                  init();
  const uint32_t        size() const;
  uint8_t const * const pack();
  void                  unpack(uint8_t const * const data, const uint32_t size);

  int8_t xDirection;
  int8_t yDirection;
  int8_t zDirection;

private:

  static const uint32_t SIZE = 3U;
  uint8_t * packedBytes;

};

#endif // DRIVE_STATE_COMMAND_H
