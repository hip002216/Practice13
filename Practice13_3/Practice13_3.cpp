#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define USER_INPUT_MAX_NUM 100
#define USER_INPUT_MIN_NUM 1 ///全部大文字　コーディング規約 MAX_NUMが何の最大値 例ANSWER_ USERINPUT_
#define DIGITS_NUM 4///ARRAYは使わないほうがいい　桁数 なんのDIGITS　結合度を弱く作る

bool IsInt(char scan_str[DIGITS_NUM]) {///整数型か判別　変数名　独立性　MVC　VとCを分ける
	bool is_int = true;
	int str_idx = 0;
	while (scan_str[str_idx] != NULL) {///機能単位に関数に分ける。フラグが多い
		if (((scan_str[str_idx] >= '0') && (scan_str[str_idx] <= '9')) || ((scan_str[0] == '-') && (str_idx == 0))) {
			str_idx++;
		}
		else {
			printf("整数以外が含まれています。\n");
			is_int = false;
			break;
		}
	}
	return is_int;
}

int StrIntChange(char scan_str[DIGITS_NUM]) {///strtoint
	int scan_idx=0;
	int scan_num = 0;
	while (scan_str[scan_idx] != NULL) {
		scan_num *= 10;
		if ((scan_str[0] == '-') && (scan_idx == 0)) {///whileの外　フラグを立てたほうがいい
			scan_idx++;
		}
		else {
			scan_num += scan_str[scan_idx++] - '0';
		}
	}
	if (scan_str[0] == '-') {
		scan_num = -scan_num;
	}
	return scan_num;
}

int ReadNum(void)///_はなしコーディング規約　動詞とそれ以降は_で区切ってok
{
	int scan_num = 0;
	bool is_available = false;///入力が成功したらtrue
	while (is_available == false) {
		int str_idx = 0;///
		char scan_str[DIGITS_NUM];
		printf("%dから%dまでの整数を入力してください。", USER_INPUT_MIN_NUM, USER_INPUT_MAX_NUM);
		scanf_s("%s", &scan_str, DIGITS_NUM);///scanfは\nとスペースを区切りとするため最初に\nとスペースがあっても読み込まれない
		scanf_s("%*[^\n]");///入力バッファをクリア　\nに到達するまでバッファを読み込む　*がついているのは読み込んでも捨てる
		if (scan_str[0] == NULL) {///INPUT_ARRAY_SIZE以上の文字数を書き込まれるとscan_strにはなにも書き込まれなくなるため　コード上に制約は書く
			printf("指定文字数を超えています。\n");
			continue;
		}
		if (IsInt(scan_str) == false) {///読み取り失敗
			continue;
		}
		scan_num = StrIntChange(scan_str);
		if ((USER_INPUT_MIN_NUM > scan_num) || (scan_num > USER_INPUT_MAX_NUM)) {///(){}をつける修正の時のため
			printf("%d以上または%d以下の数値です。\n", USER_INPUT_MAX_NUM + 1, USER_INPUT_MIN_NUM - 1);///直す
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
		choice_num = ReadNum();
		if (choice_num < correct_num) {
			printf("Small\n");
		}
		else if (choice_num > correct_num) {
			printf("Big\n");
		}
		else {
			is_finish = true;
			printf("Bingo!\n");///while分内のほうがわかりやすい
			printf("%d回目で正解しました。", count);
		}
	}
	return 0;
}