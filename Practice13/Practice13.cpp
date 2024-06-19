#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//入力した数値を読み取る関数
int Bango(void)
{
	while (1) {
		int b;
		printf("1～100までの数値を入力してください。");
		scanf_s("%d", &b);
		if (!((0 < b) && (b < 101)))
			printf("0以下または101以上の数値です。\n");
		else
			return b;
	}
}

int main(void)
{
	srand((unsigned int)time(NULL));///乱数を変更
	int Bingo = (rand() % 100 + 1);
	int i = 0;
	while (1) {   ///breakしない限り続ける
		i++;
		int num = Bango();
		if (num < Bingo)
			printf("Small\n");
		else if (num > Bingo)
			printf("Big\n");
		else if (num == Bingo) {
			printf("Bingo!\n");
			printf("%d回目で正解しました。", i);
			break;
		}
	}
	return 0;
}