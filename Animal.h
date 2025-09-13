#pragma once 
/**
���������Ϊ�˽���Cpp�ļ̳кͶ�̬  
��̬��Ҫ�����������
1. ���ڼ̳й�ϵ 
2. ��������д�����virtual��Ա����(��Ҫʵ�ֶ�̬�ķ���)
*/

/// Animal��
class Animal {
private: // Default 
	double a_lifespan_; 
	
public: 
	Animal(); 
	Animal(const double lifespan);
	virtual ~Animal(); // ��������ʹ������Ե����������������default��ʽ����չ���
	virtual void shout() = 0; // ����������ʱAnimal��Ϊ������(�ӿ�)
	virtual void operator()(); 
	virtual void operator()(const double new_lifespan); 
};

/// Cat��
class Cat : public Animal { // ��public�ķ�ʽ�̳�Animal 
public:
	Cat(); 
	Cat(const double lifespan);
	void shout() override; 
	~Cat();
};

/// Dog��
class Dog : public Animal { // ��public�ķ�ʽ�̳�Animal 
public: 
	Dog(); 
	Dog(const double lifespan);
	~Dog();
	void shout() override;
}; 

class CatDog : virtual public Cat, virtual public Dog {};

/**
�ڼ̳��У���������зǾ�̬��Ա�������ᱻ������̳У�
�������Զ�ӵ�л�������г�Ա(�����ͺ���)�����ҿ����ڴ˻���������Լ����¹��ܡ�
����public��protected�ĳ�Ա����ֱ�ӷ��ʺ�ʹ�ã�private���У���private��Ա���ڴ��д��ڣ����Լ�ӷ��ʡ�

�̳з�ʽ��public protected private����ʾ���̳е����ݵ����Ȩ�����ƣ�public��á�

�̳й��̣�
1. �����ڴ�ռ� 
2. ���û��๹�캯��(�����Ƿ�ʵ���������๹�죬������ִ�л��๹�죬����ͬ��)
3. ���������๹�캯��(�����) 
4. ������������Ĵ���

����ʱ��
1. ������������������(�����) 
2. ���û����������� 
3. �ͷ��ڴ�ռ� 

�̳к��������Ĺ������������⣺
���캯�������ֶ���д(���Ҫ�ô��ε�)����������һ�㲻��д����������new

����virtual�ؼ��֣�����virtual base ptr(vbptr)��virtual function ptr(vfptr)���ࡣ
- vbptr������μ̳���������Ա�������������⡣
- vfptr�������ʱ��̬���⡣

��̳�
vbptrʹ���м������಻��ֱ��Ƕ������࣬����ͨ��vbptr�洢��ƫ��������̬�������������������������е��ڴ��ַ���Ӷ�ȷ�������̳�����ֻ����һ�������ʵ��base_addr + *vbptr = �������Ա������ַ
�ڶ�����̳��У�һ��������ܰ������vbptr��ÿ����̳�·����Ӧһ�����������ʵ����ֻ��һ�ݡ�

�麯�����̬
ÿ���������麯������(��̳����麯������)�ڱ���ʱ����һ��Ψһ���麯����(vtable)����������ж���ͨ��vptr�������ű�ʵ�ֶ�̬���á� 
ÿ�������麯���Ļ����Ӷ����Ӧһ��vfptr��һ��vtable�� 

һ��������������ڴ��ж�Ӧһ��ʵ�����壬�������Ա��߼����Ϊ��������Ӷ��������߼��������ʵ����

��һ���������˴��麯�������������࣬��������ʵ�������������д������麯������Ҳ�ǳ�����
�ڳ�������һ��Ҫд������������������Ķ��������޷��ͷš� 

virtual function = 0����������vtable����һ�������Ĳ�λ����ֻ���麯���Ų���vtable
*/