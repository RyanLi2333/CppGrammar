#pragma once 
#include <ostream> 
#include <iostream> 
#include <cstddef> // size_t
using ElemType = int; // Ԫ��ֵ����
constexpr ElemType ELEM_INIT_VALUE{0}; // Ԫ��ֵ�������ݵĳ�ʼֵ 

class LinkNode { 
	friend class LinkList; 
	friend std::ostream& operator<<(std::ostream& cout, LinkList& list); 
private:
	ElemType data_;
	LinkNode* next_; 
public:
	LinkNode(); // ����
	LinkNode(ElemType newData); // �вι��� 
	LinkNode(ElemType newData, LinkNode* nextAddr); // �вι���2
	~LinkNode(); // ���� 
}; 

class LinkList { 
	friend std::ostream& operator<<(std::ostream& cout, LinkList& list);
private:
	LinkNode* head_; // ͷ�ڵ� 
	int length_; // ���ȣ���ѯO(1) 
public:
	LinkList(); 
	~LinkList();
	bool insert(int i, ElemType e); // ��λ�������ֵ 
	bool clear(); // ��������
	size_t size() const; // ����LinkList����O(1)ʵ��
	bool print() const; // ��ӡ����  
	bool make_example(); // ����һ��չʾ������
};

std::ostream& operator<<(std::ostream& out, LinkList& list); // ��������� 

/*
��ģ���뺯��ģ�������(deprecated)
1. ��ģ�岻֧����ʽ�����Ƶ�����Ҫ��ʽָ������(before C++17)
2. ��ģ��֧��Ĭ��ģ�����ͣ�����ģ������Ĭ��(before C++11) 
����ʹ�õ�C++17��׼�����Ծ͵���û˵����ע��汾�ż��� 

ģ�������ͨ�������
ģ����ֻ�ڱ�����ʱ����������ͨ����һ��ʼ����ʱ�ͱ�������
*/
