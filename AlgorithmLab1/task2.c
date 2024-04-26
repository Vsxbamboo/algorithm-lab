#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "task2.h"

int task2() {
	const int min_bits = 1;//生成格雷码的最低位数应该为1

	//输入格雷码位数
	int n;
	scanf("%d", &n);

	//输入检验
	if (n < min_bits) {
		printf("Invalid input!");
	}

	//计算格雷码个数
	const int length = pow(2, n);

	//分配长度为2^n的数组存储格雷码
	const int* gray = malloc(length * sizeof(int));
	memset(gray, 0, length * sizeof(int));
	//初始化最高位
	for (int i = 0; i < length / 2; i++) {
		set0(&gray[i], n);
	}
	for (int i = length / 2; i < length; i++) {
		set1(&gray[i], n);
	}

	//增加尾巴
	gray_tail(gray, n);

	//输出
	for (int i = 0; i < length; i++) {
		print_bin(gray[i], n);
		printf("\n");
	}
	return 0;
}

void gray_tail(int* gray, int n) {
	//确定n位格雷码个数
	const int range = pow(2, n);

	if (range < 4) {
		//range<4的时候结束生成
		return;
	}

	//拆分成四个部分填0110
	for (int i = 0; i < range / 4; i++) {
		set0(&gray[i], n - 1);
	}
	for (int i = range / 4; i < range / 2; i++) {
		set1(&gray[i], n - 1);
	}

	//将前半递归
	gray_tail(gray, n - 1);

	for (int i = range / 2; i < 3 * range / 4; i++) {
		set1(&gray[i], n - 1);
	}
	for (int i = 3 * range / 4; i < range; i++) {
		set0(&gray[i], n - 1);
	}

	//将后半递归
	gray_tail(&gray[range / 2], n - 1);
}

void set1(int* num, int n) {
	//与 仅有此位为1 相或
	*num |= 1 << n - 1;
}

void set0(int* num, int n) {
	//与 仅有此位为1的反 相与
	*(num) &= ~(1 << n - 1);
}

int pow(int num, int exp) {
	int result = 1;

	//reuslt与n个exp相乘
	for (int i = 0; i < exp; i++) {
		result *= num;
	}

	return result;
}

void print_bin(int num, int n) {
	for (int i = n; i > 0; i--) {
		//测试指定位是否为1
		if ((num & (1 << i - 1)) != 0) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
}