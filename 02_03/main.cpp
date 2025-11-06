#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	Sleep(delayMs);
	fn(roll, userGuess);
}

void ShowResult(int roll, int userGuess) {
	int result = roll % 2;

	printf("出目は%dでした。\n", roll);
	if (result == userGuess) {
		printf("正解\n");
	} else {
		printf("不正解\n");
	}
}

int main(){

	srand((unsigned)time(NULL));

	printf("丁(0)か半(1)かを入力してください\n");

	int in;

	scanf_s("%d/n", &in);

	if (in) {
		printf("予想は半です\n");
	} else {
		printf("予想は丁です\n");
	}

	int dice = (rand() % 6) + 1;

	void (*pfunc)(int, int);
	pfunc = ShowResult;
	DelayReveal(pfunc, 3000, dice, in);

	return 0;
}
