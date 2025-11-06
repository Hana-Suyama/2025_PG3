#include <stdio.h>
#include "MinClass.h"
#include <iostream>
#include <string>

int main(){

	int num1 = 5;
	float num2 = 3.6f;
	double num3 = 6.2;

	MinClass<int, float> class1(num1, num2);
	MinClass<int, double> class2(num1, num3);
	MinClass<float, int> class3(num2, num1);
	MinClass<float, double> class4(num2, num3);
	MinClass<double, int> class5(num3, num1);
	MinClass<double, float> class6(num3, num2);

	std::cout << std::to_string(class1.Min()) + "\n" << std::endl;
	std::cout << std::to_string(class2.Min()) + "\n" << std::endl;
	std::cout << std::to_string(class3.Min()) + "\n" << std::endl;
	std::cout << std::to_string(class4.Min()) + "\n" << std::endl;
	std::cout << std::to_string(class5.Min()) + "\n" << std::endl;
	std::cout << std::to_string(class6.Min()) + "\n" << std::endl;

	return 0;
}