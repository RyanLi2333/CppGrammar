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
