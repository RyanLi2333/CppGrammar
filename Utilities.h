#ifndef UTILITIES_H
#define UTILITIES_H 
#include <istream> 
#include <ostream> 
#include <iostream>
constexpr double MIN_EPSILON{1e-15}; // 最小误差精度  
constexpr double MAX_EPSILON{1e-9}; // 最大误差精度

namespace BasicFunc {
	void greeting(); // 问候函数 
	void farewell(); // 告别函数
	double getPI(); // 获取PI的值 
	bool isEqual(double x, double y); // 浮点数比较函数 
	bool greaterThan(double x, double y); // 浮点数比较x>y返回true，否则false 
	bool lessThan(double x, double y); // 浮点数比较x<y返回true，否则返回false  
	bool greaterEqual(double x, double y); // 大于等于 
	bool lessEqual(double x, double y); // 小于等于 
	bool isZero(double x); // 判断是否为0 
	template<typename T> // 模板放.h中定义
	void swapValue(T& x, T& y) { // 互换值 
		T tmp = x; // 临时变量tmp存储x的值  
		x = y;
		y = tmp;
	}
	template<typename T> // 展示值
	void printValue(const T& x, const T& y) {
		std::cout << "left value is " << x << '\n'; 
		std::cout << "right value is " << y << '\n';
	}
	template<typename T> // 选择排序O(n^2)
	void sortOfBasicArray(T* array, size_t length) {
		for (size_t ship = 0, minNum = 0; ship < length - 1; ++ship) { // 将首个数据赋给ship游标，表示数组下标
			minNum = ship; // 重置minNum
			for (size_t tag = ship + 1; tag <= length - 1; tag++) { // ship之后的数的下标 
				if (array[tag] < array[minNum]) { // 发现有索引minNum小于索引ship的了 
					minNum = tag; // 把当前tag的值传给minNum标记
				}
			}
			if (minNum != ship) { // 交换数
				T tmp = array[ship]; 
				array[ship] = array[minNum]; 
				array[minNum] = tmp;
			}
		}
	} // 放入任意基本数据类型的数组实现从小到大排序 
	template<typename T> 
	void printArray(T* array, size_t length) {
		for (register size_t i = 0; i < length; ++i) {
			std::cout << array[i]; 
			if (i < length - 1) std::cout << ' '; 
		}
		std::cout << '\n';
	}
}

// 圆类 
class Circle { 
	friend double BasicFunc::getPI(); // 声明全局函数做友元，全局函数可以访问该类私有成员 
	friend std::istream& operator>>(std::istream& cin, Circle& circle); // 友元 
	friend bool operator==(const Circle& c1, const Circle& c2); 
	friend bool operator!=(const Circle& c1, const Circle& c2);
	friend bool operator>(const Circle& c1, const Circle& c2);
	friend bool operator>=(const Circle& c1, const Circle& c2);
	friend bool operator<(const Circle& c1, const Circle& c2);
	friend bool operator<=(const Circle& c1, const Circle& c2);
	static constexpr double C_PI = 3.14159265358979323846; // 类内定义类属性
	mutable double c_radius; // 圆的半径，mutable修饰的声明使其在const中可修改

// 类默认private 
public:
	Circle(); // 无参构造
	Circle(double radius); // 带参构造 
	Circle(const Circle& other); // 拷贝构造函数
	~Circle(); // 析构函数 
	void setRadius(double radius); // 方法，设置半径
	double getRadius() const; // 返回圆的半径 
	double getC() const; // 求圆的周长
	double getArea() const; // 求圆的面积  
	Circle& addRadiusFrom(Circle& other); // 半径链式加法 
	Circle operator+(const Circle& other); // 运算符重载 
	Circle operator+(const double& other); // 重载运算符本身也可以重载
	Circle& operator=(const Circle& other); // 赋值运算符重载 
	Circle& operator+=(const Circle& other); // 加法赋值运算符重载 
	Circle& operator-=(const Circle& other); // 减法赋值运算符重载 
	Circle& operator++(); // 前置自增运算符重载 
	Circle operator++(int); // 后置自增运算符重载，这里的无名形参int是C++语法规范强制规定的
	Circle& operator--(); // 前置自减运算符重载 
	Circle operator--(int); // 后置自减运算符重载  
	void operator()(); // 函数调用运算符重载，类似python的__call__方法
};

std::ostream& operator<<(std::ostream& out, const Circle& circle); // 声明左移运算符重载 
std::istream& operator>>(std::istream& in, Circle& circle); // 右移运算符重载 
bool operator==(const Circle& c1, const Circle& c2); // 等于号重载  
bool operator!=(const Circle& c1, const Circle& c2); // 不等于号重载 
bool operator>(const Circle& c1, const Circle& c2); // 大于号重载 
bool operator>=(const Circle& c1, const Circle& c2); // 大于等于号重载 
bool operator<(const Circle& c1, const Circle& c2); // 小于号重载 
bool operator<=(const Circle& c1, const Circle& c2); // 小于等于号重载 


/*
静态成员static
静态成员变量：就是类属性.
静态成员函数：就是类方法，只能访问类属性。 

在C++中，类的成员变量和类的成员函数分开存储，只有类的非静态成员变量存储在类的对象上 

关于定义与声明：
定义是一种特殊的声明，所有的定义都是声明，但不是所有的声明都是定义。
定义会使操作系统分配内存，声明仅仅告诉编译器某个函数/变量存在。
声明包含定义，定义包含于声明。

cpp类与面向对象模型中，编译器只帮你生成无参构造函数，但前提是：
没手动写任何构造函数且基类有默认构造函数可用(在继承关系中)
*/

#endif 