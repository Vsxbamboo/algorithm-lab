#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "task1.h"

double get_mid(int x[], int x_low, int x_high) {
    if ((x_high - x_low + 1) % 2 == 1) {//奇数个
        return x[(x_high + x_low) / 2];//返回中间的数
    }
    else {//偶数个
        return (x[(x_high + x_low - 1) / 2] + x[(x_high + x_low + 1) / 2]) / 2.0;//返回中间两个数的平均值
    }
}

void move_left(int* low, int* high) {
    if ((*high - *low + 1) % 2 == 1) {//奇数个
        *high = (*low + *high) / 2;
    }
    else {//偶数个，向右多取一个，避免丢失中位数
        *high = (*low + *high + 1) / 2;
    }
}

void move_right(int* low, int* high) {
    if ((*high - *low) % 2 == 0) {//奇数个
        *low = (*low + *high) / 2;
    }
    else {//偶数个，向左多取一个，避免丢失中位数
        *low = (*low + *high - 1) / 2;
    }
}

int task1() {
    //输入数组大小
    int n;
    scanf("%d", &n);

    //创建两个数组
    int *x=malloc(n*sizeof(int));
    int *y=malloc(n*sizeof(int));

    //段落起止标记
    int x_low = 0, x_high = n - 1, y_low = 0, y_high = n - 1;

    //输入数组
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    //排到少于等于两个元素或者中位数相等
    while (
        get_mid(x, x_low, x_high) != get_mid(y, y_low, y_high)
        && (x_high - x_low + 1 > 2 || y_high - y_low + 1 > 2)
        ) {
        //比较中位数选段
        if (get_mid(x, x_low, x_high) < get_mid(y, y_low, y_high)) {
            move_right(&x_low, &x_high);
            move_left(&y_low, &y_high);
        }
        else {
            move_left(&x_low, &x_high);
            move_right(&y_low, &y_high);
        }
    }
    //针对剩两个或一个的情况分类讨论
    //如果中位数相等，或者长度仅为1，直接输出；有一个长度为1的话，另一个长度一定为1，可以证明，因为如果初始长度大于等于2，不可能缩减为1
    if (get_mid(x, x_low, x_high) == get_mid(y, y_low, y_high) || x_low == x_high) {
        //直接输出
        printf("%g", (get_mid(x, x_low, x_high) + get_mid(y, y_low, y_high)) / 2);
    }
    else {
        //四个数字排序后输出中位数
        int sort[4]={ x[x_low],x[x_high],y[y_low],y[y_high] };
        //冒泡
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
