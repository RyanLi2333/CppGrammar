#include <ostream>
#include <iostream> 
#include "LinkList.h" 

/// LinkNode ʵ�� 
LinkNode::LinkNode() : LinkNode(ElemInit) {} // �޲ι���
LinkNode::LinkNode(ElemType newData) : LinkNode(newData, nullptr) {} // �вι��� 
LinkNode::LinkNode(ElemType newData, LinkNode* nextAddr) : data(newData), next(nextAddr) {} // �����вι���
LinkNode::~LinkNode() = default;
/// LinkList ʵ�� 
LinkList::LinkList() : head(nullptr), length(0) {} 
LinkList::~LinkList() {
	destroy(); 
}

// ��ʼ������ 
bool LinkList::initialize() {
	if (head != nullptr)
		return false; // �Ѿ���ʼ���˾Ͳ���Ҫ�ٳ�ʼ��  
	
	head = new LinkNode(); // �ڶ�������һ��ͷ�ڵ㣬����LinkNode���췽�� 
	return true; // �ɹ���ʼ��
}

// ��λ�����ĳ���ڵ�(��������)
bool LinkList::insert(int i, ElemType e) {
	if (head == nullptr || getLength() + 1 < i || i <= 0) // δ��ʼ���򳤶ȳ���
		return false; 
	LinkNode* ship = head; // �����α꣬��ͷ�ڵ㿪ʼ���� 
	int index = 0; // Ŀǰ�α��λ��(����)
	while (index < i - 1) {
		ship = ship->next; // �ε���һ���ڵ� 
		index++; // ����
	}
	LinkNode* newNode = new LinkNode(e, ship->next); // ʹ��LinkNode�вι��� 
	ship->next = newNode; // ���� 
	length++; // ���ȵ���
	return true; // ����ɹ�
}

// �������� 
bool LinkList::destroy() { 
	if (head == nullptr)
		return false;
	LinkNode* ship = head; 
	LinkNode* before = ship;
	while (ship != nullptr) {
		ship = ship->next; // �ε���һ���ڵ� 
		delete before; // ɾ����һ���ڵ� 
		before = ship; // ����ship����һ���ڵ�
	}
	length = 0; // ���ȹ���  
	head = nullptr; // ��nullptr
	return true;
}

// ���������� 
int LinkList::getLength() const {
	return length; // O(1)ʱ�临�Ӷ� 
}

// ��ӡ���� 
bool LinkList::print() {
	if (head == nullptr || length == 0)
		return false; // ɶҲû�д�ӡʧ��  
	LinkNode* ship = head; 
	while (ship->next != nullptr) {
		ship = ship->next; // �ε���һ���ڵ� 
		std::cout << ship->data << ' ';
	} 
	std::cout << '\n'; 
	return true; // ��ӡ��� 
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

/// ȫ�ֺ���ʵ�� 
std::ostream& operator<<(std::ostream& out, LinkList& list) {
	if (list.getLength() == 0) {
		out << "NULL"; 
		return out;
	}
	LinkNode* ship = list.head; 
	while (ship->next != nullptr) {
		ship = ship->next; //�ε��¸��ڵ� 
		out << ship->data << ' ';
	}
	return out;
}
