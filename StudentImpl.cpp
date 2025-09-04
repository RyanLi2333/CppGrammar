#include <iostream> 
#include <string>
#include "Student.h" 

// 学生类实现
Student::Student() : Student("0000", "UNKNOWN", Phone()) {} // 委托构造函数，构造函数调用同一个类中的另一个构造函数
Student::Student(const std::string& id) : Student(id, "UNKNOWN", Phone()) {} // 构造函数的具体实现
Student::Student(const std::string& id, const std::string& name) : Student(id, name, Phone()) {} // 构造函数的具体实现 

Student::Student(const std::string& id, const std::string& name, const Phone& phone) : s_id(id), s_name(name), s_phone(new Phone(phone)) {
	std::cout << "Created a student successfully..." << '\n';
}

Student::Student(const Student& other) : s_id(other.s_id), s_name(other.s_name), s_phone(new Phone(*other.s_phone)) { // 深拷贝构造
	std::cout << "Copied a student successfully..." << '\n';
}

Student& Student::operator=(const Student& other) {
	if (this != &other) { // 防止自赋值
		delete s_phone; // 释放旧资源
		this->s_phone = new Phone(*other.s_phone); // 深拷贝
		this->s_id = other.s_id;
		this->s_name = other.s_name;
	}
	return *this;
}

Student::~Student() { // 析构函数定义
	if (s_phone != nullptr) {
		delete s_phone;
		this->s_phone = nullptr;
	}
	std::cout << "Deleted a student successfully..." << '\n'; 
}

void Student::getInfo() const { // 成员方法的具体实现 
	std::cout << this->s_id << '\n'; 
	std::cout << this->s_name << '\n'; 
	std::cout << this->s_phone->p_name << '\n'; // 由于设置了友元，可以访问Phone的私有变量s_phone
}

void Student::setInfo(const std::string& id, const std::string& name, const Phone& phone) { 
	if (s_phone != nullptr) {
		delete s_phone;
		this->s_phone = nullptr;
	}
	this->s_id = id; // this是一个指针，谁调用this，this就指向什么类的对象
	this->s_name = name; 
	this->s_phone = new Phone(phone);
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
