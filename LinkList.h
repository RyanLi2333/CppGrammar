#ifndef LINKLIST_H 
#define LINKLIST_H 
#include <ostream> 
#include <iostream>
using ElemType = int; // Ԫ��ֵ����
constexpr ElemType ElemInit{0}; // Ԫ��ֵ�������ݵĳ�ʼֵ 

class LinkNode { 
	friend class LinkList; 
	friend std::ostream& operator<<(std::ostream& cout, LinkList& list); 
private:
	ElemType data;
	LinkNode* next; 
public:
	LinkNode(); // ����
	LinkNode(ElemType newData); // �вι��� 
	LinkNode(ElemType newData, LinkNode* nextAddr); // �вι���2
	~LinkNode(); // ���� 
}; 

class LinkList { 
	friend std::ostream& operator<<(std::ostream& cout, LinkList& list);
private:
	LinkNode* head; // ͷ�ڵ� 
	int length; // ���ȣ���ѯO(1) 
public:
	LinkList(); 
	~LinkList();
	bool initialize(); // ��ʼ����ʹͷ���ڵ㲻����nullptr 
	bool insert(int i, ElemType e); // ��λ�������ֵ 
	bool destroy(); // ��������
	int getLength() const; // ����LinkList����O(1)ʵ��
	bool print(); // ��ӡ����  
	bool makeExample(); // ����һ��չʾ������
};

std::ostream& operator<<(std::ostream& out, LinkList& list); // ���������

#endif 