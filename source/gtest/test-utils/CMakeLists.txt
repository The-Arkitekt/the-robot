list(APPEND SOURCES
  TestMessage.cpp
  TestSubscriber.cpp
)

list(APPEND INCLUDE_DIRS
  "${CMAKE_CURRENT_SOURCE_DIR}/../../messaging/"
)

add_library(TestUtils ${SOURCES})
target_include_directories(
  TestUtils PUBLIC
  ${INCLUDE_DIRS}
)
