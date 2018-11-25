project(server C CXX)
set(PROJECT_NAME server)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

enable_language(C CXX)
get_property(languages GLOBAL PROPERTY ENABLED_LANGUAGES)

project(server LANGUAGES C CXX)
message("languages: ${languages}")

project(server VERSION 0.0.1)
set(server_DESCRIPTION "server: servidor UDP")

# if ("CXX" IN_LIST languages)
#  message("C enabled")
# endif()

# should we use our own math functions
option(USE_LIB "static Lib lib building" ON)

configure_file(
  ${PROJECT_SOURCE_DIR}/Include/versioncfg.h.in
  ${PROJECT_SOURCE_DIR}/Include/versioncfg.h
  )

# add lib pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# add the binary tree directory to the search path for include files
include_directories(${PROJECT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(HEADER_FILES ${PROJECT_SOURCE_DIR}/Include/versioncfg.h ${PROJECT_SOURCE_DIR}/Include/lib.h ${PROJECT_SOURCE_DIR}/Include/Defines_e_Estruturas.h)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Compiler Options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Werror -lnsl -lsocket")

# add the MathFunctions library?
if (USE_LIB)
include_directories(
   ${PROJECT_SOURCE_DIR}/Include
   )
add_subdirectory(Lib)

set(SOURCES ${PROJECT_SOURCE_DIR}/Arquivos_Server/Server.c)
set(CLIENT_SOURCES ${PROJECT_SOURCE_DIR}/Arquivos_Client/Client.c)
# set(EXTRA_LIBS ${EXTRA_LIBS} lib)
endif (USE_LIB)

# add the executable
add_executable(server ${SOURCES})
add_executable(client ${CLIENT_SOURCES})

target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT})

link_directories(${PROJECT_SOURCE_DIR}/Include)
target_link_libraries(server Lib)
target_link_libraries(client Lib)

install(TARGETS server DESTINATION ${EXECUTABLE_OUTPUT_PATH})

