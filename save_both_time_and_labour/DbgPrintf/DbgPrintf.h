#include <windows.h>
#include <tchar.h>
#include <stdio.h>

inline void __cdecl OutputDebugStringF(const char *format , ...)
{
  va_list vlArgs;
  char *strBuffer = (char*)malloc(4096 * sizeof(char));
  // char *strBuffer = (char*)GlobalAlloc(GPTR, 4096 * sizeof(char));
  if(strBuffer == NULL)
  {
    return;
  }
  memset(strBuffer , 0 , 4096 * sizeof(char));

  va_start(vlArgs , format);
  _vsnprintf_s(strBuffer ,
               (4096 - 1) * sizeof(char) ,
               (4096 - 1) * sizeof(char) ,
               format ,
               vlArgs);
  va_end(vlArgs);
  strcat_s(strBuffer, 4096, "\n");
  OutputDebugStringA(strBuffer);
  free(strBuffer);
  // GlobalFree(strBuffer);
  return;
}

#ifdef _DEBUG
#define DbgPrintf OutputDebugStringF
#else
#define DbgPrintf
#endif