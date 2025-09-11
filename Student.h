#pragma once 
#include <string> 

class Phone; // ������func

// ѧ����
class Student {
	std::string s_id; // ��Ա������ѧ��ѧ��
	std::string s_name; // ��Ա������ѧ������ 
	Phone* s_phone; // ѧ���ֻ�

public: 
	Student(); // �չ���
	Student(const Student& other); // ������캯�� 
	Student(const std::string& id); // ���캯��(��ʼ���б�)����
	Student(const std::string& id, const std::string& name); // ���캯���������� 
	Student(const std::string& id, const std::string& name, const Phone& phone); // ����
	Student& operator=(const Student& other); // ���������
	~Student(); // ������������
	void getInfo() const; // �������� const��ʾ�Է����������ƣ�����ֻ�� 
	void setInfo(const std::string& id, const std::string& name, const Phone& phone); // ������������ѧ��ѧ�ź����������޸� 
};

// �ֻ���
class Phone {
	friend class Student;// ����������Ԫ��Student����Է���phone���˽�г�Ա 
	std::string p_name; // �ֻ���

public:
	Phone(const std::string& name); 
	Phone();
	~Phone();
};

/*
C++��class��struct������Ϊ�ȼ�
class��strct����Ҫ��������Ĭ�ϵ�Ȩ�޿��Ƶȼ���ͬ
classĬ��private
structĬ��public

��װ
C++����������εȼ���
public �����
protected ����������ɷ���
private ���ϸ�

���������͹��캯��Ҳ�����趨��protected��private�У���һ����Ҫpublic(��ĳЩ���ģʽ�г���)

����һ����ʱ�����û��ָ������ô���������ٻ��Զ����죺
1. Ĭ�Ϲ��캯��(��ʵ��)
2. Ĭ����������(��ʵ��)
3. Ĭ�Ͽ������캯��(ǳ����) 
4. operator=����(ֵ����)

��Ԫ�÷���
friend + ����
*/

