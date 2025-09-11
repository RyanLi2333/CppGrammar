#include <ostream>
#include <iostream> 
#include "LinkList.h" 

/// LinkNode ʵ�� 
LinkNode::LinkNode() : LinkNode(ElemInit) {} // �޲ι���
LinkNode::LinkNode(ElemType newData) : LinkNode(newData, nullptr) {} // �вι��� 
LinkNode::LinkNode(ElemType newData, LinkNode* nextAddr) : data(newData), next(nextAddr) {} // �����вι���
LinkNode::~LinkNode() = default;
/// LinkList ʵ�� 
LinkList::LinkList() : head(new LinkNode()), length(0) {} 
LinkList::~LinkList() { clear(); } // ����clear�����������

// ��λ�����ĳ���ڵ�(��������)
bool LinkList::insert(int i, ElemType e) {
	if (getLength() + 1 < i || i <= 0) 
		return false; // δ��ʼ���򳤶ȳ��� 
	LinkNode* ship = head; // �����α꣬��ͷ�ڵ㿪ʼ���� 
	for (size_t index = 0; index < i - 1; ++index) 
		ship = ship->next; // �ε���һ���ڵ� 
	LinkNode* newNode = new LinkNode(e, ship->next); // ʹ��LinkNode�вι��� 
	ship->next = newNode; // ���� 
	length++; // ���ȵ���
	return true; // ����ɹ�
}

// ������� 
bool LinkList::clear() { 
	if (length == 0) 
		return false; // ����Ϊ0�����ʧ�� 
	LinkNode* ship = head->next; 
	LinkNode* beforeNode = ship; // beforeNode���漴��ɾ���Ľڵ�
	while (ship) {
		ship = ship->next; // �ε���һ���ڵ� 
		delete beforeNode; // ɾ����һ�����ڵĽڵ� 
		beforeNode = ship; // ɾ����ͬ��������һ���ڵ� 
	} 
	length = 0; // ����������
	return true; // ������ 
}

// ���������� 
int LinkList::getLength() const { return length; } // O(1)ʱ�临�Ӷ� 

// ��ӡ���� 
bool LinkList::print() const {
	if (length == 0) return false; // ɶҲû�д�ӡʧ��  
	LinkNode* ship = head->next; // ֱ�ӽ����һ�����ݽڵ�  
	std::cout << ship->data;  // ��ӡ����
	while ((ship = ship->next)) 
		std::cout << ' ' << ship->data;
	std::cout << '\n'; 
	return true; // ��ӡ��� 
}

bool LinkList::makeExample() {
	if (length != 0) return false; // �����������ݾͲ���ģ��  
	for (int i = 1; i <= 10; i++) 
		insert(i, i * i);
	return true; 
}

/// ȫ�ֺ���ʵ�� 
std::ostream& operator<<(std::ostream& out, LinkList& list) {
	if (list.getLength() == 0) {
		out << "NULL"; // û����������ʽstring��ʾ��� 
		return out;
	}
	LinkNode* ship = list.head->next; // ֱ�Ӱѵ�һ�����ݽڵ㴫��ship 
	out << ship->data; // ��ӡ�׸����ݽڵ������(�����ո�)
	while ((ship = ship->next)) 
		out << ' ' << ship->data; // ������ڵ����� 
	return out;
}
