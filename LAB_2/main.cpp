#include <iostream>
#include "calculator.h"

int main() {
    Calculator calculator;
    int res1 = calculator.Add(1.0, 1.0);
    int res2 = calculator.Sub(1.0, 1.0);    
	std::cout << std::to_string(res1) << std::endl; //2.5
	std::cout << std::to_string(res2) << std::endl; //1.5
	return 0;
}

