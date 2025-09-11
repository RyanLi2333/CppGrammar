#pragma once
#include <istream> 
#include <ostream> 
#include <iostream> 
#include <utility> // ʹ��std::swap 
#include <cstddef> // ʹ��size_t
constexpr double MIN_EPSILON{1e-15}; // ��С����  
constexpr double MAX_EPSILON{1e-9}; // �������

class Circle; // ��ǰ������Circle

namespace func {
	void greeting(); // �ʺ��� 
	void farewell(); // �����
	double getPI(); // ��ȡPI��ֵ 
	bool isEqual(double x, double y); // �������ȽϺ��� 
	bool greaterThan(double x, double y); // �������Ƚ�x>y����true������false 
	bool lessThan(double x, double y); // �������Ƚ�x<y����true�����򷵻�false  
	bool greaterEqual(double x, double y); // ���ڵ��� 
	bool lessEqual(double x, double y); // С�ڵ��� 
	bool isZero(double x); // �ж��Ƿ�Ϊ0 
	// ����ֵ ģ�庯��
	template<typename T> // ģ���.h�ж��� 
	void swapValue(T& x, T& y);
	// չʾֵ
	template<typename T> 
	void printValue(const T& x, const T& y); 
	// ������������������͵�����ʵ�ִ�С�������� 
	template<typename T, size_t N> 
	void sortOfBasicArray(T (&array)[N]);
	// ��ӡ��������������͵�����
	template<typename T, size_t N> 
	void printArray(const T(&array)[N]);
	// ������������������
	template<typename T> 
	T addi(const T& x, const T& y);  
	// ΪCircle entities���Ƶ�ģ���ػ� 
	template<>
	Circle func::addi<Circle>(const Circle& x, const Circle& y); // ����
}

/*
ģ�� 
���ͬ��������ģ��ͺ���Ĭ�ϵ��ú���
����ͨ����ģ������б���������ģ�庯��
����ģ��Ҳ���Է������� 
ֻ����û����ͨ������ģ��ƥ�����ȷʱ������������ú���ģ��

����ģ�岻���Է�����ʽ����ת�����������ֶ���ʽ��ʽ����ת�� 
����ģ����ʽָ�����Ϳ��Է�����ʽ����ת��
*/

// Բ�� 
class Circle { 
	friend Circle func::addi<Circle>(const Circle& x, const Circle& y); // ģ���ػ���Ԫ(����namespace)
	friend double func::getPI(); // ����ȫ�ֺ�������Ԫ��ȫ�ֺ������Է��ʸ���˽�г�Ա 
	friend std::istream& operator>>(std::istream& cin, Circle& circle); // ��Ԫ 
	friend bool operator==(const Circle& c1, const Circle& c2); 
	friend bool operator!=(const Circle& c1, const Circle& c2);
	friend bool operator>(const Circle& c1, const Circle& c2);
	friend bool operator>=(const Circle& c1, const Circle& c2);
	friend bool operator<(const Circle& c1, const Circle& c2);
	friend bool operator<=(const Circle& c1, const Circle& c2);
	static constexpr double C_PI = 3.14159265358979323846; // ���ڶ���������
	mutable double c_radius; // Բ�İ뾶��mutable���ε�����ʹ����const�п��޸�

// ��Ĭ��private 
public:
	Circle(); // �޲ι���
	Circle(double radius); // ���ι��� 
	Circle(const Circle& other); // �������캯��
	~Circle(); // �������� 
	void setRadius(double radius); // ���������ð뾶
	double getRadius() const; // ����Բ�İ뾶 
	double getC() const; // ��Բ���ܳ�
	double getArea() const; // ��Բ�����  
	Circle& addRadiusFrom(Circle& other); // �뾶��ʽ�ӷ� 
	Circle operator+(const Circle& other); // ��������� 
	Circle operator+(const double& other); // �������������Ҳ��������
	Circle& operator=(const Circle& other); // ��ֵ��������� 
	Circle& operator+=(const Circle& other); // �ӷ���ֵ��������� 
	Circle& operator-=(const Circle& other); // ������ֵ��������� 
	Circle& operator++(); // ǰ��������������� 
	Circle operator++(int); // ����������������أ�����������β�int��C++�﷨�淶ǿ�ƹ涨��
	Circle& operator--(); // ǰ���Լ���������� 
	Circle operator--(int); // �����Լ����������  
	void operator()(); // ����������������أ�����python��__call__����
};

std::ostream& operator<<(std::ostream& out, const Circle& circle); // ����������������� 
std::istream& operator>>(std::istream& in, Circle& circle); // ������������� 
bool operator==(const Circle& c1, const Circle& c2); // ���ں�����  
bool operator!=(const Circle& c1, const Circle& c2); // �����ں����� 
bool operator>(const Circle& c1, const Circle& c2); // ���ں����� 
bool operator>=(const Circle& c1, const Circle& c2); // ���ڵ��ں����� 
bool operator<(const Circle& c1, const Circle& c2); // С�ں����� 
bool operator<=(const Circle& c1, const Circle& c2); // С�ڵ��ں����� 


/// ģ�嶨�壺
namespace func {  
	// ����ֵģ�庯�� 
	template<typename T> 
	void swapValue(T& x, T& y) {
		T tmp = x; // ��ʱ����tmp�洢x��ֵ  
		x = y;
		y = tmp;
	}
	// ��ӡ��������ֵab
	template<typename T> 
	void printValue(const T& x, const T& y) {
		std::cout << "left value is " << x << '\n';
		std::cout << "right value is " << y << '\n';
	}
	// ѡ������ʵ��
	template<typename T, size_t N> 
	void sortOfBasicArray(T(&array)[N]) { // ����������������ѡ������ 
		for (size_t i = 0; i + 1 < N; ++i) { // i���ֻ�ܴﵽi - 2����
			size_t min_i = i; // ������Сֵ������ 
			for (size_t j = min_i + 1; j < N; ++j) {
				if (array[j] < array[min_i])
					min_i = j;
			}
			if (min_i != i) // ���min_i��i�Ѿ���һ���ˣ�˵���и�С��
				std::swap(array[i], array[min_i]);
		}
	} 
	// ��ӡ���� 
	template<typename T, size_t N> // �����N�Ǳ�����������size_t����N
	void printArray(const T(&array)[N]) { 
		if constexpr (N == 0) {
			std::cout << "[]"; // ��ӡ������ 
		} else if (N == 1) {
			std::cout << array[0]; // ��ӡ��һ��Ԫ��
		}
		for (size_t i = 1; i < N; ++i) { // ������ӡ����Ԫ�� 
			std::cout << ' ' << array[i];
		}
		std::cout << '\n'; // ����
	}
	// ���ģ�庯��
	template<typename T> 
	T addi(const T& x, const T& y) {
		return x + y; // ֱ�ӷ�����ӽ�� 
	} 
	// ģ���ػ���ģ���ػ���һ����ͨ��������ģ�庯����Ӧ����.cpp�ж��壬����ͨ��ģ�庯�����ر����͵ľ���ʵ�֣�����ͨ������һ��
	template<> 
	inline Circle addi<Circle>(const Circle& x, const Circle& y) { 
		return Circle(x.c_radius + y.c_radius);
	}
}


/*
��̬��Աstatic
��̬��Ա����������������.
��̬��Ա�����������෽����ֻ�ܷ��������ԡ� 

��C++�У���ĳ�Ա��������ĳ�Ա�����ֿ��洢��ֻ����ķǾ�̬��Ա�����洢����Ķ����� 

���ڶ�����������
������һ����������������еĶ��嶼�����������������е��������Ƕ��塣
�����ʹ����ϵͳ�����ڴ棬�����������߱�����ĳ������/�������ڡ�
�����������壬���������������

cpp�����������ģ���У�������ֻ���������޲ι��캯������ǰ���ǣ�
û�ֶ�д�κι��캯���һ�����Ĭ�Ϲ��캯������(�ڼ̳й�ϵ��)
*/
 