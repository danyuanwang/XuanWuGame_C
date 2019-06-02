cmake_minimum_required (VERSION 3.0)
project (XWCommon)
add_Library(XWCommon 
Logger.cpp
)

include_directories ("${PROJECT_SOURCE_DIR}/../boost")
