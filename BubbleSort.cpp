#include <iostream>
#include <algorithm>
#include  "jarynUtils.h"

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2022/4/20 8:33 上午
 * Desc ：交换排序之冒泡排序
 */
//void swap(int &a, int &b){
//    int temp = a;
//    a = b;
//    b = temp;
//}

void sort(int *num, int len){
    int i, j;
    bool flag = false;

    // 把小的元素往前冒，到len - 1足以，因为最后一次排序 前len - 1项必定是有序且小于第len项
    for (i = 0; i < len - 1; i++) {
        // 第i项已经有序
        for (j = len - 1; j > i; j--) {
            if (num[j] < num[j - 1]) {
                swap(num[j], num[j-1]);
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }

}

int main() {
    int num[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int len = 8;
    sort(num, num + len);
//    sort(num, len);
    printArrayWithGuard(num, len);
    return 0;
}