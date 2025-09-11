#include <istream> 
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Utilities.h" // ����ͷ�ļ�����.cpp�п���ȫ��using xx����.h��ʹ��std::

void func::greeting() {
	std::cout << "------Welcome to the world of Cpp... ------" << '\n'; 
} // �ʺ���

void func::farewell() {
	std::cout << "------See You... ------" << '\n'; 
} // ����� 

bool func::isEqual(double x, double y) {
	if (std::isnan(x) || std::isnan(y))
		return false;

	const double diff = std::fabs(x - y); // ��ֵ����ֵ 
	const double maxOne = std::max(std::fabs(x), std::fabs(y)); // ȡ�ø��Ծ���ֵ�����ֵ
	return diff < MIN_EPSILON || maxOne < MIN_EPSILON || diff < maxOne * MAX_EPSILON; // ����ʽ��� 
}

bool func::greaterThan(double x, double y) { 
	if (std::isnan(x) || std::isnan(y)) // ����x��yΪNaN�����
		return false; 

	const double diff = x - y; // �õ���ֵ  
	if (diff > MIN_EPSILON) // ������С���ȷ���true
		return true; 

	const double maxOne = std::max(std::fabs(x), std::fabs(y)); // ȡ�����ֵ 
	return diff > maxOne * MAX_EPSILON; // ������Ծ��ȷ���true
}

bool func::lessThan(double x, double y) { // С�ں�
	return greaterThan(y, x); // ͵��ʵ��
} 

bool func::greaterEqual(double x, double y) { // ���ڵ��ں�
	if (std::isnan(x) || std::isnan(y)) // ��������NaN����
		return false; 

	return !lessThan(x, y); // ͵��ʵ��
} 

bool func::lessEqual(double x, double y) { // С�ڵ��ں�
	if (std::isnan(x) || std::isnan(y)) // ��������NaN���� 
		return false;

	return !greaterThan(x, y); // ͵��ʵ�� 
} 

bool func::isZero(double x) {
	return isEqual(x, .0);
}

Circle::Circle() : Circle(.0) {} // ί�й��캯��  
Circle::Circle(const Circle& other) : Circle(other.c_radius) {}
Circle::Circle(double radius) : c_radius(func::lessThan(radius, .0) ? .0 : radius) {
	std::cout << "Create a circle... " << '\n'; 
} // ���ι��캯�� 

Circle::~Circle() { 
	std::cout << "Delete a circle... " << '\n'; 
} // ���������������� 

void Circle::setRadius(double radius) { 
	this->c_radius = radius;
} // ����Բ�İ뾶 

/*
��Ա������const���ε���thisָ��
thisָ����һ��ָ�볣������ָ���ָ�򲻿ɱ䣬����Ȼ����ͨ����ָ���޸�Ŀ���ֵ
����һ��const�൱�ڶ��޸�Ŀ���ֵҲ����������
�����Ҫ�ڳ�������Ҳ���Զ�ĳЩ��������ֵ���޸ģ���Ӧ������Щ�����Ķ����м���mutable�ؼ���
*/

double Circle::getRadius() const {
	return this->c_radius; 
} // ����Բ�İ뾶 

double Circle::getC() const {
	return 2.0 * Circle::C_PI * this->c_radius;
} // ��Բ���ܳ� 

double Circle::getArea() const {
	return Circle::C_PI * this->c_radius * this->c_radius;
} // ��Բ����� 

Circle& Circle::addRadiusFrom(Circle& other) {
	this->c_radius += other.c_radius;
	return *this;
} // Բ�İ뾶��ʽ�ӷ� 

double func::getPI() {
	return Circle::C_PI;
} // ����PI��ֵ

Circle Circle::operator+(const Circle& other) { // �ӷ����������
	return Circle(this->c_radius + other.c_radius); // �뾶���
}

Circle Circle::operator+(const double& other) { // �ӷ��������������
	return Circle(this->c_radius + other);
}

Circle& Circle::operator=(const Circle& other) { // ��ֵ���������
	if (this == &other) 
		return *this; // �Ը�ֵ

	this->c_radius = other.c_radius; // ��ֵ
	return *this; // ֧����ʽ��ֵ
} 

Circle& Circle::operator+=(const Circle& other) { // �ӷ���ֵ���������
	this->c_radius += other.c_radius;  
	return *this;
}

Circle& Circle::operator-=(const Circle& other) {
	this->c_radius -= other.c_radius; 
	if (func::lessThan(this->c_radius, .0))
		this->c_radius = .0; // �뾶����Ϊ�������������������ֱ�Ӹ�0 

	return *this;
}

/*
ͨ�������������������Ҫ��ȫ�ֺ������أ���Ϊ�������ػᵼ��circle >> cout�Ĺ����﷨(�ȼ���circle.operator>>(cout))
*/
std::ostream& operator<<(std::ostream& out, const Circle& circle) { // �������������
	out << "Radius = " << circle.getRadius(); 
	return out;
}

std::istream& operator>>(std::istream& in, Circle& circle) { // ������������� 
	in >> circle.c_radius;
	if (func::lessThan(circle.c_radius, .0)) // ����Ǹ���ֱ�ӹ���
		circle.c_radius = .0;

	return in;
}

/*
��Ҫ���и�ֵ�����������Ӧ��return *this��֧����ʽ��ֵ��
������Ҫ��ֵ�ģ�����+-*�Ⱦ���Ҫ����һ����ʱ����Խ�����д洢���߷��� 

���� cout  
cout��һ������Ķ���
*/ 

Circle& Circle::operator++() { 
	++this->c_radius; // �뾶����  
	return *this;
}

Circle Circle::operator++(int) {
	Circle tmp = *this; 
	this->c_radius++; // this->c_radius����
	return tmp;
} 

Circle& Circle::operator--() { // ǰ���Լ�
	--this->c_radius;
	return *this;
}

Circle Circle::operator--(int) { // �����Լ�
	Circle tmp = *this; 
	this->c_radius--; 
	return tmp;
}

/*
����������������뷵��ԭֵ�ĸ��������������һ����ʱ��������ʹ�ú�ᱻ�Զ����١�
*/

bool operator==(const Circle& c1, const Circle& c2) { // ���ں����� 
	return func::isEqual(c1.c_radius, c2.c_radius); 
} 

bool operator!=(const Circle& c1, const Circle& c2) { // ���Ⱥ�����
	if (std::isnan(c1.c_radius) || std::isnan(c2.c_radius))
		return false;

	return !func::isEqual(c1.c_radius, c2.c_radius);
}

bool operator>(const Circle& c1, const Circle& c2) { // ���ں����� 
	return func::greaterThan(c1.c_radius, c2.c_radius);
} 

bool operator>=(const Circle& c1, const Circle& c2) { // ���ڵ��ں����� 
	return func::greaterEqual(c1.c_radius, c2.c_radius); 
}

bool operator<(const Circle& c1, const Circle& c2) { // С�ں�����
	return func::lessThan(c1.c_radius, c2.c_radius);
}

bool operator<=(const Circle& c1, const Circle& c2) { // С�ڵ��ں�����
	return func::lessEqual(c1.c_radius, c2.c_radius); 
} 

void Circle::operator()() { // �����������������
	std::cout << "Radius = " << this->c_radius << '\n';
}
