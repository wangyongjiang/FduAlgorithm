#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/7 11:35 上午
 * Desc ：给定⼀个 1~n 的排列 P，即⻓度为 n，且 1~n 中所有数字都恰好出现⼀次的序列。
 * 现在按顺序将排列中的元素⼀⼀插⼊到初始为空的⼆叉搜索树中（左小右大），问最后每个节点的⽗亲节点的元素是什么。
 * 特别地，根节点的⽗亲节点元素视为 0。
 */
const int N = 100010;
int a[N];
typedef struct TreeNode {
    int val;
    TreeNode *l, *r, *p;
} TreeNode;

void midOrder(TreeNode *p) {
    if (p == NULL) return;
    midOrder(p -> l);
    if (p -> p != NULL) cout <<  p -> p -> val << " ";
    else cout << "0 ";
    midOrder(p -> r);
}

/** 测试用例：
5
2 3 5 1 4
**/
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];


    TreeNode *root = new TreeNode();
    root -> val = a[0];

    TreeNode *p = root;
    TreeNode *pre = root;
    for (int i = 1; i < n; i++) {
        p = root;
        bool isLeft = false;
        while (p) {
            pre = p;
            if (a[i] <= p -> val) {
                p = p -> l;
                isLeft = true;
            } else if (a[i] > p -> val) {
                p = p -> r;
                isLeft = false;
            }
        }
        TreeNode *node = new TreeNode();
        node -> val = a[i];
        node -> p = pre;
        if (isLeft) pre -> l = node;
        else pre -> r = node;
    }
    return 0;
}
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> a[i];
//    TreeNode *root = new TreeNode();
//    root -> val = a[0];
//    root -> l = NULL;
//    root -> r = NULL;
//    // 建树
//    for (int i = 1; i < n; i++) {
//        TreeNode *p = root, *pre;
//        bool isLeft = true;
//        while (p != NULL) {
//            pre = p; // 指向p的前驱
//            if (a[i] < p -> val) {
//                p = p->l;
//                isLeft = true;
//            }
//            else {
//                p = p->r;
//                isLeft = false;
//            }
//        }
//        auto *newNode = new TreeNode();
//        newNode -> val = a[i];
//        newNode -> l = NULL;
//        newNode -> r = NULL;
//        newNode -> p = pre;
//        if (isLeft) pre -> l = newNode;
//        else pre -> r = newNode;
//    }
//    // 中序遍历
//    midOrder(root);
//    return 0;
//}

