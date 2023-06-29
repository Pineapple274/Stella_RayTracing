cmake_minimum_required(VERSION 3.0)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src SRC_LIST)
message(STATUS "This is BINARY dir " ${CMAKE_CURRENT_LIST_DIR}/include)
# set the project name and version
project(Stella_Raytracing VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# file(GLOB SOURCES "src/*.cpp")
# target_include_directories(${PROJECT_NAME}
#     PRIVATE 
#         ${CMAKE_CURRENT_LIST_DIR}/include
# )
# target_include_directories(${PROJECT_SOURCE_DIR}/include)

# add the executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

# # build a library for udp
# function(lib_udp_on_win)
# 	# dynamic library
# 	# ---------------------------------------------------------------------------------------------------

# 	# compiler is vs
# 	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
# 		# build program
# 		add_executable( ${PROJECT_NAME} ${lib_udp_type} ${udp_src} )

# 		# .h and .cxx files
# 		target_sources(${PROJECT_NAME} PRIVATE ${udp_src} )

# 		# use c++11
# 		target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

# 	endif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
# endfunction(lib_udp_on_win)

# if (CMAKE_SYSTEM_NAME MATCHES "Windows")
# 	lib_udp_on_win()
# endif()
