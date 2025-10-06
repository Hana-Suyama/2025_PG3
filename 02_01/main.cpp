#include <stdio.h>

template <typename Type>

Type Min(Type a, Type b) {
	if (a < b) {
		return static_cast<Type>(a);
	}
	return static_cast<Type>(b);
}

int main(){

	printf("%d\n", Min<int>(3, 10));
	printf("%f\n", Min<float>(6.0f, 2.0f));
	printf("%f\n", Min<double>(3.58, 5.26));

	return 0;
}