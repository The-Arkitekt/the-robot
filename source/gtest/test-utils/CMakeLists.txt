set(UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../utils/)
set(MESSAGING_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../messaging/)

list(APPEND SOURCES
  TestMessage.cpp
)

list(APPEND INCLUDE_DIRS
  ${UTILS_DIR}
  ${MESSAGING_DIR}
)

add_library(TestUtils ${SOURCES})
target_include_directories(
  TestUtils PUBLIC
  ${INCLUDE_DIRS}
)
