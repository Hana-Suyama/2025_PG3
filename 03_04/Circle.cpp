#include "Circle.h"
#include <stdio.h>

void Circle::Size()
{
	size_ = radius_ * radius_ * 3.14159265358979323846;
}

void Circle::Draw()
{
	printf("円の面積 : %f\n", size_);
}
