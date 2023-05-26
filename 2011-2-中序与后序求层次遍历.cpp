#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/17 3:34 下午
 * Desc ：输入树的中序和后序排列，输出树的层次遍历
输入：
7
1 2 3 4 5 6 7
2 3 1 5 7 6 4
输出：4 1 6 3 5 7 2
 */

typedef struct TreeNode {
    int val;
    TreeNode *left = NULL, *right = NULL;
} TreeNode;

TreeNode* create(vector<int> &mid, vector<int> &post, int midL, int midR, int postL, int postR) {
    if (midL > midR) return NULL;
    if (postL > postR) return NULL;
    int val = post[postR]; // 当前根节点
    int pos = -1;
    for (int i = midL; i <= midR; i ++) {
        if (val == mid[i]) {
            pos = i;
            break;
        }
    }

    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node -> val = val;
    node -> left = create(mid, post, midL, pos - 1, postL, postL + pos - midL - 1);
    node -> right = create(mid, post, pos + 1, midR, postL + pos - midL, postR - 1);
    return node;
}

int main() {
    // 思路：先建树、再层次遍历
    int n;
    cin >> n;
    vector<int> mid(n), post(n);
    for (int i = 0; i < n; i++) cin >> mid[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    TreeNode *root = create(mid, post, 0, n - 1, 0, n - 1);

    queue<TreeNode*> q;
    q.push(root);
    cout << root -> val << " ";
    while (q.size()) {
        auto c = q.front();
        q.pop();

        if (c -> left) {
            cout <<  c -> left -> val << " ";
            q.push(c -> left);
        }
        if (c -> right) {
            cout <<  c -> right -> val << " ";
            q.push(c -> right);
        }
    }
    return 0;
}