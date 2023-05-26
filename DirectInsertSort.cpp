#include <iostream>
#include "jarynUtils.h"

/**
 * Author ：Jaryn
 * Time ：2022/4/19 8:18 上午
 * Desc ：直接插入排序
 */


// 直接插入排序，num[0]作为哨兵
void sort(int *num, int len){
    int i, j;
    // 从第二个元素开始
    for (i = 2; i < len; ++i) {
        // 当前元素小，将前面有序子序列中大于当前元素的元素们后移1位
        if (num[i - 1] > num[i]) {
            // 哨兵保存当前元素
            num[0] = num[i];
            // 注：条件加了等于，即>=，稳定性：不稳定
            for (j = i - 1; num[j] > num[0]; --j) {
                // j 指向 当前元素的前一个元素
                num[j + 1] = num[j];
            }
            num[j + 1] = num[0];
            printArrayWithGuard(num, len);
        }
    }
}

int main() {
    int num[] = {9999, 49, 38, 65, 97, 76, 13, 27, 49};
    int len = 9;
    sort(num, len);
    printArrayWithGuard(num, len);
    return 0;
}