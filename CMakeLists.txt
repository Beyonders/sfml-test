cmake_minimum_required(VERSION 2.6)
project(myproject)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Set version information in a config.h file
#set(myproject_VERSION_MAJOR 1)
#set(myproject_VERSION_MINOR 0)
#configure_file(
#  "${PROJECT_SOURCE_DIR}/config.h.in"
#  "${PROJECT_BINARY_DIR}/config.h"
#  )
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "sfml-test")
FILE(GLOB SOURCES "SFML Test.cpp")
add_executable(${EXECUTABLE_NAME} ${SOURCES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

#ADD_SUBDIRECTORY(data)
configure_file(humans.png ${CMAKE_CURRENT_BINARY_DIR}/humans.png COPYONLY)
configure_file(JLSSpaceGothicR.ttf ${CMAKE_CURRENT_BINARY_DIR}/JLSSpaceGothicR.ttf COPYONLY)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
install(TARGETS ${DATA} DESTINATION bin)


# CPack packaging
#include(InstallRequiredSystemLibraries)
#set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
#set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
#include(CPack)
