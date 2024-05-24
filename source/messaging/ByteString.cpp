#include "ByteString.h"

const uint8_t ByteString::MAX_BYTE_STRING_LENGTH = 255U;


ByteString::ByteString():
  bytes(nullptr),
  size (0U)
{
}

ByteString::ByteString(uint8_t const * const bytes, const uint8_t size):
  bytes(bytes),
  size (size)
{
}

ByteString::~ByteString()
{
}


