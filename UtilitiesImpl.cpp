#include <istream> 
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Utilities.h" // 链接头文件，在.cpp中可以全局using xx，在.h中使用std::

void BasicFunc::greeting() {
	std::cout << "------Welcome to the world of Cpp... ------" << '\n'; 
} // 问候函数

void BasicFunc::farewell() {
	std::cout << "------See You... ------" << '\n'; 
} // 告别函数 

bool BasicFunc::isEqual(double x, double y) {
	if (std::isnan(x) || std::isnan(y))
		return false;

	const double diff = std::fabs(x - y); // 差值绝对值 
	const double maxOne = std::max(std::fabs(x), std::fabs(y)); // 取得各自绝对值的最大值
	return diff < MIN_EPSILON || maxOne < MIN_EPSILON || diff < maxOne * MAX_EPSILON; // 函数式编程 
}

bool BasicFunc::greaterThan(double x, double y) { 
	if (std::isnan(x) || std::isnan(y)) // 处理x或y为NaN的情况
		return false; 

	const double diff = x - y; // 得到差值  
	if (diff > MIN_EPSILON) // 大于最小精度返回true
		return true; 

	const double maxOne = std::max(std::fabs(x), std::fabs(y)); // 取得最大值 
	return diff > maxOne * MAX_EPSILON; // 大于相对精度返回true
}

bool BasicFunc::lessThan(double x, double y) { // 小于号
	return greaterThan(y, x); // 偷懒实现
} 

bool BasicFunc::greaterEqual(double x, double y) { // 大于等于号
	if (std::isnan(x) || std::isnan(y)) // 独立处理NaN问题
		return false; 

	return !lessThan(x, y); // 偷懒实现
} 

bool BasicFunc::lessEqual(double x, double y) { // 小于等于号
	if (std::isnan(x) || std::isnan(y)) // 独立处理NaN问题 
		return false;

	return !greaterThan(x, y); // 偷懒实现 
} 

bool BasicFunc::isZero(double x) {
	return isEqual(x, .0);
}

Circle::Circle() : Circle(.0) {} // 委托构造函数  
Circle::Circle(const Circle& other) : Circle(other.c_radius) {}
Circle::Circle(double radius) : c_radius(BasicFunc::lessThan(radius, .0) ? .0 : radius) {
	std::cout << "Create a circle... " << '\n'; 
} // 含参构造函数 

Circle::~Circle() { 
	std::cout << "Delete a circle... " << '\n'; 
} // 析构函数不允许含参 

void Circle::setRadius(double radius) { 
	this->c_radius = radius;
} // 设置圆的半径 

/*
成员函数加const修饰的是this指针
this指针是一个指针常量，即指针的指向不可变，但依然可以通过该指针修改目标的值
加了一个const相当于对修改目标的值也进行了限制
如果想要在常函数中也可以对某些变量进行值的修改，则应该在这些变量的定义中加上mutable关键字
*/

double Circle::getRadius() const {
	return this->c_radius; 
} // 返回圆的半径 

double Circle::getC() const {
	return 2.0 * Circle::C_PI * this->c_radius;
} // 求圆的周长 

double Circle::getArea() const {
	return Circle::C_PI * this->c_radius * this->c_radius;
} // 求圆的面积 

Circle& Circle::addRadiusFrom(Circle& other) {
	this->c_radius += other.c_radius;
	return *this;
} // 圆的半径链式加法 

double BasicFunc::getPI() {
	return Circle::C_PI;
} // 返回PI的值

Circle Circle::operator+(const Circle& other) { // 加法运算符重载
	return Circle(this->c_radius + other.c_radius); // 半径相加
}

Circle Circle::operator+(const double& other) { // 加法运算符重载重载
	return Circle(this->c_radius + other);
}

Circle& Circle::operator=(const Circle& other) { // 赋值运算符重载
	if (this == &other) 
		return *this; // 自赋值

	this->c_radius = other.c_radius; // 赋值
	return *this; // 支持链式赋值
} 

Circle& Circle::operator+=(const Circle& other) { // 加法赋值运算符重载
	this->c_radius += other.c_radius;  
	return *this;
}

Circle& Circle::operator-=(const Circle& other) {
	this->c_radius -= other.c_radius; 
	if (BasicFunc::lessThan(this->c_radius, .0))
		this->c_radius = .0; // 半径不能为负数，如果减数过大则直接赋0 

	return *this;
}

/*
通常重载左右移运算符需要用全局函数重载，因为类中重载会导致circle >> cout的怪异语法(等价于circle.operator>>(cout))
*/
std::ostream& operator<<(std::ostream& out, const Circle& circle) { // 左移运算符重载
	out << "Radius = " << circle.getRadius(); 
	return out;
}

std::istream& operator>>(std::istream& in, Circle& circle) { // 右移运算符重载 
	in >> circle.c_radius;
	if (BasicFunc::lessThan(circle.c_radius, .0)) // 如果是负数直接归零
		circle.c_radius = .0;

	return in;
}

/*
需要进行赋值的重载运算符应当return *this以支持链式赋值；
而不需要赋值的，比如+-*等就需要创建一个临时对象对结果进行存储或者返回 

关于 cout  
cout是一个特殊的对象
*/ 

Circle& Circle::operator++() { 
	++this->c_radius; // 半径递增  
	return *this;
}

Circle Circle::operator++(int) {
	Circle tmp = *this; 
	this->c_radius++; // this->c_radius递增
	return tmp;
} 

Circle& Circle::operator--() { // 前置自减
	--this->c_radius;
	return *this;
}

Circle Circle::operator--(int) { // 后置自减
	Circle tmp = *this; 
	this->c_radius--; 
	return tmp;
}

/*
后置自增运算符必须返回原值的副本，这个副本是一个临时对象，它在使用后会被自动销毁。
*/

bool operator==(const Circle& c1, const Circle& c2) { // 等于号重载 
	return BasicFunc::isEqual(c1.c_radius, c2.c_radius); 
} 

bool operator!=(const Circle& c1, const Circle& c2) { // 不等号重载
	if (std::isnan(c1.c_radius) || std::isnan(c2.c_radius))
		return false;

	return !BasicFunc::isEqual(c1.c_radius, c2.c_radius);
}

bool operator>(const Circle& c1, const Circle& c2) { // 大于号重载 
	return BasicFunc::greaterThan(c1.c_radius, c2.c_radius);
} 

bool operator>=(const Circle& c1, const Circle& c2) { // 大于等于号重载 
	return BasicFunc::greaterEqual(c1.c_radius, c2.c_radius); 
}

bool operator<(const Circle& c1, const Circle& c2) { // 小于号重载
	return BasicFunc::lessThan(c1.c_radius, c2.c_radius);
}

bool operator<=(const Circle& c1, const Circle& c2) { // 小于等于号重载
	return BasicFunc::lessEqual(c1.c_radius, c2.c_radius); 
} 

void Circle::operator()() { // 函数调用运算符重载
	std::cout << "Radius = " << this->c_radius << '\n';
}
