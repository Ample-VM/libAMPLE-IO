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

#include <AMPLE/IO/FileInfo.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <fileapi.h>

static inline bool AMPLE_IO_FileInfo_Length_CheckIfArgumentsAreInvalid(struct AMPLE_IO_FileInfo_t* fileInfo, int64_t* length)
{
    bool fileInfoIsNull = (fileInfo == (struct AMPLE_IO_FileInfo_t*)NULL);
    bool lengthIsNull = (length == (int64_t*)NULL);
    if (fileInfoIsNull || lengthIsNull)
    {
        return true;
    }

    bool fileNameIsNull = (fileInfo->_fileName == (const char*)NULL);
    bool fileNameIsInvalid = (fileInfo->_fileNameSize <= 1);    
    
    return !fileInfoIsNull && !fileNameIsInvalid;
}

AMPLE_IO_FILEINFO_LENGTH_RESULT AMPLE_IO_FileInfo_Length(struct AMPLE_IO_FileInfo_t* fileInfo, int64_t* length)
{
    bool invalidArguments = AMPLE_IO_FileInfo_Length_CheckIfArgumentsAreInvalid(fileInfo, length);
    if (invalidArguments)
    {
        return AMPLE_IO_FILEINFO_LENGHT_RESULT_INVALIDARGUMENTS;
    }

    HANDLE handle = CreateFile(name, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE handle = CreateFile(fileInfo->_fileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (handle == INVALID_HANDLE_VALUE)
    {
        return APLE_IO_FILEINFO_LENGTH_RESULT_INTERMNALERROR;
    }

    LARGE_INTEGER size;
    if (!GetFileSizeEx(hFile, &size))
    {
        CloseHandle(hFile);
        return APLE_IO_FILEINFO_LENGTH_RESULT_INTERMNALERROR;
    }

    CloseHandle(hFile);

    *length = size.QuadPart;
    return AMPLE_IO_FILEINFO_LENGHT_RESULT_SUCCESS;
}
