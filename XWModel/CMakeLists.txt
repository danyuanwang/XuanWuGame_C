cmake_minimum_required (VERSION 3.0)
project (XWModel)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

add_Library(XWModel 
Board.cpp
Cell.cpp
CommonStructure.cpp
DataModel.cpp
GameModel.cpp
GameModelCallback.cpp
GamePlayRequest.cpp
Map.cpp
Mine.cpp
ModelObject.cpp
Panel.cpp
PanelAction.cpp
PanelScale.cpp
Player.cpp
)

include_directories ("${PROJECT_SOURCE_DIR}/../boost")
include_directories ("${PROJECT_SOURCE_DIR}/../XuanwuNet")

