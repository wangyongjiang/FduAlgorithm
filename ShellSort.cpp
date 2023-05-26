#include <iostream>
#include "jarynUtils.h"

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2022/4/19 9:44 上午
 * Desc ：希尔排序，基本思想：将元素序列打造成基本有序（步长分组）后使用直接插入排序
 */

// 课本
void sort(int *num, int len) {
    int i, j, d;
    for (d = len / 2; d >= 1; d /= 2) {

        // 咸鱼要求的实现方式：一次性处理一个组内的所有，而不是一个一个元素轮流处理（课本）
        // k为组的序号，由步长决定，最多有d个组，例：步长为2，最多有2个组
        for (int k = 1; k <= d; ++k) {

            // 直接插入排序，注意步长
            for (i = k + d; i < len; i += d) {
                if (num[i] < num[i - d]) {
                    num[0] = num[i];
                    for (j = i - d; j > 0 && num[j] > num[0]; j -= d) {
                        num[j + d] = num[j];
                    }
                    num[j + d] = num[0];
                }
            }
        }
        printArrayWithGuard(num, len);
    }
}

// 课本
//void sort(int *num, int len){
//    int i, j, d;
//    for (d = len / 2; d >= 1; d /= 2) {
//        // 直接插入排序，注意步长
//        for (i = d + 1; i < len; i++) {
//            if (num[i] < num[i - d]) {
//                num[0] = num[i];
//                for (j = i - d; j > 0 && num[j] > num[0]; j -= d) {
//                    num[j + d] = num[j];
//                }
//                num[j + d] = num[0];
//            }
//        }
//        printArrayWithGuard(num, len);
//    }
//}

int main() {
    int num[] = {9999, 49, 38, 65, 97, 76, 13, 27, 49, 55, 04};
    int len = 11;
    printArrayWithGuard(num, len);
    sort(num, len);
    printArrayWithGuard(num, len);
    return 0;
}