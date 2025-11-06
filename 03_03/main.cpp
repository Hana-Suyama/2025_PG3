#include <stdio.h>
#include "Planet.h"
#include "Sun.h"
#include "Earth.h"

int main(){

	Planet* planets[2];

	planets[0] = new Sun();
	planets[1] = new Earth();

	planets[0]->print();
	planets[1]->print();

	delete planets[0];
	delete planets[1];

	return 0;
}