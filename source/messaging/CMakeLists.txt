set(UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../utils/)
set(ARRAY_LIST_DIR ${UTILS_DIR}/array-list)

list(APPEND INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${ARRAY_LIST_DIR}
)

list(APPEND SOURCES 
  DriveStateCommand.cpp
)

add_library(Messaging ${SOURCES})

target_include_directories(
  Messaging PUBLIC
  ${INCLUDE_DIRS}
)
