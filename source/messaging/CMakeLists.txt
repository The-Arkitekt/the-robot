list(APPEND SOURCES 
  DriveStateCommand.cpp
  SingletonMessageBroker.cpp
)

add_library(Messaging ${SOURCES})
