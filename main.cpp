#include <iostream>
#include "Utilities.h" 

int main() {
	using namespace BasicFunc;
	greeting(); // Hello 

	char chr[] {'c', 'h', 'i', 'n', 'a'}; 
	size_t len = sizeof(chr) / sizeof(chr[0]);
	printArray(chr, len);

	sortOfBasicArray(chr, len);
	printArray(chr, len); 

	farewell(); // byebye
	return 0; 
} 

