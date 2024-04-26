#pragma once
#include<stdio.h>
#include<stdlib.h>

//主函数
int task2();

//生成格雷码的n位的下一位尾巴
void gray_tail(int* gray, int n);

//设置某一位
void set1(int* num, int n);
void set0(int* num, int n);

//幂
int pow(int num, int exp);

//二进制输出
void print_bin(int num,int n);
