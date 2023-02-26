/**
 * MIT License
 *
 * Copyright (c) 2022 Ample VM
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

#pragma once

#include <stdbool.h>
#include <stddef.h>

struct AMPLE_IO_FileInfo_t {
    const char* fileName;
    size_t fileNameLength;
};

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Construct a FileInfo instance.
 * Creates a FileInfo instance from the file name passed and places it in the FileInfo struct passed.
 * If it fails it will return false and if it succeeds it will return true.
 * The file name will be copied over so it is very important to destroy the object.
 * 
 * @param fileInfo A pointer pointing to sizeof(struct AMPLE_IO_FileInfo_t) bytes to place the new instance.
 * @param fileName The file name to base the FileInfo instance from.
 * @return bool 1 if the FileInfo constructor succeeded and 0 if it failed.
 */
bool AMPLE_IO_FileInfo_Construct(struct AMPLE_IO_FileInfo_t* fileInfo, const char* fileName);

#ifdef __cplusplus
}
#endif