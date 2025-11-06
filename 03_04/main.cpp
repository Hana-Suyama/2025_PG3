#include <stdio.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main(){

	IShape* shapes[2];

	shapes[0] = new Circle;
	shapes[1] = new Rectangle;

	shapes[0]->Size();
	shapes[1]->Size();

	shapes[0]->Draw();
	shapes[1]->Draw();

	delete shapes[0];
	delete shapes[1];

	return 0;
}