# MIT License
# 
# Copyright (c) 2023 Ample VM
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.10)
project(AMPLE-IO VERSION 0.3.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(AMPLE_IO_C_SRC "")
set(AMPLE_IO_CXX_SRC "")

include_directories("${CMAKE_CURRENT_LIST_DIR}/include/public")
include_directories("${CMAKE_CURRENT_LIST_DIR}/include/private")

include("${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt")

add_library("AMPLE-IO_shared" SHARED ${AMPLE_IO_C_SRC};${AMPLE_IO_CXX_SRC})
add_library("AMPLE-IO_static" STATIC ${AMPLE_IO_C_SRC};${AMPLE_IO_CXX_SRC})

if (NOT WIN32)
    set_target_properties("AMPLE-IO_shared" PROPERTIES OUTPUT_NAME AMPLE-IO)
    set_target_properties("AMPLE-IO_static" PROPERTIES OUTPUT_NAME AMPLE-IO)
endif()

target_include_directories("AMPLE-IO_shared" PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/public")
target_include_directories("AMPLE-IO_static" PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/public")

install(TARGETS "AMPLE-IO_shared"
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(TARGETS "AMPLE-IO_static"
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/public/"
        DESTINATION "include"
        FILES_MATCHING
        PATTERN "*.h")