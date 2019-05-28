cmake_minimum_required (VERSION 3.0)
project (XuanwuTcpSvr)
# The version number.
set (XuanwuTcpSvr_VERSION_MAJOR 1)
set (XuanwuTcpSvr_VERSION_MINOR 0)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/XuanwuConfig.h.in"
	"${PROJECT_SOURCE_DIR}/XuanwuConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find XuanwuConfig.h
#include_directories("${PROJECT_SOURCE_DIR}/include")

include_directories ("${PROJECT_SOURCE_DIR}/../boost")
include_directories ("${PROJECT_SOURCE_DIR}/../XuanwuNet")
include_directories ("${PROJECT_SOURCE_DIR}/../XWModel")

add_subdirectory (../XWModel ${PROJECT_BINARY_DIR}/XWModel)
add_subdirectory (../XuanwuNet ${PROJECT_BINARY_DIR}XuanwuNet)

set (EXTRA_LIBS ${EXTRA_LIBS} XWModel)
set (EXTRA_LIBS ${EXTRA_LIBS} XuanwuNet)

set(Boost_USE_MULTITHREADED      ON)

set( BOOST_ROOT "${PROJECT_SOURCE_DIR}/../boost" CACHE PATH "${PROJECT_SOURCE_DIR}/../boost/stage/lib" )

FIND_PACKAGE( Boost 1.67 REQUIRED COMPONENTS system thread iostreams)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )


# should we use our own math functions?
#option (USE_MYMATH "A sample of using compiling option" OFF)

# add the USE_MYMATH library?
#
#if (USE_MYMATH)
#  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
#  add_subdirectory (MathFunctions)
#  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
#endif (USE_MYMATH)
 
# add the executable
add_executable (XuanwuTcpSvr 
		GameServer.cpp
		XuanwuTcpSvr.cpp
		)

target_link_libraries (XuanwuTcpSvr  ${EXTRA_LIBS})
target_link_libraries (XuanwuTcpSvr  ${Boost_LIBRARIES})

# does this system provide the log and exp functions?
#include (CheckFunctionExists)
#check_function_exists (log HAVE_LOG)
#check_function_exists (exp HAVE_EXP)

# add the install targets
#install (TARGETS Xuanwu DESTINATION bin)
#install (FILES "${PROJECT_BINARY_DIR}/XuanwuConfig.h" DESTINATION include)


# build a CPack driven installer package
#include (InstallRequiredSystemLibraries)
#set (CPACK_RESOURCE_FILE_LICENSE
#     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
#set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
#set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
#include (CPack)

