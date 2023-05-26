#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/17 3:34 下午
 * Desc ：最大叶子间距，就是求树的直径
 * 思路：先建树，再递归求直径
 */
typedef struct TreeNode {
    int val;
    TreeNode *left = NULL, *right = NULL;
} TreeNode;

int diameter = 0;

// 求直径
int postOrder(TreeNode* p) {
    if (p == NULL) return 0;
    int lHigh = postOrder(p -> left);
    int rHigh = postOrder(p -> right);
    diameter = max(diameter, lHigh + rHigh + 1);
    return max(lHigh, rHigh) + 1;
}

int main() {
    int val;
    cin >> val;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root -> val = val;
    queue<TreeNode*> q;
    q.push(root);
    int preLeftVal, preRightVal;
    // 建树
    while (q.size()) {

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;
        // 出现两次-1 -1就结束
        if (leftVal == -1 && rightVal == -1 && preLeftVal == -1 && preRightVal == -1) break;

        // 当前结点
        TreeNode *c = q.front();
        q.pop();
        if (leftVal != -1) {
            TreeNode *node = new TreeNode();
            node -> val = leftVal;
            c -> left = node;
            q.push(node);
        } else c -> left = NULL;
        if (rightVal != -1) {
            TreeNode *node = new TreeNode();
            node -> val = rightVal;
            c -> right = node;
            q.push(node);
        } else c -> right = NULL;

        preLeftVal = leftVal;
        preRightVal = rightVal;
    }

    // 求直径
    postOrder(root);
    cout << diameter - 1; // -1是因为diameter求的结点数量，-1就是路径长度
    return 0;
}