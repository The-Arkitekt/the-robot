#include "DriveStateCommand.h"
#include <new>

namespace Messages
{

DriveStateCommand::DriveStateCommand():
  xDirection (0),
  yDirection (0),
  zDirection (0),
  packedBytes(0U)
{
}

DriveStateCommand::DriveStateCommand(const int8_t xDirection,
                                     const int8_t yDirection,
                                     const int8_t zDirection):
  xDirection (xDirection),
  yDirection (yDirection),
  zDirection (zDirection),
  packedBytes(0U)
{
}

DriveStateCommand::~DriveStateCommand()
{
}

void DriveStateCommand::initialize()
{
  xDirection = 0;
  yDirection = 0;
  zDirection = 0;
  packedBytes.clear();
}

unsigned int DriveStateCommand::getId() const
{
  return IDENTIFIER;
}

Utils::ArrayList<uint8_t> DriveStateCommand::pack()
{
  if (0U == packedBytes.size())
  {
    packedBytes.resize(NUM_BYTES);
  }
   
  unsigned int arrayIndex = 0U;
  unsigned int identifier = IDENTIFIER;
  uint8_t *    bytes      = static_cast<uint8_t*>(static_cast<void*>(&identifier));

  for (unsigned int i = 0U; i < ID_SIZE; ++i)
  {
    packedBytes[arrayIndex++] = bytes[i];
  }

  packedBytes[arrayIndex++] = static_cast<uint8_t>(xDirection);
  packedBytes[arrayIndex++] = static_cast<uint8_t>(yDirection);
  packedBytes[arrayIndex++] = static_cast<uint8_t>(zDirection);

  return packedBytes;
}

void DriveStateCommand::unpack(const Utils::ArrayList<uint8_t>& data)
{
  if ((NUM_BYTES != data.size()) || (IDENTIFIER != data[0U]))
  {
    return;
  }

  unsigned int arrayIndex = ID_SIZE;

  xDirection = static_cast<int8_t>(data[arrayIndex++]);
  yDirection = static_cast<int8_t>(data[arrayIndex++]);
  zDirection = static_cast<int8_t>(data[arrayIndex++]);
}

}
