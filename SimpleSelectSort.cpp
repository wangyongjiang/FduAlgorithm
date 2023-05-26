#include <iostream>
#include  "jarynUtils.h"

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2022/4/20 8:33 上午
 * Desc ：简单选择排序
 */
void sort(int *num, int len){
    // 比n-1趟即可，最后一个元素自然有序
    for (int i = 0; i < len - 1; ++i) {
        // 最小的下标默认为当前子序列的首元素(第i个元素)
        int min = i;
        // 每次从第i + 1 到 len - 1 元素的中挑一个最小的放到前面（这里的前面指的是下标i）
        int j;
        for (j = i + 1; j < len; ++j) {
            // 当前元素更小
            if (num[j] < num[min]) {
                min = j;
            }
        }
        // 子序列有更小的元素
        if (min != j) {
            swap(num[min], num[i]);
        }
    }
}

int main() {
    int num[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int len = 8;
    sort(num, len);
    printArray(num, len);
    return 0;
}