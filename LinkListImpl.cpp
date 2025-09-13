#include <ostream>
#include <iostream> 
#include "LinkList.h" 

/// LinkNode ʵ�� 
LinkNode::LinkNode() : LinkNode(ELEM_INIT_VALUE) {} // �޲ι���
LinkNode::LinkNode(ElemType new_data) : LinkNode(new_data, nullptr) {} // �вι��� 
LinkNode::LinkNode(ElemType new_data, LinkNode* next_addr) : data_(new_data), next_(next_addr) {} // �����вι���
LinkNode::~LinkNode() = default;

/// LinkList ʵ�� 
LinkList::LinkList() : head_(new LinkNode()), length_(0) {} 
LinkList::~LinkList() { 
	clear(); 
} // ����clear�����������

// ��λ�����ĳ���ڵ�(��������)
bool LinkList::insert(int i, ElemType e) {
	if (size() + 1 < i || i <= 0) 
		return false; // δ��ʼ���򳤶ȳ��� 
	
	LinkNode* ship = head_; // �����α꣬��ͷ�ڵ㿪ʼ���� 
	for (size_t index = 0; index < i - 1; ++index) 
		ship = ship->next_; // �ε���һ���ڵ� 
	
	LinkNode* newNode = new LinkNode(e, ship->next_); // ʹ��LinkNode�вι��� 
	ship->next_ = newNode; // ���� 
	length_++; // ���ȵ���
	return true; // ����ɹ�
}

// ������� 
bool LinkList::clear() { 
	if (length_ == 0) 
		return false; // ����Ϊ0�����ʧ�� 
	
	LinkNode* ship = head_->next_; 
	LinkNode* beforeNode = ship; // beforeNode���漴��ɾ���Ľڵ�
	while (ship) {
		ship = ship->next_; // �ε���һ���ڵ� 
		delete beforeNode; // ɾ����һ�����ڵĽڵ� 
		beforeNode = ship; // ɾ����ͬ��������һ���ڵ� 
	} 
	
	length_ = 0; // ����������
	return true; // ������ 
}

// ���������� 
size_t LinkList::size() const { 
	return length_; 
} // O(1)ʱ�临�Ӷ� 

// ��ӡ���� 
bool LinkList::print() const {
	if (length_ == 0) 
		return false; // ɶҲû�д�ӡʧ��  
	
	LinkNode* ship = head_->next_; // ֱ�ӽ����һ�����ݽڵ�  
	std::cout << ship->data_;  // ��ӡ����
	while ((ship = ship->next_)) 
		std::cout << ' ' << ship->data_;
	
	std::cout << '\n'; 
	return true; // ��ӡ��� 
}

bool LinkList::make_example() {
	if (length_ != 0) 
		return false; // �����������ݾͲ���ģ��  
	
	for (int i = 1; i <= 10; i++) 
		insert(i, i * i);
	return true; 
}

/// ȫ�ֺ���ʵ�� 
std::ostream& operator<<(std::ostream& out, LinkList& list) {
	if (list.size() == 0) {
		out << "NULL"; // û����������ʽstring��ʾ��� 
		return out;
	}

	LinkNode* ship = list.head_->next_; // ֱ�Ӱѵ�һ�����ݽڵ㴫��ship 
	out << ship->data_; // ��ӡ�׸����ݽڵ������(�����ո�)
	while ((ship = ship->next_)) 
		out << ' ' << ship->data_; // ������ڵ����� 

	return out;
}
