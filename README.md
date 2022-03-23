# DocAnalysis_cpp
study project based on cpp,

**本项目为个人学习C++之余的练手项目，来源课堂大作业，同时也写了一篇blog讲解相关的内容，配合[这篇博客](https://blog.csdn.net/qq_43578237/article/details/123579743)食用效果更佳**

## 介绍
C++练手项目——DocAnalysis。

本项目使用`C++`语言编写，在`Windows`系统下，使用`VScode`编译运行，实现以下效果
- 输入：两个`.docx`扩展名类型的文件
- 输出：
  - 统计并输出两个文档**多少字符相同，多少字符不同**
  - 统计并输出每个文档的**前十高频字或词**


## 最终工程文件结构

下面展示的是`DocAnalysis`目录下的文件结构：

```js
.
+-- main.cpp // 包含main函数定义，程序入口

// DocAnalysis类包含了程序运行的主逻辑
+-- DocAnalysis.h
+-- DocAnalysis.cpp

// WInFile类完成了基本的从文件中读取GBK编码字符并存储为宽字符类型的操作
+-- WInFile.h
+-- WInFile.cpp

// WOutFile类完成了输出GBK编码宽字符到文件的操作
+-- WOutFile.h
+-- WOutFile.cpp

// TrieTree类定义了字典树这一数据结构及其基本操作，由于template类的声明与实现必须放在同一个文件当中，所以这里采用.hpp文件类型
+-- TrieTree.hpp

+-- dict // dict文件夹存储相关字典
|   +-- baidu_stopwords.txt // 百度停止词词典
|   +-- dict.txt // 现代汉语词典

+-- 资本论 //输入文件1，用于Release下测试的长文档
|   +-- 资本论.docx
|   +-- 资本论.txt //1.docx转换之后的txt文件
|   +-- 资本论_result.txt //输出结果文件，包含词频和字频

+-- 共产党宣言 //输入文件2，用于Release下测试的长文档
|   +-- 共产党宣言.docx
|   +-- 共产党宣言.txt
|   +-- 共产党宣言_result.txt

+-- 1 //输入文件1，用于Debug下测试的短文档
|   +-- 1.docx
|   +-- 1.txt //1.docx转换之后的txt文件
|   +-- 1_result.txt //输出结果文件，包含词频和字频

+-- 2 //输入文件2，用于Debug下测试的短文档
|   +-- 2.docx
|   +-- 2.txt
|   +-- 2_result.txt
```

## 效果展示
对`资本论.docx`的分析如下：

> 前十高频词: 
> 资本 18273次
> 生产 12384次
> 价值 10518次
> 劳动 9528次
> 商品 6728次
> 货币 5590次
> 工人 4360次
> 形式 4011次
> 剩余 3482次
> 产品 3332次
>
> 前十高频字: 
> 资 23366次
> 产 18583次
> 不 16957次
> 生 16681次
> 价 14592次
> 动 12319次
> 人 11920次
> 工 11324次
> 值 10841次
> 品 10783次

结果存储在`资本论\资本论_result.txt`当中。对于字符相等与不相等数目的比较则直接显示在控制台窗口中。
