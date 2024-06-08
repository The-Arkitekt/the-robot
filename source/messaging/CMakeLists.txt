set(UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../utils/)

list(APPEND INCLUDE_DIRS
  ${UTILS_DIR}
)

list(APPEND SOURCES 
  DriveStateCommand.cpp
  SingletonMessageBroker.cpp
)

add_library(Messaging ${SOURCES})

target_include_directories(
  Messaging PUBLIC
  ${INCLUDE_DIRS}
)
