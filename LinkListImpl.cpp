#include <ostream>
#include <iostream> 
#include "LinkList.h" 

/// LinkNode 实现 
LinkNode::LinkNode() : LinkNode(ElemInit) {} // 无参构造
LinkNode::LinkNode(ElemType newData) : LinkNode(newData, nullptr) {} // 有参构造 
LinkNode::LinkNode(ElemType newData, LinkNode* nextAddr) : data(newData), next(nextAddr) {} // 完整有参构造
LinkNode::~LinkNode() = default;
/// LinkList 实现 
LinkList::LinkList() : head(nullptr), length(0) {} 
LinkList::~LinkList() {
	destroy(); 
}

// 初始化链表 
bool LinkList::initialize() {
	if (head != nullptr)
		return false; // 已经初始化了就不需要再初始化  
	
	head = new LinkNode(); // 在堆区创建一个头节点，调用LinkNode构造方法 
	return true; // 成功初始化
}

// 按位序插入某个节点(不是索引)
bool LinkList::insert(int i, ElemType e) {
	if (head == nullptr || getLength() + 1 < i || i <= 0) // 未初始化或长度超出
		return false; 
	LinkNode* ship = head; // 设置游标，从头节点开始遍历 
	int index = 0; // 目前游标的位置(长度)
	while (index < i - 1) {
		ship = ship->next; // 游到下一个节点 
		index++; // 递增
	}
	LinkNode* newNode = new LinkNode(e, ship->next); // 使用LinkNode有参构造 
	ship->next = newNode; // 接上 
	length++; // 长度递增
	return true; // 插入成功
}

// 销毁链表 
bool LinkList::destroy() { 
	if (head == nullptr)
		return false;
	LinkNode* ship = head; 
	LinkNode* before = ship;
	while (ship != nullptr) {
		ship = ship->next; // 游到下一个节点 
		delete before; // 删除上一个节点 
		before = ship; // 跟着ship到下一个节点
	}
	length = 0; // 长度归零  
	head = nullptr; // 归nullptr
	return true;
}

// 返回链表长度 
int LinkList::getLength() const {
	return length; // O(1)时间复杂度 
}

// 打印链表 
bool LinkList::print() {
	if (head == nullptr || length == 0)
		return false; // 啥也没有打印失败  
	LinkNode* ship = head; 
	while (ship->next != nullptr) {
		ship = ship->next; // 游到下一个节点 
		std::cout << ship->data << ' ';
	} 
	std::cout << '\n'; 
	return true; // 打印完成 
}

bool LinkList::makeExample() {
	if (head != nullptr)
		return false; 
	initialize();
	for (int i = 1; i <= 10; i++) {
		insert(i, i * i);
	}
	return true; 
}

/// 全局函数实现 
std::ostream& operator<<(std::ostream& out, LinkList& list) {
	if (list.getLength() == 0) {
		out << "NULL"; 
		return out;
	}
	LinkNode* ship = list.head; 
	while (ship->next != nullptr) {
		ship = ship->next; //游到下个节点 
		out << ship->data << ' ';
	}
	return out;
}
