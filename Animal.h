#pragma once 
/**
这个部分是为了介绍Cpp的继承和多态  
多态需要满足的条件：
1. 存在继承关系 
2. 派生类重写基类的virtual成员函数(需要实现多态的方法)
*/

/// Animal类
class Animal {
private: // Default 
	double a_lifespan_; 
	
public: 
	Animal(); 
	Animal(const double lifespan);
	virtual ~Animal(); // 虚析构，使基类可以调用派生类的析构。default显式申请空构造
	virtual void shout() = 0; // 纯虚数，此时Animal变为抽象类(接口)
	virtual void operator()(); 
	virtual void operator()(const double new_lifespan); 
};

/// Cat类
class Cat : public Animal { // 以public的方式继承Animal 
public:
	Cat(); 
	Cat(const double lifespan);
	void shout() override; 
	~Cat();
};

/// Dog类
class Dog : public Animal { // 以public的方式继承Animal 
public: 
	Dog(); 
	Dog(const double lifespan);
	~Dog();
	void shout() override;
}; 

class CatDog : virtual public Cat, virtual public Dog {};

/**
在继承中，基类的所有非静态成员变量都会被派生类继承；
派生类自动拥有基类的所有成员(变量和函数)，并且可以在此基础上添加自己的新功能。
其中public和protected的成员可以直接访问和使用；private不行，但private成员在内存中存在，可以间接访问。

继承方式：public protected private。表示所继承的内容的最高权限限制，public最常用。

继承过程：
1. 分配内存空间 
2. 调用基类构造函数(无论是否实现了派生类构造，都必须执行基类构造，析构同理)
3. 调用派生类构造函数(如果有) 
4. 完成派生类对象的创建

销毁时：
1. 调用派生类析构函数(如果有) 
2. 调用基类析构函数 
3. 释放内存空间 

继承后的派生类的构造与析构问题：
构造函数必须手动重写(如果要用带参的)，析构函数一般不用写，除非用了new

关于virtual关键字：包含virtual base ptr(vbptr)和virtual function ptr(vfptr)两类。
- vbptr解决菱形继承中虚基类成员变量的冗余问题。
- vfptr解决运行时多态问题。

虚继承
vbptr使得中间派生类不再直接嵌入虚基类，而是通过vbptr存储的偏移量，动态计算虚基类在最终派生类对象中的内存地址，从而确保整个继承链中只存在一份虚基类实例base_addr + *vbptr = 主基类成员变量地址
在多重虚继承中，一个对象可能包含多个vbptr，每个虚继承路径对应一个，但虚基类实例仍只有一份。

虚函数与多态
每个定义了虚函数的类(或继承了虚函数的类)在编译时生成一张唯一的虚函数表(vtable)，该类的所有对象通过vptr共享这张表实现多态调用。 
每个带有虚函数的基类子对象对应一个vfptr和一张vtable。 

一个派生类对象，在内存中对应一个实例整体，但它可以被逻辑拆解为多个基类子对象，属于逻辑概念而非实体概念。

当一个类中有了纯虚函数，则化作抽象类，抽象类无实例，子类必须重写基类的虚函数否则也是抽象类
在抽象类中一定要写虚析构，避免派生类的堆区数据无法释放。 

virtual function = 0的作用是在vtable中留一个待填充的槽位，故只有虚函数才参与vtable
*/