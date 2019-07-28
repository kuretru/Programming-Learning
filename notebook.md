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

#### list 双向链表

#### stack 栈

* 入栈：`void stack.push(ELEMENT)`
* 出栈：`void stack.pop()`
* 栈顶元素：`ELEMENT = stack.top()`

#### queue 队列

* 入队：`void queue.push(ELEMENT)`
* 出队：`void queue.pop()`
* 队首元素：`ELEMENT = queue.front()`

#### set 红黑树

#### map 红黑树

* 插入元素：`map[key] = value`，覆盖插入
* 删除元素：`int map.erase(KEY)`，返回操作个数，1即为删除成功
* 访问元素：`value = map[key]`
* 是否存在：`int map.count(KEY)`，返回操作个数，1即为存在
* 迭代器：`iter->first`方位key值；`iter->second`方位value值
