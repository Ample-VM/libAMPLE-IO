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

include("${CMAKE_CURRENT_LIST_DIR}/Generic/CMakeLists.txt")

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    include("${CMAKE_CURRENT_LIST_DIR}/Windows/CMakeLists.txt")
    add_compile_definitions(__WINDOWS__)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    include("${CMAKE_CURRENT_LIST_DIR}/POSIX/CMakeLists.txt")
    include("${CMAKE_CURRENT_LIST_DIR}/Darwin/CMakeLists.txt")
    add_compile_definitions(__DARWIN__)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    include("${CMAKE_CURRENT_LIST_DIR}/POSIX/CMakeLists.txt")
    include("${CMAKE_CURRENT_LIST_DIR}/Linux/CMakeLists.txt")
    add_compile_definitions(__LINUX__)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
    include("${CMAKE_CURRENT_LIST_DIR}/POSIX/CMakeLists.txt")
    include("${CMAKE_CURRENT_LIST_DIR}/Freebsd/CMakeLists.txt")
    add_compile_definitions(__FREEBSD__)
endif()
