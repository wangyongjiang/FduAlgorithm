#include <iostream>
#include  "jarynUtils.h"

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2022/4/22 8:09 上午
 * Desc ：归并排序
 */

#define ArrayLen 7

// 辅助数组
int* assistNum = (int*)malloc(ArrayLen * sizeof(int));

/**
 * 两个相邻数组归并
 * @param num
 * @param low 左边数组的开始
 * @param mid 左边数组的结束
 * @param high 右边数组的结束 （因为相邻，mid + 1 为右边数组的开始）
 */
void merge(int *num, int low, int mid, int high){

    // 主要思想：将当前比较范围的子数组复制到辅助数组，指针在辅助数组上移动，排序好的元素放入真正数组

    // i为左边数组的开始下标，j为右边数组的开始下标
    // 辅助队列下标从low开始，方便一一对应
    int i = low, j = mid + 1, realPos = low;
    // 复制
    for (int k = low; k <= high; ++k) {
        assistNum[k] = num[k];
    }
    while (i <= mid && j <= high) {
        // 左边的数组的值小于等于（等于是为了保持稳定性）右边的，那就把左边的当前元素放入辅助数组
        if (assistNum[i] <= assistNum[j]) {
            num[realPos++] = assistNum[i++];
        } else {
            num[realPos++] = assistNum[j++];
        }
    }
    // 以下两个循序是保证比完之后还有剩余有序元素，直接放回数组即可，两个循环只能运行一个
    while (i <= mid) {
        num[realPos++] = assistNum[i++];
    }
    while (j <= high) {
        num[realPos++] = assistNum[j++];
    }
}

void mergeSort(int *num, int low, int high){
    if (low >= high) {
        return;
    }
    // 默认从中间划分
    int mid = (low + high) / 2;
    // 左边
    mergeSort(num, low, mid);
    // 右边
    mergeSort(num, mid + 1, high);
    merge(num, low, mid, high);
}

int main() {
    int num[] = {49, 38, 65, 97, 76, 13, 27};
    mergeSort(num, 0, ArrayLen - 1);
    printArray(num, ArrayLen);
    return 0;
}