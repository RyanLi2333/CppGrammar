#include <iostream> 
#include <string>
#include "Student.h" 

// ѧ����ʵ��
Student::Student() : Student("0000", "UNKNOWN", Phone()) {} // ί�й��캯�������캯������ͬһ�����е���һ�����캯��
Student::Student(const std::string& id) : Student(id, "UNKNOWN", Phone()) {} // ���캯���ľ���ʵ��
Student::Student(const std::string& id, const std::string& name) : Student(id, name, Phone()) {} // ���캯���ľ���ʵ�� 

Student::Student(const std::string& id, const std::string& name, const Phone& phone) : s_id_(id), s_name_(name), s_phone_(new Phone(phone)) {
	std::cout << "Created a student successfully..." << '\n';
}

Student::Student(const Student& other) : s_id_(other.s_id_), s_name_(other.s_name_), s_phone_(new Phone(*other.s_phone_)) { // �������
	std::cout << "Copied a student successfully..." << '\n';
}

Student& Student::operator=(const Student& other) {
	if (this != &other) { // ��ֹ�Ը�ֵ
		delete s_phone_; // �ͷž���Դ
		this->s_phone_ = new Phone(*other.s_phone_); // ���
		this->s_id_ = other.s_id_;
		this->s_name_ = other.s_name_;
	}
	return *this;
}

Student::~Student() { // ������������
	if (s_phone_ != nullptr) {
		delete s_phone_;
		this->s_phone_ = nullptr;
	}
	std::cout << "Deleted a student successfully..." << '\n'; 
}

void Student::getInfo() const { // ��Ա�����ľ���ʵ�� 
	std::cout << this->s_id_ << '\n'; 
	std::cout << this->s_name_ << '\n'; 
	std::cout << this->s_phone_->p_name << '\n'; // ������������Ԫ�����Է���Phone��˽�б���s_phone_
}

void Student::setInfo(const std::string& id, const std::string& name, const Phone& phone) { 
	if (s_phone_ != nullptr) {
		delete s_phone_;
		this->s_phone_ = nullptr;
	}
	this->s_id_ = id; // this��һ��ָ�룬˭����this��this��ָ��ʲô��Ķ���
	this->s_name_ = name; 
	this->s_phone_ = new Phone(phone);
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
