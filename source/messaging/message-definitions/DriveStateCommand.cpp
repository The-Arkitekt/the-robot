#include "DriveStateCommand.h"
#include <new>

namespace messaging
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

void DriveStateCommand::init()
{
  xDirection = 0;
  yDirection = 0;
  zDirection = 0;

  const uint64_t arrayListSize = packedBytes.size();
  for (uint64_t i = 0U; i < arrayListSize; ++i)
  {
    packedBytes[i] = 0U;
  }
}

uint8_t DriveStateCommand::identifier() const
{
  return IDENTIFIER;
}

utils::ArrayList<uint8_t> DriveStateCommand::pack()
{
  if (0U == packedBytes.size())
  {
    packedBytes.resize(NUM_BYTES);
  }
    
  packedBytes[0U] = static_cast<uint8_t>(xDirection);
  packedBytes[1U] = static_cast<uint8_t>(yDirection);
  packedBytes[2U] = static_cast<uint8_t>(zDirection);

  return packedBytes;
}

void DriveStateCommand::unpack(const utils::ArrayList<uint8_t>& data)
{
  if ((NUM_BYTES != data.size()) || (IDENTIFIER != data[0U]))
  {
    return;
  }

  xDirection = static_cast<int8_t>(data[1U]);
  yDirection = static_cast<int8_t>(data[2U]);
  zDirection = static_cast<int8_t>(data[3U]);
}

}
