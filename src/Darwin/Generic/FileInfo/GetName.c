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

#include <AMPLE/IO/FileInfo.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <libgen.h>

size_t AMPLE_IO_FileInfo_GetName(struct AMPLE_IO_FileInfo_t* fileInfo, char* fileName, size_t fileNameSize)
{
    bool fileInfoIsNull = (fileInfo == (struct AMPLE_IO_FileInfo_t*)NULL);
    bool fileNameIsNull = ((fileInfoIsNull) ? true : (fileInfo->fileName == (const char*)NULL));
    if (fileInfoIsNull || fileNameIsNull)
    {
        return -1;
    }

    bool isFolder = (fileInfo->fileName[fileInfo->fileNameLength - 1] == '/') ||
        (fileInfo->fileName[fileInfo->fileNameLength - 1] == '.');
    if (isFolder)
    {
        return 0;
    }

    char* trueFileName = basename((char*)(fileInfo->fileName));
    size_t trueFileNameSize = strlen(trueFileName) + 1;

    bool fileNameDestinationIsNull = (fileName == (char*)NULL);
    if (fileNameDestinationIsNull)
    {
        return trueFileNameSize;
    }

    size_t bytesToCopy = (fileNameSize < trueFileNameSize) ? fileNameSize : trueFileNameSize;

    memcpy((void*)fileName, (const char*)(trueFileName), bytesToCopy);

    return bytesToCopy;
}
