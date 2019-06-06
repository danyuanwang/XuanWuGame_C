cmake_minimum_required (VERSION 3.0)
project (XWCommon)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

add_Library(XWCommon 
Logger.cpp
)

include_directories ("${PROJECT_SOURCE_DIR}/../boost")
