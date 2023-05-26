#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/19 4:34 下午
 * Desc ：输入一棵二叉树，输出树的前、中、后序遍历结果。
          输入一个整数N（N<= 10000)，表示树中有N个结点（编号0~N-1）。
          接下来N行，依次为结点0~结点N-1的左右孩子情况。
          每行3个整数，F,L,R。L,R为F的左右孩子。L,R如果为-1表示该位置上没有孩子。
          分三行分别输出树的前中后序遍历。
          同一行中的数字，用一个空格间隔。
 */
typedef struct TreeNode {
    int val;
    TreeNode *left = NULL, *right = NULL, *parent = NULL; // 父节点方便找到root
}TreeNode ;

const int N = 10010;
TreeNode* a[N];

void preOrder(TreeNode * p) {
    if (p == NULL) return;
    cout << p -> val << " ";
    preOrder(p -> left);
    preOrder(p -> right);
}

void inOrder(TreeNode * p) {
    if (p == NULL) return;
    inOrder(p -> left);
    cout << p -> val << " ";
    inOrder(p -> right);
}

void postOrder(TreeNode * p) {
    if (p == NULL) return;
    postOrder(p -> left);
    postOrder(p -> right);
    cout << p -> val << " ";
}

int main() {
    int n; cin >> n;

    // 先将树存在一个数组中，方便后续构造树
    for (int i = 0; i < n; i++) {
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        node -> val = i;
        a[i] = node;
    }

    // 建树
    for (int i = 0; i < n; i++) {
        int parent, left, right;
        cin >> parent >> left >> right;
        TreeNode *p = a[parent];
        if (left != -1) {
            p -> left = a[left];
            a[left] -> parent = p;
        }
        if (right != -1) {
            p -> right = a[right];
            a[right] -> parent = p;
        }
    }
    TreeNode *root = a[0];
    while (root -> parent) { // 0不一定是根，所以需要找到根节点
        root = root -> parent;
    }

    preOrder(root); cout << endl;
    inOrder(root); cout << endl;
    postOrder(root);
    return 0;
}