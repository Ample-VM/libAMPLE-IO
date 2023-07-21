/**
 * MIT License
 * 
 * Copyright (c) 2023 Ample VM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __AMPLE_IO_FILEINFO_H__
#define __AMPLE_IO_FILEINFO_H__

#pragma region Include Section
#ifndef __cplusplus
    #include <stddef.h>
    #include <stdint.h>
#else
    #include <cstddef>
    #include <cstdint>
#endif
#pragma endregion


#pragma region Define Section
#define AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT int8_t
#define AMPLE_IO_FILEINFO_DESTRUCTOR void

#define AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT_SUCCESS INT8_C(0)
#define AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT_INVALIDARGUMENTS INT8_C(-1)
#define AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT_OUTOFMEMORY INT8_C(-2)
#pragma endregion


#pragma region C link style for C++
#ifdef __cplusplus
extern "C"
{
#endif
#pragma endregion


#pragma region Struct Section
struct AMPLE_IO_FileInfo_t
{
    const char* _fileName;
    size_t _fileNameSize;
    AMPLE_IO_FILEINFO_DESTRUCTOR(*Destructor)(struct AMPLE_IO_FileInfo_t*);
};
#pragma endregion


#pragma region Fuction Section
AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT AMPLE_IO_FileInfo_Constructor(struct AMPLE_IO_FileInfo_t* fileInfo, const char* fileName);
AMPLE_IO_FILEINFO_DESTRUCTOR AMPLE_IO_FileInfo_Destructor(struct AMPLE_IO_FileInfo_t* fileInfo);
#pragma endregion


#pragma region C link style for C++
#ifdef __cplusplus
}
#endif
#pragma endregion

#endif//__AMPLE_IO_FILEINFO_H__
