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
set(MESSAGING_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../messaging/")
add_subdirectory(${MESSAGING_DIR} messaging_bld)

list(APPEND LINK_LIBRARIES
  Messaging
)

list(APPEND INCLUDE_DIRS
  ${MESSAGING_DIR}
)

list(APPEND SOURCES
  "DriveStateCommand-test.cpp"
  "SingletonMessageBroker-test.cpp"
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
)

include(GoogleTest)
gtest_discover_tests(TheRobot-test)


