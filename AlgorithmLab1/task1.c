#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "task1.h"

double get_mid(int x[], int x_low, int x_high) {
    if ((x_high - x_low + 1) % 2 == 1) {//������
        return x[(x_high + x_low) / 2];//�����м����
    }
    else {//ż����
        return (x[(x_high + x_low - 1) / 2] + x[(x_high + x_low + 1) / 2]) / 2.0;//�����м���������ƽ��ֵ
    }
}

void move_left(int* low, int* high) {
    if ((*high - *low + 1) % 2 == 1) {//������
        *high = (*low + *high) / 2;
    }
    else {//ż���������Ҷ�ȡһ�������ⶪʧ��λ��
        *high = (*low + *high + 1) / 2;
    }
}

void move_right(int* low, int* high) {
    if ((*high - *low) % 2 == 0) {//������
        *low = (*low + *high) / 2;
    }
    else {//ż�����������ȡһ�������ⶪʧ��λ��
        *low = (*low + *high - 1) / 2;
    }
}

int task1() {
    //���������С
    int n;
    scanf("%d", &n);

    //������������
    int *x=malloc(n*sizeof(int));
    int *y=malloc(n*sizeof(int));

    //������ֹ���
    int x_low = 0, x_high = n - 1, y_low = 0, y_high = n - 1;

    //��������
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    //�ŵ����ڵ�������Ԫ�ػ�����λ�����
    while (
        get_mid(x, x_low, x_high) != get_mid(y, y_low, y_high)
        && (x_high - x_low + 1 > 2 || y_high - y_low + 1 > 2)
        ) {
        //�Ƚ���λ��ѡ��
        if (get_mid(x, x_low, x_high) < get_mid(y, y_low, y_high)) {
            move_right(&x_low, &x_high);
            move_left(&y_low, &y_high);
        }
        else {
            move_left(&x_low, &x_high);
            move_right(&y_low, &y_high);
        }
    }
    //���ʣ������һ���������������
    //�����λ����ȣ����߳��Ƚ�Ϊ1��ֱ���������һ������Ϊ1�Ļ�����һ������һ��Ϊ1������֤������Ϊ�����ʼ���ȴ��ڵ���2������������Ϊ1
    if (get_mid(x, x_low, x_high) == get_mid(y, y_low, y_high) || x_low == x_high) {
        //ֱ�����
        printf("%g", (get_mid(x, x_low, x_high) + get_mid(y, y_low, y_high)) / 2);
    }
    else {
        //�ĸ���������������λ��
        int sort[4]={ x[x_low],x[x_high],y[y_low],y[y_high] };
        //ð��
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (sort[i] > sort[j]) {
                    int temp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = temp;
                }
            }
        }
        printf("%g", get_mid(sort, 1, 2));
    }

    return 0;
}
