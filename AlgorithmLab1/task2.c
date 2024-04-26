#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "task2.h"

int task2() {
	const int min_bits = 1;//���ɸ���������λ��Ӧ��Ϊ1

	//���������λ��
	int n;
	scanf("%d", &n);

	//�������
	if (n < min_bits) {
		printf("Invalid input!");
	}

	//������������
	const int length = pow(2, n);

	//���䳤��Ϊ2^n������洢������
	const int* gray = malloc(length * sizeof(int));
	memset(gray, 0, length * sizeof(int));
	//��ʼ�����λ
	for (int i = 0; i < length / 2; i++) {
		set0(&gray[i], n);
	}
	for (int i = length / 2; i < length; i++) {
		set1(&gray[i], n);
	}

	//����β��
	gray_tail(gray, n);

	//���
	for (int i = 0; i < length; i++) {
		print_bin(gray[i], n);
		printf("\n");
	}
	return 0;
}

void gray_tail(int* gray, int n) {
	//ȷ��nλ���������
	const int range = pow(2, n);

	if (range < 4) {
		//range<4��ʱ���������
		return;
	}

	//��ֳ��ĸ�������0110
	for (int i = 0; i < range / 4; i++) {
		set0(&gray[i], n - 1);
	}
	for (int i = range / 4; i < range / 2; i++) {
		set1(&gray[i], n - 1);
	}

	//��ǰ��ݹ�
	gray_tail(gray, n - 1);

	for (int i = range / 2; i < 3 * range / 4; i++) {
		set1(&gray[i], n - 1);
	}
	for (int i = 3 * range / 4; i < range; i++) {
		set0(&gray[i], n - 1);
	}

	//�����ݹ�
	gray_tail(&gray[range / 2], n - 1);
}

void set1(int* num, int n) {
	//�� ���д�λΪ1 ���
	*num |= 1 << n - 1;
}

void set0(int* num, int n) {
	//�� ���д�λΪ1�ķ� ����
	*(num) &= ~(1 << n - 1);
}

int pow(int num, int exp) {
	int result = 1;

	//reuslt��n��exp���
	for (int i = 0; i < exp; i++) {
		result *= num;
	}

	return result;
}

void print_bin(int num, int n) {
	for (int i = n; i > 0; i--) {
		//����ָ��λ�Ƿ�Ϊ1
		if ((num & (1 << i - 1)) != 0) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
}