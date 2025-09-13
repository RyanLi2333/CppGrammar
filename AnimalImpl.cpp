#include <iostream> 
#include <cmath>
#include "Animal.h" 
#include "Utilities.h"

/// Animal��ʵ��
Animal::Animal() : Animal(.0) {} // ί�й��캯�� 
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

/// Cat��ʵ�� 
Cat::Cat() : Animal(.0) {}
Cat::Cat(const double lifespan) : Animal(lifespan) {} 
Cat::~Cat() {
	std::cout << "The cat have been eradicated" << '\n'; 
}

void Cat::shout() { // è��
	std::cout << "Miao~Miao~~" << '\n'; 
} 

/// Dog��ʵ�� 
Dog::Dog() : Animal(.0) {} 
Dog::Dog(const double lifespan) : Animal(lifespan) {}
Dog::~Dog() {
	std::cout << "The dog have been eradicated" << '\n';
}

void Dog::shout() { // ����
	std::cout << "Woof!!" << '\n'; 
}