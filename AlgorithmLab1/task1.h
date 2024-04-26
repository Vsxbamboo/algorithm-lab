#pragma once
#include<stdio.h>
#include<stdlib.h>

//获取中位数
double get_mid(int x[], int x_low, int x_high);

//取左段
void move_left(int* low, int* high);

//取右端
void move_right(int* low, int* high);

//主函数
int task1();
