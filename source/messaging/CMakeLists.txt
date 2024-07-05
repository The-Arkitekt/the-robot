set(MESSAGING_COMMON_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/common)
set(MESSAGING_DEFINITIONS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/message-definitions)

set(UTILS_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/../utils)
set(ARRAY_LIST_DIR ${UTILS_DIR}/array-list)



list(APPEND INCLUDE_DIRS
  ${MESSAGING_COMMON_DIR}
  ${MESSAGING_DEFINITIONS_DIR}
  ${ARRAY_LIST_DIR}
)

list(APPEND SOURCES 
  ${MESSAGING_DEFINITIONS_DIR}/DriveStateCommand.cpp
)

add_library(Messaging ${SOURCES})

target_include_directories(
  Messaging PUBLIC
  ${INCLUDE_DIRS}
)
