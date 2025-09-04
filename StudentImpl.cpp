#include <iostream> 
#include <string>
#include "Student.h" 

// ѧ����ʵ��
Student::Student() : Student("0000", "UNKNOWN", Phone()) {} // ί�й��캯�������캯������ͬһ�����е���һ�����캯��
Student::Student(const std::string& id) : Student(id, "UNKNOWN", Phone()) {} // ���캯���ľ���ʵ��
Student::Student(const std::string& id, const std::string& name) : Student(id, name, Phone()) {} // ���캯���ľ���ʵ�� 

Student::Student(const std::string& id, const std::string& name, const Phone& phone) : s_id(id), s_name(name), s_phone(new Phone(phone)) {
	std::cout << "Created a student successfully..." << '\n';
}

Student::Student(const Student& other) : s_id(other.s_id), s_name(other.s_name), s_phone(new Phone(*other.s_phone)) { // �������
	std::cout << "Copied a student successfully..." << '\n';
}

Student& Student::operator=(const Student& other) {
	if (this != &other) { // ��ֹ�Ը�ֵ
		delete s_phone; // �ͷž���Դ
		this->s_phone = new Phone(*other.s_phone); // ���
		this->s_id = other.s_id;
		this->s_name = other.s_name;
	}
	return *this;
}

Student::~Student() { // ������������
	if (s_phone != nullptr) {
		delete s_phone;
		this->s_phone = nullptr;
	}
	std::cout << "Deleted a student successfully..." << '\n'; 
}

void Student::getInfo() const { // ��Ա�����ľ���ʵ�� 
	std::cout << this->s_id << '\n'; 
	std::cout << this->s_name << '\n'; 
	std::cout << this->s_phone->p_name << '\n'; // ������������Ԫ�����Է���Phone��˽�б���s_phone
}

void Student::setInfo(const std::string& id, const std::string& name, const Phone& phone) { 
	if (s_phone != nullptr) {
		delete s_phone;
		this->s_phone = nullptr;
	}
	this->s_id = id; // this��һ��ָ�룬˭����this��this��ָ��ʲô��Ķ���
	this->s_name = name; 
	this->s_phone = new Phone(phone);
	std::cout << "Setting successfully..." << '\n'; 
}

// �ֻ���ʵ��
Phone::Phone() : Phone("UNKNOWN PHONE") {}

Phone::Phone(const std::string& name) : p_name(name) {
	std::cout << "Create a Phone: " << name << '\n'; 
} 

Phone::~Phone() {
	std::cout << "Deleted a phone" << '\n'; 
}
