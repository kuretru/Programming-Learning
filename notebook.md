# 呉真的PAT笔记本
## C++ STL
#### 字符串
* 获取字符串中的某个字符：`char c = text[i]`
* 数字转换为字符串：`string text = std::to_string(12345)`
* 字符串转换为数组：`int x = std::stoi("12345")`
#### 容器
##### vector 顺序表
* 二维数组初始化`vector<vector<int> data(SIZE, vector<int>(SIZE, 0))`
* 插入：`data.pushback()`
* 迭代器中判断最后一个：`iter == data.end() - 1`

## 数据结构
