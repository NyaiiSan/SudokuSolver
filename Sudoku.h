#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include "main.h"

// 填入所有数字
int fillNums(SquMap **);

// 检查一个数字是否正确
int checkNum(SquMap *, int x, int y, int num);

#endif