#include "Rectangle.h"
#include <stdio.h>

void Rectangle::Size()
{
	size_ = width_ * height_;
}

void Rectangle::Draw()
{
	printf("矩形の面積 : %f\n", size_);
}
