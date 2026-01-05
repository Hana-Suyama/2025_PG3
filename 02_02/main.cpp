#include <stdio.h>

int RecursiveWage(int Time, int Wage, int AllWage) {
	if (Time <= 1) {
		return AllWage;
	}
	return RecursiveWage(Time - 1, (Wage * 2) - 50, AllWage + (Wage * 2) - 50);
}

void WageCompare(int Time) {
	printf("労働時間 : %d\n", Time);
	printf("一般的な賃金体系 : %d\n", Time * 1226);
	printf("再帰的な賃金体系 : %d\n", RecursiveWage(Time, 100, 100));
}

int main(){

	WageCompare(8);

	return 0;
}