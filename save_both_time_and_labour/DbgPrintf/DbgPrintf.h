#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define DBG9527BUFFSIZE 4096

inline void __cdecl OutputDebugStringF(const TCHAR *format , ...)
{
  va_list vlArgs;
  TCHAR *strBuffer = (TCHAR*)malloc(DBG9527BUFFSIZE * sizeof(TCHAR));
  // TCHAR *strBuffer = new TCHAR(DBG9527BUFFSIZE);
  // char *strBuffer = (char*)GlobalAlloc(GPTR, DBG9527BUFFSIZE * sizeof(char));
  if(strBuffer == NULL)
  {
    return;
  }
  memset(strBuffer , 0 , DBG9527BUFFSIZE * sizeof(TCHAR));

  va_start(vlArgs , format);

#ifdef UNICODE
  _vsnwprintf_s(strBuffer ,
               (DBG9527BUFFSIZE - 1) ,
               (DBG9527BUFFSIZE - 1) ,
               format ,
               vlArgs);

#else // !UNICODE
  _vsnprintf_s(strBuffer ,
               (DBG9527BUFFSIZE - 1) ,
               (DBG9527BUFFSIZE - 1) ,
               format ,
               vlArgs);
#endif // UNICODE

  va_end(vlArgs);
  // strcat_s(strBuffer, DBG9527BUFFSIZE, "\n");
  OutputDebugString(strBuffer);
  free(strBuffer);
  // delete strBuffer;
  // GlobalFree(strBuffer);
  return;
}

inline void __cdecl OutputDebugStringFW(const WCHAR *format , ...)
{
  va_list vlArgs;
  WCHAR *strBuffer = (WCHAR*)malloc(DBG9527BUFFSIZE * sizeof(WCHAR));
  // char *strBuffer = (char*)GlobalAlloc(GPTR, DBG9527BUFFSIZE * sizeof(char));
  if(strBuffer == NULL)
  {
    return;
  }
  memset(strBuffer , 0 , DBG9527BUFFSIZE * sizeof(WCHAR));

  va_start(vlArgs , format);
  _vsnwprintf_s(strBuffer ,
               (DBG9527BUFFSIZE - 1) ,
               (DBG9527BUFFSIZE - 1) ,
               format ,
               vlArgs);

  va_end(vlArgs);
  // strcat_s(strBuffer, DBG9527BUFFSIZE, "\n");
  OutputDebugStringW(strBuffer);
  free(strBuffer);
  // GlobalFree(strBuffer);
  return;
}

inline void __cdecl OutputDebugStringFA(const char *format , ...)
{
  va_list vlArgs;
  char *strBuffer = (char*)malloc(DBG9527BUFFSIZE * sizeof(char));
  // char *strBuffer = (char*)GlobalAlloc(GPTR, DBG9527BUFFSIZE * sizeof(char));
  if(strBuffer == NULL)
  {
    return;
  }
  memset(strBuffer , 0 , DBG9527BUFFSIZE * sizeof(char));

  va_start(vlArgs , format);
  _vsnprintf_s(strBuffer ,
               (DBG9527BUFFSIZE - 1) ,
               (DBG9527BUFFSIZE - 1) ,
               format ,
               vlArgs);
  va_end(vlArgs);
  // strcat_s(strBuffer, DBG9527BUFFSIZE, "\n");
  OutputDebugStringA(strBuffer);
  free(strBuffer);
  // GlobalFree(strBuffer);
  return;
}

#ifdef _DEBUG
#define DbgPrintf OutputDebugStringF
#define DbgPrintfA OutputDebugStringFA
#define DbgPrintfW OutputDebugStringFW
#else
#define DbgPrintf
#define DbgPrintfA
#define DbgPrintfW
#endif