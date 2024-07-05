#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define USER_INPUT_MAX_NUM 100
#define USER_INPUT_MIN_NUM 1 ///全部大文字　コーディング規約 MAX_NUMが何の最大値 例ANSWER_ USERINPUT_
#define DIGITS_NUM 4///ARRAYは使わないほうがいい　桁数

int main(void)
{
	char scan_str;
	printf("%dから%dまでの整数を入力してください。", USER_INPUT_MIN_NUM, USER_INPUT_MAX_NUM);
	///scanf_s("%s", &scan_str, DIGITS_NUM);
	scanf_s("%[aaa]",&scan_str,DIGITS_NUM);
	printf("%s", scan_str);
	return 0;
}