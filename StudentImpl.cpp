#include <iostream> 
#include <string>
#include "Student.h" 

// 学生类实现
Student::Student() : Student("0000", "UNKNOWN", Phone()) {} // 委托构造函数，构造函数调用同一个类中的另一个构造函数
Student::Student(const std::string& id) : Student(id, "UNKNOWN", Phone()) {} // 构造函数的具体实现
Student::Student(const std::string& id, const std::string& name) : Student(id, name, Phone()) {} // 构造函数的具体实现 

Student::Student(const std::string& id, const std::string& name, const Phone& phone) : s_id_(id), s_name_(name), s_phone_(new Phone(phone)) {
	std::cout << "Created a student successfully..." << '\n';
}

Student::Student(const Student& other) : s_id_(other.s_id_), s_name_(other.s_name_), s_phone_(new Phone(*other.s_phone_)) { // 深拷贝构造
	std::cout << "Copied a student successfully..." << '\n';
}

Student& Student::operator=(const Student& other) {
	if (this != &other) { // 防止自赋值
		delete s_phone_; // 释放旧资源
		this->s_phone_ = new Phone(*other.s_phone_); // 深拷贝
		this->s_id_ = other.s_id_;
		this->s_name_ = other.s_name_;
	}
	return *this;
}

Student::~Student() { // 析构函数定义
	if (s_phone_ != nullptr) {
		delete s_phone_;
		this->s_phone_ = nullptr;
	}
	std::cout << "Deleted a student successfully..." << '\n'; 
}

void Student::getInfo() const { // 成员方法的具体实现 
	std::cout << this->s_id_ << '\n'; 
	std::cout << this->s_name_ << '\n'; 
	std::cout << this->s_phone_->p_name << '\n'; // 由于设置了友元，可以访问Phone的私有变量s_phone_
}

void Student::setInfo(const std::string& id, const std::string& name, const Phone& phone) { 
	if (s_phone_ != nullptr) {
		delete s_phone_;
		this->s_phone_ = nullptr;
	}
	this->s_id_ = id; // this是一个指针，谁调用this，this就指向什么类的对象
	this->s_name_ = name; 
	this->s_phone_ = new Phone(phone);
	std::cout << "Setting successfully..." << '\n'; 
}

// 手机类实现
Phone::Phone() : Phone("UNKNOWN PHONE") {}

Phone::Phone(const std::string& name) : p_name(name) {
	std::cout << "Create a Phone: " << name << '\n'; 
} 

Phone::~Phone() {
	std::cout << "Deleted a phone" << '\n'; 
}
