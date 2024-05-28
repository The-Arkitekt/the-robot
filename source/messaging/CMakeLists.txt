list(APPEND SOURCES 
  DriveStateCommand.cpp
  Topic.cpp
  SingletonMessageBroker.cpp
  SingletonBrokerPublisher.cpp
)

add_library(Messaging ${SOURCES})
