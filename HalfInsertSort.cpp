#include <iostream>
#include "jarynUtils.h"

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2022/4/19 8:48 上午
 * Desc ：折半插入排序，与直接插入不同的是这个在遍历子序列时，可以用折半查找
 *        且是找出插入位置后，一次性移动（直接插入是比一次移动一次）
 */

// 折半插入排序，num[0]作为哨兵
void sort(int *num, int len){
    int i,j;
    // 从第二个元素开始
    for (i = 2; i < len; ++i) {
        // 当前元素小，将前面有序子序列中大于当前元素的元素们后移1位
        if (num[i - 1] > num[i]) {
            // 哨兵保存当前元素
            num[0] = num[i];
            // 二分/折半查找
            int low = 1;
            int high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (num[mid] <= num[0]) {
                    // 等于的时候，为了保持稳定性，应该继续看成要插入的位置在右边（大）
                    low = mid + 1;
                } else if (num[mid] > num[0]) {
                    high = mid - 1;
                }
            }
            // 最终low == high + 1，且low就是要插入的位置，所有元素后移
            for (j = i - 1; j >= low; --j) {
                num[j + 1] = num[j];
            }
            // 插入
            num[low] = num[0];
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