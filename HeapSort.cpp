#include <iostream>
#include  "jarynUtils.h"

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2022/4/20 8:33 上午
 * Desc ：选择排序 - 堆排序
 *        堆 - 完全二叉树，根 ≥ 左右，注意和BST区分
 */

// 调整指定root下标的双亲结点为大顶堆，并且"实现小元素下坠"
void adjustHeap(int *num, int root, int len){
    // 根元素暂存，后面需要使用，用一个变量也可以
    num[0] = num[root];
    // i为root的左孩子，左孩子小于等于len表示root节点有左孩子
    // 当左孩子大于len表示root没有左孩子，为叶子结点（完全二叉树的特性）,
    //          此时这个叶子结点的位置就应该是root最后下坠的位置（若没有break）
    // i *= 2 表示 root每次下坠时，i也要跟着下坠，成为新root的左子树
    for (int i = root * 2; i <= len; i *= 2) {
        // 小于len表示有右兄弟（完全二叉树的特性），
        if (i < len && num[i] < num[i + 1]) {
            i++;
        }
        if (num[0] > num[i]) {
            // 已经是要处理的元素已是最大的，那么就是大顶堆了，因为建堆是从下往上建的，下面子树必是大顶堆
            // 跳出循环，让当前root重新赋值 处理的元素（num[0]）即可
            break;
        } else {
            // 子节点大于当前节点，需要交换，并且会发生小元素下坠的情况
            num[root] = num[i];
            // 开始下坠到大的子节点，不断进行循环调整
            root = i;
        }
    }
    // 最后务必别忘记，将小元素对应的下坠位置赋值
    num[root] = num[0];
}

/**
 * 建堆，每次从最后一个分支结点往前构建，自下而上，否则自上而下都分叉了，不好建
 *        最后一个分支结点：n / 2 向下取整
 *        最后一个分支结点前面的元素都是分支结点（完全二叉树的特性）
 */
void buildMaxHeap(int *num, int len){
    // 数组从1开始存数据
    for (int i = len / 2; i > 0; --i) {
        adjustHeap(num, i, len);
    }
}

/**
 * 开始建堆 + 排序
 *   排序：因为大顶堆第一个元素必是最大的，所以将第一个元素与最后一个交换
 *        前len - 1个元素重新成堆
 *        继续第一个与第len - 1个的交换
 *        ...
 *        直到剩下一个元素即可，自然有序
 *        最后数组为升序
 */
void sort(int *num, int len){
    // 建堆
    buildMaxHeap(num, len);
    // 数组 1 - len才保存数据，只需排序n - 1躺
    for (int i = len; i > 1; i--) {
        swap(num[1], num[i]);
        // 注意这里len为i - 1，因为每次交换后，最后一个元素会有序
        adjustHeap(num, 1, i - 1);
    }
}

int main() {
    // 堆结构使用完全二叉树的顺序存储，此时0元素默认不存东西，下标从1开始
    int num[] = {9999, 87, 45, 78, 32, 17, 65, 53, 9};
    int len = 8;
    sort(num, len);
    printArrayWithGuard(num, 9);
    return 0;
}