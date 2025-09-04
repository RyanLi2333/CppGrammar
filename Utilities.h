#ifndef UTILITIES_H
#define UTILITIES_H 
#include <istream> 
#include <ostream> 
#include <iostream>
constexpr double MIN_EPSILON{1e-15}; // ��С����  
constexpr double MAX_EPSILON{1e-9}; // �������

namespace BasicFunc {
	void greeting(); // �ʺ��� 
	void farewell(); // �����
	double getPI(); // ��ȡPI��ֵ 
	bool isEqual(double x, double y); // �������ȽϺ��� 
	bool greaterThan(double x, double y); // �������Ƚ�x>y����true������false 
	bool lessThan(double x, double y); // �������Ƚ�x<y����true�����򷵻�false  
	bool greaterEqual(double x, double y); // ���ڵ��� 
	bool lessEqual(double x, double y); // С�ڵ��� 
	bool isZero(double x); // �ж��Ƿ�Ϊ0 
	template<typename T> // ģ���.h�ж���
	void swapValue(T& x, T& y) { // ����ֵ 
		T tmp = x; // ��ʱ����tmp�洢x��ֵ  
		x = y;
		y = tmp;
	}
	template<typename T> // չʾֵ
	void printValue(const T& x, const T& y) {
		std::cout << "left value is " << x << '\n'; 
		std::cout << "right value is " << y << '\n';
	}
	template<typename T> // ѡ������O(n^2)
	void sortOfBasicArray(T* array, size_t length) {
		for (size_t ship = 0, minNum = 0; ship < length - 1; ++ship) { // ���׸����ݸ���ship�α꣬��ʾ�����±�
			minNum = ship; // ����minNum
			for (size_t tag = ship + 1; tag <= length - 1; tag++) { // ship֮��������±� 
				if (array[tag] < array[minNum]) { // ����������minNumС������ship���� 
					minNum = tag; // �ѵ�ǰtag��ֵ����minNum���
				}
			}
			if (minNum != ship) { // ������
				T tmp = array[ship]; 
				array[ship] = array[minNum]; 
				array[minNum] = tmp;
			}
		}
	} // ������������������͵�����ʵ�ִ�С�������� 
	template<typename T> 
	void printArray(T* array, size_t length) {
		for (register size_t i = 0; i < length; ++i) {
			std::cout << array[i]; 
			if (i < length - 1) std::cout << ' '; 
		}
		std::cout << '\n';
	}
}

// Բ�� 
class Circle { 
	friend double BasicFunc::getPI(); // ����ȫ�ֺ�������Ԫ��ȫ�ֺ������Է��ʸ���˽�г�Ա 
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

#endif 