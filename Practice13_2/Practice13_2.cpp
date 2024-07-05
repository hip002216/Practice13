#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define USER_INPUT_MAX_NUM 100
#define USER_INPUT_MIN_NUM 1 ///全部大文字　コーディング規約 MAX_NUMが何の最大値 例ANSWER_ USERINPUT_
#define INPUT_ARRAY_SIZE 4///ARRAYは使わないほうがいい　桁数

int Read_num(void)///_はなしコーディング規約　動詞とそれ以降は_で区切ってok
{
	int scan_num;
	bool is_available = false;///入力が成功したらtrue
	while (is_available == false) {
		int str_idx = 0;///
		char scan_str[INPUT_ARRAY_SIZE];
		printf("%dから%dまでの整数を入力してください。", USER_INPUT_MIN_NUM, USER_INPUT_MAX_NUM);
		scanf_s("%s", &scan_str, INPUT_ARRAY_SIZE);///最初が\nの場合どうなるのか
		scanf_s("%*[^\n]");///入力バッファをクリア　\nに到達するまでバッファを読み込む　*がついているのは読み込んでも捨てる
		bool is_int = true;///文字列が整数だけならtrue
		bool is_minus;///入力文字が－の場合ならtrue
		if (scan_str[0] == '-')///{}をぬかさない
			is_minus = true;
		else
			is_minus = false;
		if (scan_str[0] == NULL) {///INPUT_ARRAY_SIZE以上の文字数を書き込まれるとscan_strにはなにも書き込まれなくなるため
			printf("指定文字数を超えています。\n");
			continue;
		}
		while (scan_str[str_idx] != NULL) {///機能単位に関数に分ける。フラグが多い
			if (((scan_str[str_idx] >= '0') && (scan_str[str_idx] <= '9')) || ((is_minus == true) && (str_idx == 0)))
				str_idx++;
			else {
				printf("整数以外が含まれています。\n");
				is_int = false;
				break;
			}
		}
		if (is_int == false) {
			continue;
		}
		int scan_idx = 0;
		scan_num = 0;
		while (scan_str[scan_idx] != NULL) {///関数化したほうがいい
			scan_num *= 10;
			if ((is_minus == true) && (scan_idx == 0)) {
				scan_idx++;
			}
			else {
				scan_num += scan_str[scan_idx++] - '0';
			}
		}
		if (is_minus == true) {
			scan_num = -scan_num;
		}
		if ((USER_INPUT_MIN_NUM > scan_num) || (scan_num > USER_INPUT_MAX_NUM)) {///(){}をつける修正の時のため
			printf("%d以上または%d以下の数値です。\n", USER_INPUT_MAX_NUM + 1, USER_INPUT_MIN_NUM - 1);
			continue;
		}
		is_available = true;
	}
	return scan_num;
}

int main(void)
{
	srand((unsigned int)time(NULL)); /// 乱数を変更
	int correct_num = USER_INPUT_MIN_NUM + (rand() % (USER_INPUT_MAX_NUM - USER_INPUT_MIN_NUM + 1));
	int count = 0;
	int choice_num = 0;
	bool is_finish = false;
	while (is_finish == false) {
		count++;
		choice_num = Read_num();
		if (choice_num < correct_num)
			printf("Small\n");
		else if (choice_num > correct_num)
			printf("Big\n");
		else {
			is_finish = true;
			printf("Bingo!\n");///while分内のほうがわかりやすい
			printf("%d回目で正解しました。", count);
		}
		}
	return 0;
}