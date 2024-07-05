#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define USER_INPUT_MAX_NUM 100
#define USER_INPUT_MIN_NUM 1 ///全部大文字　コーディング規約 MAX_NUMが何の最大値 例ANSWER_ USERINPUT_
#define INPUT_ARRAY_SIZE 256/// 何のARRAYか INPUT 三桁だけでいい

typedef enum {
	Str,
	Val
}RESULT_STR;///何の結果

void printout()///名前　関数化しない方法を考える
{
	printf("%d～%dまでの整数を入力してください。", USER_INPUT_MIN_NUM, USER_INPUT_MAX_NUM);
}

RESULT_STR read_str(char scan_str[INPUT_ARRAY_SIZE]) ///入力されたものに数字以外が含まれていないか確認する
{
	int idx = 0;///idx1の名前
	while (scan_str[idx]) {///関数名とあってない　一つの関数で一つの機能　0の時にFalseになっていいのかNULLの時に抜けるようにする
		if (((scan_str[idx] >= '0') && (scan_str[idx] <= '9')) || (scan_str[idx] == '-'))
			idx++;
		else
			return Str;///列挙型など意味を持たせる
	}
	return Val;
}

//入力した数値を読み取る関数
int read_num(void) ///英語表記　read_numberなど
{ ///無限ループはないほうがいい。breakの後に return
	char scan_str[INPUT_ARRAY_SIZE]; ///入力された数値
	int scan_num = USER_INPUT_MIN_NUM-1;///最小値より下か最大値より上ならなんでもいい scan_numの宣言は一回のほうがいい
	while ((USER_INPUT_MIN_NUM > scan_num) || (scan_num > USER_INPUT_MAX_NUM)) {
		int scan_idx = 0;
		RESULT_STR result_str = Str; ///入力されたものが数字かそれ以外か
		printout();
		while (result_str == Str) {///意味を持たせる whileを重ねないほうがいい
			scanf_s("%s", scan_str, INPUT_ARRAY_SIZE);
			result_str = read_str(scan_str);
			if (result_str == Str) {
				printf("整数以外が含まれています。\n");
				printout();
			}
		}
		scan_num = 0; ///前の数のほうが桁数が大い時のため
		while (scan_str[scan_idx]) { ///入力された数値が－の場合と＋の場合で分ける。min_numを－に変えた時のため
			scan_num *= 10;
			if (scan_str[0] == '-') {
				if (scan_idx == 0) {
					scan_idx++;
				}
				else {
					scan_num -= scan_str[scan_idx++] - '0';
				}
			}
			else {
				scan_num += scan_str[scan_idx++] - '0';
			}
		}
		if ((USER_INPUT_MIN_NUM > scan_num) || (scan_num > USER_INPUT_MAX_NUM)) {///(){}をつける修正の時のため
			printf("%d以上または%d以下の数値です。\n", USER_INPUT_MAX_NUM + 1, USER_INPUT_MIN_NUM - 1);
		}
	}
	return scan_num;
}

int main(void)
{
	srand((unsigned int)time(NULL)); /// 乱数を変更
	int correct_num = USER_INPUT_MIN_NUM + (rand() % (USER_INPUT_MAX_NUM - USER_INPUT_MIN_NUM + 1));
	int count = 0; ///意味のある変数をつける　for分ならok
	int choice_num = USER_INPUT_MIN_NUM - 1;///最小値より下か最大値より上ならなんでもいい
	while (choice_num != correct_num) {   /// 無限ループを使わない
		count++;
		choice_num = read_num();
		if (choice_num < correct_num)
			printf("Small\n");
		else if (choice_num > correct_num)
			printf("Big\n");
		else if (choice_num == correct_num) {///いらない　フラグを立てる　判定を２回しない
			printf("Bingo!\n");
			printf("%d回目で正解しました。", count);
		}
	}
	return 0;
}

/*
int array_size(void)
{
	int max_num_size=0;
	int max_num;
	USER_INPUT_MAX_NUM>0?max_num = USER_INPUT_MAX_NUM:max_num=-USER_INPUT_MAX_NUM;
	while (max_num > 0) {
		max_num_size++;
		max_num /= 10;
	}
	int min_num_size = 0;
	int min_num;
	USER_INPUT_MIN_NUM > 0 ? min_num = USER_INPUT_MIN_NUM : min_num = -USER_INPUT_MIN_NUM;
	while (max_num > 0) {
		min_num_size++;
		min_num /= 10;
	}
	if (max_num_size > min_num_size) {
		return max_num_size+1;
	}
	else {
		return min_num_size;
	}
}
#define INPUT_ARRAY_SIZE array_size()*/