# 呉真的PAT笔记本

## C++ 基础

### 输入输出

* 读入一整行：`std::getline(std::cin, text)`

### 常量

* int最大值：`INT32_MAX`
* int最小值：`INT32_MIN`
* 关闭stdio同步：`std::ios::sync_with_stdio(false)`

### 数学函数

* 随机数：`rand()`
* 绝对值：`abs()`
* 两数最大值：`std::max(left, right)`
* 排序：`std::sort(data.begin(), data.end())` in \<algorithm\>
* 数组最大值：`*std::max_element(data.begin(), data.end())` in \<algorithm\>
* 迭代器索引：`std::distance(data.begin(), iter)`

### 重写运算符

```c++
bool operator<(const student &y) const
{
    return grade > y.grade;
}

student operator+(const student &y)
{
    student s;
    s.grade = grade + y.grade;
    return s;
}
```

### 函数指针

```c++
void quick_sort(vector<int> &data);
void heap_sort(vector<int> &data);
void merge_sort(vector<int> &data);
void radix_sort(vector<int> &data);
typedef void (*sort_interface)(vector<int> &data);
sort_interface sort = radix_sort;
sort(data);
```

## C++ STL

### string 字符串

* 获取字符串中的某个字符：`char c = text[i]`
* 转换为小写：`std::transform(text.begin(), text.end(), text.begin(), ::tolower)`
* 数字转换为字符串：`string text = std::to_string(12345)`
* 字符串转换为数组：`int x = std::stoi("12345")`
* string转换为cstring：`char *c = text.c_str()` 或 `char *c = text.data()`
* cstring转换为string：`std::string text(c)`
* 求子串：`std::string sub = text.substr(start, length)`

### 容器

#### vector 顺序表

* 二维数组初始化：`vector<vector<int> data(SIZE, vector<int>(SIZE, 0))`
* 二维数组重新初始化：`data.resize(SIZE, vector<int>(SIZE, 0))`
* 插入：`data.pushback()`
* 第一个元素：`data.front()`；最后一个元素：`data.back()`
* 迭代器中判断最后一个：`iter == data.end() - 1`
* 判断相等：`data == tmp`
* 查找：`iter = std::find(data.begin(), data.end(), value)` in \<algorithm\>

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

* 插入元素：`set.insert(ELEMENT)`
* 删除元素：`set.erase(ELEMENT)`，返回操作个数，1即为删除成功
* 是否存在：`int set.count(ELEMENT)`，返回操作个数，1即为存在

#### map 红黑树

* 插入元素：`map[key] = value`，覆盖插入
* 插入元素：`map.insert(std::pair<K_TYPE, V_TYPE>(key, value))`
* 删除元素：`int map.erase(KEY)`，返回操作个数，1即为删除成功
* 访问元素：`value = map[key]`
* 是否存在：`int map.count(KEY)`，返回操作个数，1即为存在
* 迭代器：`iter->first`即为key值；`iter->second`即为value值

#### unordered_set 哈希表

* 内部不自动排序，迭代顺序与插入顺序相反的set

#### unordered_map 哈希表

* 内部不自动排序，迭代顺序与插入顺序相反的map

## 调试技巧

### 输出二叉树

逆时针旋转90度后输出二叉树

``` c++
void debug(node *head, int level)
{
    if (!head)
        return;
    debug(head->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%3d\n", head->data);
    debug(head->left, level + 1);
}
```
