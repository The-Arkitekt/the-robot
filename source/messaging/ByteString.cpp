#include "ByteString.h"

const uint8_t ByteString::MAX_BYTE_STRING_LENGTH = 255U;


ByteString::ByteString():
  bytes(nullptr),
  size (0U)
{
}

ByteString::ByteString(uint8_t const * const bytes, const uint8_t size)
  bytes(nullptr),
  size(0U)
{
  if ((nullptr == bytes) || (MAX_BYTE_STRING_LENGTH < size))
  {
    return;
  }

  this->bytes = new (std::nothrow) uint8_t[size];
  if (nullptr == this->bytes)
  {
    return;
  }
  
  for (uint8_t i = 0U; i < size; ++i)
  {
    this->bytes[i] = bytes[i];
  }

  this->size = size;
}

ByteString::~ByteString()
{
  delete[] bytes;
}


