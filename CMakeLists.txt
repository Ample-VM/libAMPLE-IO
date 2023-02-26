cmake_minimum_required(VERSION 3.10)
project(AMPLE-IO VERSION 0.3.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)

set(SRC "")

include_directories("${CMAKE_CURRENT_LIST_DIR}/include/public")
include_directories("${CMAKE_CURRENT_LIST_DIR}/include/private")

include("${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt")

add_library("AMPLE-IO_shared" SHARED ${SRC})
add_library("AMPLE-IO_static" STATIC ${SRC})

if (NOT WIN32)
    set_target_properties("AMPLE-IO_shared" PROPERTIES OUTPUT_NAME AMPLE-IO)
    set_target_properties("AMPLE-IO_static" PROPERTIES OUTPUT_NAME AMPLE-IO)
endif()

target_include_directories("AMPLE-IO_shared" PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/public")
target_include_directories("AMPLE-IO_static" PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/public")