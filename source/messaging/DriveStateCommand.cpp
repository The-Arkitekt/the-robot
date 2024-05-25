#include "DriveStateCommand.h"
#include <new>

DriveStateCommand::DriveStateCommand():
  xDirection (0),
  yDirection (0),
  zDirection (0),
  packedBytes(nullptr)
{
}

DriveStateCommand::DriveStateCommand(const int8_t xDirection,
                                     const int8_t yDirection,
                                     const int8_t zDirection):
  xDirection (xDirection),
  yDirection (yDirection),
  zDirection (zDirection),
  packedBytes(nullptr)
{
}

DriveStateCommand::~DriveStateCommand()
{
  init();
}

void DriveStateCommand::init()
{
  xDirection = 0;
  yDirection = 0;
  zDirection = 0;
  
  delete[] packedBytes;
  packedBytes = nullptr;
}

const uint32_t DriveStateCommand::size() const
{
  return DriveStateCommand::SIZE;
}

uint8_t const * const DriveStateCommand::pack()
{
  if (nullptr == packedBytes)
  {
    packedBytes = new (std::nothrow) uint8_t[DriveStateCommand::SIZE];
  }
  
  if (nullptr != packedBytes)
  {
    packedBytes[0U] = static_cast<uint8_t>(xDirection);
    packedBytes[1U] = static_cast<uint8_t>(yDirection);
    packedBytes[2U] = static_cast<uint8_t>(zDirection);
  }

  return packedBytes;
}

void DriveStateCommand::unpack(uint8_t const * const data, const uint32_t size)
{
  if ((nullptr == data) || (DriveStateCommand::SIZE != size))
  {
    return;
  }

  xDirection = static_cast<int8_t>(data[0U]);
  yDirection = static_cast<int8_t>(data[1U]);
  zDirection = static_cast<int8_t>(data[2U]);
}



  
