#pragma once
#include <istream> 
#include <ostream> 
#include <iostream> 
#include <utility> // 使用std::swap 
#include <cstddef> // 使用size_t
constexpr double MIN_EPSILON{1e-15}; // 最小误差精度  
constexpr double MAX_EPSILON{1e-9}; // 最大误差精度

class Circle; // 提前声明有Circle

namespace func {
	void greeting(); // 问候函数 
	void farewell(); // 告别函数
	double getPI(); // 获取PI的值 
	bool isEqual(double x, double y); // 浮点数比较函数 
	bool greaterThan(double x, double y); // 浮点数比较x>y返回true，否则false 
	bool lessThan(double x, double y); // 浮点数比较x<y返回true，否则返回false  
	bool greaterEqual(double x, double y); // 大于等于 
	bool lessEqual(double x, double y); // 小于等于 
	bool isZero(double x); // 判断是否为0 
	// 互换值 模板函数
	template<typename T> // 模板放.h中定义 
	void swapValue(T& x, T& y);
	// 展示值
	template<typename T> 
	void printValue(const T& x, const T& y); 
	// 放入任意基本数据类型的数组实现从小到大排序 
	template<typename T, size_t N> 
	void sortOfBasicArray(T (&array)[N]);
	// 打印任意基本数据类型的数组
	template<typename T, size_t N> 
	void printArray(const T(&array)[N]);
	// 任意基本数据类型相加
	template<typename T> 
	T addi(const T& x, const T& y);  
	// 为Circle entities定制的模板特化 
	template<>
	Circle func::addi<Circle>(const Circle& x, const Circle& y); // 声明
}

/*
模板 
如果同名，函数模板和函数默认调用函数
可以通过空模板参数列表主动调用模板函数
函数模板也可以发生重载 
只有在没有普通函数或模板匹配更精确时，编译器会调用函数模板

函数模板不可以发生隐式类型转换，但可以手动显式隐式类型转换 
函数模板显式指定类型可以发生隐式类型转换
*/

// 圆类 
class Circle { 
	friend Circle func::addi<Circle>(const Circle& x, const Circle& y); // 模板特化友元(带上namespace)
	friend double func::getPI(); // 声明全局函数做友元，全局函数可以访问该类私有成员 
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


/// 模板定义：
namespace func {  
	// 互换值模板函数 
	template<typename T> 
	void swapValue(T& x, T& y) {
		T tmp = x; // 临时变量tmp存储x的值  
		x = y;
		y = tmp;
	}
	// 打印两个变量值ab
	template<typename T> 
	void printValue(const T& x, const T& y) {
		std::cout << "left value is " << x << '\n';
		std::cout << "right value is " << y << '\n';
	}
	// 选择排序实现
	template<typename T, size_t N> 
	void sortOfBasicArray(T(&array)[N]) { // 基本数据类型数组选择排序 
		for (size_t i = 0; i + 1 < N; ++i) { // i最大只能达到i - 2的数
			size_t min_i = i; // 保存最小值的索引 
			for (size_t j = min_i + 1; j < N; ++j) {
				if (array[j] < array[min_i])
					min_i = j;
			}
			if (min_i != i) // 如果min_i和i已经不一样了，说明有更小的
				std::swap(array[i], array[min_i]);
		}
	} 
	// 打印数组 
	template<typename T, size_t N> // 这里的N是编译期声明的size_t参数N
	void printArray(const T(&array)[N]) { 
		if constexpr (N == 0) {
			std::cout << "[]"; // 打印空数组 
		} else if (N == 1) {
			std::cout << array[0]; // 打印第一个元素
		}
		for (size_t i = 1; i < N; ++i) { // 继续打印其他元素 
			std::cout << ' ' << array[i];
		}
		std::cout << '\n'; // 换行
	}
	// 相加模板函数
	template<typename T> 
	T addi(const T& x, const T& y) {
		return x + y; // 直接返回相加结果 
	} 
	// 模版特化，模板特化是一种普通函数而非模板函数，应当在.cpp中定义，它是通用模板函数的特别类型的具体实现，是普通函数的一种
	template<> 
	inline Circle addi<Circle>(const Circle& x, const Circle& y) { 
		return Circle(x.c_radius + y.c_radius);
	}
}


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
 