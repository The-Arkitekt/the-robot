set(UTILS_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/../../utils)
set(ARRAY_LIST_DIR ${UTILS_DIR}/array-list)
set(OBSERVER_DIR   ${UTILS_DIR}/observer)


list(APPEND INCLUDE_DIRS
  ${ARRAY_LIST_DIR}
  ${OBSERVER_DIR}
)

list(APPEND SOURCES 
  LocalLinuxNetworkInterface.cpp
)

add_library(NetworkInterface ${SOURCES})

target_include_directories(
  NetworkInterface PUBLIC
  ${INCLUDE_DIRS}
)
