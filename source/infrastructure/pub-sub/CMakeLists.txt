set(MODEL_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/model)
set(MSG_DEF_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/message-definitions)
set(UTILS_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/../../utils)
set(ARRAY_LIST_DIR ${UTILS_DIR}/array-list)


list(APPEND INCLUDE_DIRS
  ${MSG_DEF_DIR}
  ${MODEL_DIR}
  ${ARRAY_LIST_DIR}
)

add_library(DriveStateCommand ${MSG_DEF_DIR}/DriveStateCommand.cpp)
target_include_directories(
  DriveStateCommand PUBLIC
  ${INCLUDE_DIRS}
)
