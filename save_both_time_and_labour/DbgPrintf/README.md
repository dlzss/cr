## 重写OutputDebugString函数，支持A版和W版

### 功能：

- 只在`Debug`下输出

- 支持格式化字符串，使其可以像`printf()`一样使用

### 使用方法：

```cpp
#include "DbgPrintf.h"
...
DbgPrintf(_T("Info %d: %s"), 1, _T("Hello"));
DbgPrintfA("Info %d: %s", 1, "Hello");
DbgPrintfW(L"Info %d: %s", 1, L"Hello"L);
...
```
