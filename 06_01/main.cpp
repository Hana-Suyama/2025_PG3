#include <stdio.h>
#include <thread>

void print1() {
	printf("thread 1\n");
}

void print2() {
	printf("thread 2\n");
}

void print3() {
	printf("thread 3\n");
}

int main(){

	std::thread th1(print1);
	th1.join();

	std::thread th2(print2);
	th2.join();

	std::thread th3(print3);
	th3.join();


	return 0;
}