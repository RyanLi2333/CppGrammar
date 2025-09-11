#include <ostream>
#include <iostream> 
#include "LinkList.h" 

/// LinkNode 实现 
LinkNode::LinkNode() : LinkNode(ElemInit) {} // 无参构造
LinkNode::LinkNode(ElemType newData) : LinkNode(newData, nullptr) {} // 有参构造 
LinkNode::LinkNode(ElemType newData, LinkNode* nextAddr) : data(newData), next(nextAddr) {} // 完整有参构造
LinkNode::~LinkNode() = default;
/// LinkList 实现 
LinkList::LinkList() : head(new LinkNode()), length(0) {} 
LinkList::~LinkList() { clear(); } // 调用clear函数清空内容

// 按位序插入某个节点(不是索引)
bool LinkList::insert(int i, ElemType e) {
	if (getLength() + 1 < i || i <= 0) 
		return false; // 未初始化或长度超出 
	LinkNode* ship = head; // 设置游标，从头节点开始遍历 
	for (size_t index = 0; index < i - 1; ++index) 
		ship = ship->next; // 游到下一个节点 
	LinkNode* newNode = new LinkNode(e, ship->next); // 使用LinkNode有参构造 
	ship->next = newNode; // 接上 
	length++; // 长度递增
	return true; // 插入成功
}

// 清空链表 
bool LinkList::clear() { 
	if (length == 0) 
		return false; // 长度为0则清空失败 
	LinkNode* ship = head->next; 
	LinkNode* beforeNode = ship; // beforeNode保存即将删除的节点
	while (ship) {
		ship = ship->next; // 游到下一个节点 
		delete beforeNode; // 删除上一个所在的节点 
		beforeNode = ship; // 删除后同样进入下一个节点 
	} 
	length = 0; // 链表长度重置
	return true; // 清除完成 
}

// 返回链表长度 
int LinkList::getLength() const { return length; } // O(1)时间复杂度 

// 打印链表 
bool LinkList::print() const {
	if (length == 0) return false; // 啥也没有打印失败  
	LinkNode* ship = head->next; // 直接进入第一个数据节点  
	std::cout << ship->data;  // 打印数据
	while ((ship = ship->next)) 
		std::cout << ' ' << ship->data;
	std::cout << '\n'; 
	return true; // 打印完成 
}

bool LinkList::makeExample() {
	if (length != 0) return false; // 单链表有内容就不做模板  
	for (int i = 1; i <= 10; i++) 
		insert(i, i * i);
	return true; 
}

/// 全局函数实现 
std::ostream& operator<<(std::ostream& out, LinkList& list) {
	if (list.getLength() == 0) {
		out << "NULL"; // 没有内容则显式string提示输出 
		return out;
	}
	LinkNode* ship = list.head->next; // 直接把第一个数据节点传入ship 
	out << ship->data; // 打印首个数据节点的内容(不带空格)
	while ((ship = ship->next)) 
		out << ' ' << ship->data; // 输出本节点数据 
	return out;
}
