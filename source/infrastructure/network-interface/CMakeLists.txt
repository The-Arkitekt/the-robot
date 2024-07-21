set(UTILS_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/../../utils)
set(ARRAY_LIST_DIR ${UTILS_DIR}/array-list)
set(OBSERVER_DIR   ${UTILS_DIR}/observer)
set(LOCAL_LINUX_DIR ${CMAKE_CURRENT_SOURCE_DIR}/local-linux)


list(APPEND LOCAL_LINUX_INCLUDE_DIRS
  ${ARRAY_LIST_DIR}
  ${OBSERVER_DIR}
)
list(APPEND LOCAL_LINUX_SOURCES 
  ${LOCAL_LINUX_DIR}/LocalLinuxNetworkInterface.cpp
)
add_library(LocalLinuxNetworkInterface ${LOCAL_LINUX_SOURCES})
target_include_directories(
  LocalLinuxNetworkInterface PUBLIC
  ${LOCAL_LINUX_INCLUDE_DIRS}
)
