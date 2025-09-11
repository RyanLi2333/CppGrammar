#pragma once 
#include <string> 

class Phone; // 声明类func

// 学生类
class Student {
	std::string s_id; // 成员变量，学生学号
	std::string s_name; // 成员变量，学生姓名 
	Phone* s_phone; // 学生手机

public: 
	Student(); // 空构造
	Student(const Student& other); // 深拷贝构造函数 
	Student(const std::string& id); // 构造函数(初始化列表)声明
	Student(const std::string& id, const std::string& name); // 构造函数声明重载 
	Student(const std::string& id, const std::string& name, const Phone& phone); // 重载
	Student& operator=(const Student& other); // 运算符重载
	~Student(); // 析构函数声明
	void getInfo() const; // 方法声明 const表示对方法进行限制，方法只读 
	void setInfo(const std::string& id, const std::string& name, const Phone& phone); // 方法声明，对学生学号和姓名进行修改 
};

// 手机类
class Phone {
	friend class Student;// 声明类做友元，Student类可以访问phone类的私有成员 
	std::string p_name; // 手机名

public:
	Phone(const std::string& name); 
	Phone();
	~Phone();
};

/*
C++中class和struct可以视为等价
class和strct的主要区别在于默认的权限控制等级不同
class默认private
struct默认public

封装
C++三大访问修饰等级：
public 随便整
protected 类内与子类可访问
private 最严格

析构函数和构造函数也可以设定在protected或private中，不一定非要public(在某些设计模式中常用)

创建一个类时，如果没有指定，那么编译器至少会自动构造：
1. 默认构造函数(空实现)
2. 默认析构函数(空实现)
3. 默认拷贝构造函数(浅拷贝) 
4. operator=重载(值拷贝)

友元用法：
friend + 声明
*/

