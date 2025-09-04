#ifndef LINKLIST_H 
#define LINKLIST_H 
#include <ostream> 
#include <iostream>
using ElemType = int; // 元素值类型
constexpr ElemType ElemInit{0}; // 元素值类型数据的初始值 

class LinkNode { 
	friend class LinkList; 
	friend std::ostream& operator<<(std::ostream& cout, LinkList& list); 
private:
	ElemType data;
	LinkNode* next; 
public:
	LinkNode(); // 构造
	LinkNode(ElemType newData); // 有参构造 
	LinkNode(ElemType newData, LinkNode* nextAddr); // 有参构造2
	~LinkNode(); // 析构 
}; 

class LinkList { 
	friend std::ostream& operator<<(std::ostream& cout, LinkList& list);
private:
	LinkNode* head; // 头节点 
	int length; // 长度，查询O(1) 
public:
	LinkList(); 
	~LinkList();
	bool initialize(); // 初始化，使头部节点不再是nullptr 
	bool insert(int i, ElemType e); // 按位序插入新值 
	bool destroy(); // 销毁链表
	int getLength() const; // 返回LinkList长度O(1)实现
	bool print(); // 打印链表  
	bool makeExample(); // 生成一段展示性链表
};

std::ostream& operator<<(std::ostream& out, LinkList& list); // 重载输出流

#endif 