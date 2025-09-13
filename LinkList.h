#pragma once 
#include <ostream> 
#include <iostream> 
#include <cstddef> // size_t
using ElemType = int; // 元素值类型
constexpr ElemType ELEM_INIT_VALUE{0}; // 元素值类型数据的初始值 

class LinkNode { 
	friend class LinkList; 
	friend std::ostream& operator<<(std::ostream& cout, LinkList& list); 
private:
	ElemType data_;
	LinkNode* next_; 
public:
	LinkNode(); // 构造
	LinkNode(ElemType newData); // 有参构造 
	LinkNode(ElemType newData, LinkNode* nextAddr); // 有参构造2
	~LinkNode(); // 析构 
}; 

class LinkList { 
	friend std::ostream& operator<<(std::ostream& cout, LinkList& list);
private:
	LinkNode* head_; // 头节点 
	int length_; // 长度，查询O(1) 
public:
	LinkList(); 
	~LinkList();
	bool insert(int i, ElemType e); // 按位序插入新值 
	bool clear(); // 销毁链表
	size_t size() const; // 返回LinkList长度O(1)实现
	bool print() const; // 打印链表  
	bool make_example(); // 生成一段展示性链表
};

std::ostream& operator<<(std::ostream& out, LinkList& list); // 重载输出流 

/*
类模板与函数模板的区别：(deprecated)
1. 类模板不支持隐式类型推导，需要显式指明类型(before C++17)
2. 类模板支持默认模板类型，函数模板则无默认(before C++11) 
由于使用的C++17标准，所以就当我没说过，注意版本号即可 

模板类和普通类的区别：
模板类只在被调用时被创建；普通类在一开始编译时就被创建。
*/
