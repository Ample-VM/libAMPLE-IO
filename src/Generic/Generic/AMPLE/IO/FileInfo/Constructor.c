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

static inline bool AMPLE_IO_FileInfo_Constructor_CheckIfArgumentsAreInvalid(struct AMPLE_IO_FileInfo_t* fileInfo, const char* fileName)
{
    bool fileInfoIsNull = (fileInfo == (struct AMPLE_IO_FileInfo_t*)NULL);
    bool fileNameIsNull = (fileName == (const char*)NULL);
    if (fileInfoIsNull || fileNameIsNull)
    {
        return true;
    }

    size_t fileNameSize = strlen(fileName);
    bool emptyFileName = (fileNameSize == 0);
    if (emptyFileName)
    {
        return true;
    }

    return false;
}

AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT AMPLE_IO_FileInfo_Constructor(struct AMPLE_IO_FileInfo_t* fileInfo, const char* fileName)
{
    bool invalidArguments = AMPLE_IO_FileInfo_Constructor_CheckIfArgumentsAreInvalid(fileInfo, fileName);
    if (invalidArguments)
    {
        return AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT_INVALIDARGUMENTS;
    }

    size_t fileNameSize = strlen(fileName);
    fileInfo->_fileNameSize = fileNameSize + 1;
    fileInfo->_fileName = (const char*)malloc(fileInfo->_fileNameSize * sizeof(const char));
    bool outOfMemory = (fileInfo->_fileName == (const char*)NULL);
    if (outOfMemory)
    {
        return AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT_OUTOFMEMORY;
    }

    (void)memcpy((void*)(fileInfo->_fileName), (const void*)fileName, fileInfo->_fileNameSize * sizeof(const char));

    fileInfo->Exists = AMPLE_IO_FileInfo_Exists;
    fileInfo->Lenght = AMPLE_IO_FileInfo_Length;
    fileInfo->Destructor = AMPLE_IO_FileInfo_Destructor;

    return AMPLE_IO_FILEINFO_CONSTRUCTOR_RESULT_SUCCESS;
}
