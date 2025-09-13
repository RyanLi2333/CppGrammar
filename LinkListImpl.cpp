#include <ostream>
#include <iostream> 
#include "LinkList.h" 

/// LinkNode 实现 
LinkNode::LinkNode() : LinkNode(ELEM_INIT_VALUE) {} // 无参构造
LinkNode::LinkNode(ElemType new_data) : LinkNode(new_data, nullptr) {} // 有参构造 
LinkNode::LinkNode(ElemType new_data, LinkNode* next_addr) : data_(new_data), next_(next_addr) {} // 完整有参构造
LinkNode::~LinkNode() = default;

/// LinkList 实现 
LinkList::LinkList() : head_(new LinkNode()), length_(0) {} 
LinkList::~LinkList() { 
	clear(); 
} // 调用clear函数清空内容

// 按位序插入某个节点(不是索引)
bool LinkList::insert(int i, ElemType e) {
	if (size() + 1 < i || i <= 0) 
		return false; // 未初始化或长度超出 
	
	LinkNode* ship = head_; // 设置游标，从头节点开始遍历 
	for (size_t index = 0; index < i - 1; ++index) 
		ship = ship->next_; // 游到下一个节点 
	
	LinkNode* newNode = new LinkNode(e, ship->next_); // 使用LinkNode有参构造 
	ship->next_ = newNode; // 接上 
	length_++; // 长度递增
	return true; // 插入成功
}

// 清空链表 
bool LinkList::clear() { 
	if (length_ == 0) 
		return false; // 长度为0则清空失败 
	
	LinkNode* ship = head_->next_; 
	LinkNode* beforeNode = ship; // beforeNode保存即将删除的节点
	while (ship) {
		ship = ship->next_; // 游到下一个节点 
		delete beforeNode; // 删除上一个所在的节点 
		beforeNode = ship; // 删除后同样进入下一个节点 
	} 
	
	length_ = 0; // 链表长度重置
	return true; // 清除完成 
}

// 返回链表长度 
size_t LinkList::size() const { 
	return length_; 
} // O(1)时间复杂度 

// 打印链表 
bool LinkList::print() const {
	if (length_ == 0) 
		return false; // 啥也没有打印失败  
	
	LinkNode* ship = head_->next_; // 直接进入第一个数据节点  
	std::cout << ship->data_;  // 打印数据
	while ((ship = ship->next_)) 
		std::cout << ' ' << ship->data_;
	
	std::cout << '\n'; 
	return true; // 打印完成 
}

bool LinkList::make_example() {
	if (length_ != 0) 
		return false; // 单链表有内容就不做模板  
	
	for (int i = 1; i <= 10; i++) 
		insert(i, i * i);
	return true; 
}

/// 全局函数实现 
std::ostream& operator<<(std::ostream& out, LinkList& list) {
	if (list.size() == 0) {
		out << "NULL"; // 没有内容则显式string提示输出 
		return out;
	}

	LinkNode* ship = list.head_->next_; // 直接把第一个数据节点传入ship 
	out << ship->data_; // 打印首个数据节点的内容(不带空格)
	while ((ship = ship->next_)) 
		out << ' ' << ship->data_; // 输出本节点数据 

	return out;
}
