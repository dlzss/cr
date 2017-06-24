## 重写OutputDebugString函数（ASCII版）

### 功能：

- 只在`Debug`下输出

- 支持格式化字符串，使其可以想`printf()`一样使用

### 使用方法：

```cpp
#include "DbgPrintf.h"
...
DbgPrintf("Info %d: %s", 1, "Hello");
...
```
