#ifndef BYTE_STRING_H
#define BYTE_STRING_H

class ByteString
{
public:

  static const uint8_t MAX_BYTE_STRING_LENGTH;

  ByteString();
  ByteString(uint8_t const * const bytes, const uint8_t size);
  ~ByteString();

  uint8_t const * const bytes;
  uint8_t               size;

}

#endif // BYTE_STRING_H
