#include <iostream>
#include  "jarynUtils.h"

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2022/4/20 8:33 上午
 * Desc ：交换排序之快速排序
 */
// 分区，将指定范围内的元素分区，并返回基准元素下标
int partition(int *num, int low, int high){
    // 取前一个元素为基准元素
    int pivot = num[low];
    // 大的元素放右边，小的元素放左边
    while (low < high) {
        // 找出小于基准元素的下标high放到low位置
        while (low < high && num[high] >= pivot) {
            high--;
        }
        num[low] = num[high];
        // 找出大于基准元素的下标low放到high位置
        while (low < high && num[low] <= pivot) {
            low++;
        }
        num[high] = num[low];
    }
    // low == high表示已经分区完毕，当前指向位置就是中间位置，即基准位置
    num[low] = pivot;
    return low;
}

// 快排入口，递归分区（左右分区）
void sort(int *num, int low, int high){
    if (low >= high) {
        return;
    }
    int pivotPos = partition(num, low, high);
    sort(num, low, pivotPos - 1);
    sort(num, pivotPos + 1, high);
}

int main() {
    int num[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int len = 8;
    sort(num, 0, len - 1);
    printArray(num, len);
    return 0;
}