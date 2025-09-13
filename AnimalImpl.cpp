#include <iostream> 
#include <cmath>
#include "Animal.h" 
#include "Utilities.h"

/// Animal类实现
Animal::Animal() : Animal(.0) {} // 委托构造函数 
Animal::Animal(const double lifespan) : a_lifespan_(func::lessThan(lifespan, .0) ? .0 : lifespan) { 
	std::cout << "Created an animal successfully" << '\n';
}

void Animal::operator()() {
	std::cout << "Lifespan is " << this->a_lifespan_ << '\n'; 
}

void Animal::operator()(const double new_lifespan) {
	if (!std::isnan(new_lifespan) && func::greaterEqual(new_lifespan, .0)) {
		this->a_lifespan_ = new_lifespan; 
		std::cout << "Modified successfully" << '\n';
	}
	else {
		std::cout << "Failed to modify" << '\n';
	}
} 

Animal::~Animal() = default;

/// Cat类实现 
Cat::Cat() : Animal(.0) {}
Cat::Cat(const double lifespan) : Animal(lifespan) {} 
Cat::~Cat() {
	std::cout << "The cat have been eradicated" << '\n'; 
}

void Cat::shout() { // 猫叫
	std::cout << "Miao~Miao~~" << '\n'; 
} 

/// Dog类实现 
Dog::Dog() : Animal(.0) {} 
Dog::Dog(const double lifespan) : Animal(lifespan) {}
Dog::~Dog() {
	std::cout << "The dog have been eradicated" << '\n';
}

void Dog::shout() { // 狗叫
	std::cout << "Woof!!" << '\n'; 
}