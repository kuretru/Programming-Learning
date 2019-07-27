# 呉真的PAT笔记本

## C++ STL

### string 字符串

* 获取字符串中的某个字符：`char c = text[i]`
* 数字转换为字符串：`string text = std::to_string(12345)`
* 字符串转换为数组：`int x = std::stoi("12345")`

### 容器

#### vector 顺序表

* 二维数组初始化`vector<vector<int> data(SIZE, vector<int>(SIZE, 0))`
* 插入：`data.pushback()`
* 迭代器中判断最后一个：`iter == data.end() - 1`

#### stack 栈

* 入栈：`stack.push()`
* 出栈：`stack.pop()`(仅出栈，不返回)
* 栈顶元素：`stack.top()`
