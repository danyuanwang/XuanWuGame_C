cmake_minimum_required (VERSION 3.0)
project (XuanwuNet)
add_Library(XuanwuNet 
Client.cpp
ConnectionMgr.cpp
ConnectionSession.cpp
GZip.cpp
MsgPump.cpp
NetMsgCallback.cpp
NetPackMsgHandler.cpp
NetSctructure.cpp
Server.cpp
TcpNetPackMsgHandler.cpp
)

include_directories ("${PROJECT_SOURCE_DIR}/../boost")
include_directories ("${PROJECT_SOURCE_DIR}/../XWModel")

