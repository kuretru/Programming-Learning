# 呉真的Python笔记本

## 数字类型

* int：整数，没有范围限制
* float：浮点数：有范围限制
* complex(real, imag)：复数

## 算数运算符

* //：(向左)取整
* **：求幂

## 数学函数`in math`

* log(x[,base])：以base为底的对数
* round(x[,n])：四舍五入取小数点后n位数

## 字符串

* 单引号，双引号，三引号任意使用
* 正向索引：0~(n-1)
* 反向索引：(-n)~(-1)

## 内置函数

### 转换函数

* bool()
* int() / float() / complex()
* str()
* ord()：Unicode字符转整数
* chr()：整数转Unicode字符
* bin() / oct() / hex()：进制转换
* list()：转列表

## 字符串操作

* 转为数字：`number = int(text)`
* 转为数组：`data = text.split()`

## 变量

* 获取变量类型：`type(ELEMENT)`
* 获取变量地址：`id(ELEMENT)`
* 删除变量：`del(ELEMENT)`

## 输入/输出

* 按字符串读入一整行：`text = input()`
* 带提示读入：`input("Tips")`
