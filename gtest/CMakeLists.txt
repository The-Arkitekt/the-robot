cmake_minimum_required(VERSION 3.14)
project(the-robot-gtest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

########################################
# GTEST stuff
#
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#########################################
# Setup files and directories
#
set(GTEST_PUB_SUB_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/pub-sub)
set(GTEST_MSG_DEF_DIR   ${GTEST_PUB_SUB_DIR}/message-definitions)
set(GTEST_UTILS_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/utils)
set(ROBOT_SOURCE_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/../source)
set(INFRASTRUCTURE_DIR  ${ROBOT_SOURCE_DIR}/infrastructure)
set(PUB_SUB_DIR         ${INFRASTRUCTURE_DIR}/pub-sub)
set(MSG_DEF_DIR         ${PUB_SUB_DIR}/message-definition)
set(UTILS_DIR           ${ROBOT_SOURCE_DIR}/utils)
set(ARRAY_LIST_DIR      ${UTILS_DIR}/array-list)
set(QUEUE_DIR           ${UTILS_DIR}/queue)
set(LINKED_LIST_DIR     ${UTILS_DIR}/linked-list)
set(NODE_DIR            ${UTILS_DIR}/node)
set(OBSERVER_DIR        ${UTILS_DIR}/observer)
set(PAIR_DIR            ${UTILS_DIR}/pair)
set(MAP_DIR             ${UTILS_DIR}/map)

add_subdirectory(${PUB_SUB_DIR} pub-sub_bld)

list(APPEND LINK_LIBRARIES
  DriveStateCommand
)

list(APPEND INCLUDE_DIRS
  ${ARRAY_LIST_DIR}
  ${QUEUE_DIR}
  ${LINKED_LIST_DIR}
  ${NODE_DIR}
  ${OBSERVER_DIR}
  ${PAIR_DIR}
  ${MAP_DIR}
)

list(APPEND SOURCES
  ${GTEST_MSG_DEF_DIR}/DriveStateCommand-test.cpp
  ${GTEST_UTILS_DIR}/ArrayList-test.cpp
  ${GTEST_UTILS_DIR}/Queue-test.cpp
  ${GTEST_UTILS_DIR}/LinkedList-test.cpp
  ${GTEST_UTILS_DIR}/LinearSearchMap-test.cpp
)

########################################
# Setup project
#
add_executable(
  TheRobot-test
  ${SOURCES}
)

target_include_directories(
  TheRobot-test PUBLIC
  ${INCLUDE_DIRS}
)

target_link_libraries(
  TheRobot-test PUBLIC
  ${LINK_LIBRARIES}
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(TheRobot-test)
