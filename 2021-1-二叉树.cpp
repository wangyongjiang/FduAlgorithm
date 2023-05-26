#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/8 11:35 上午
 * Desc ：给定一颗二叉树，树的每个节点的值为一个正整数。
 * 如果从根节点到节点 N 的路径上不存在比节点 N 的值大的节点，
 * 那么节点 N 被认为是树上的关键节点。求树上所有的关键节点的个数。
 */
typedef struct TreeNode{
    int val;
    TreeNode *left = NULL, *right = NULL, *parent = NULL;
} TreeNode;

vector<int> path;
queue<TreeNode *> q;

int res = 0; // 根默认是

void postOrder(TreeNode *p) {
    if (p == NULL) return;
    path.push_back(p -> val);
    postOrder(p -> left);
    postOrder(p -> right);
    bool isKey = true;
    for (int i = 0; i < path.size() - 1; i++) {
        if (path[i] > path[path.size() - 1]) isKey = false;
    }
    if (isKey) {
        res++;
    }
    path.pop_back();
}

int main() {
    // 测试案例：3 1 4 3 null 1 5
    string s;
    getline(cin ,s);
    stringstream ss(s);
    vector<string> cnt;
    string c;
    while (getline(ss, c, ' ')) {
        cnt.push_back(c);
    }
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root -> val = stoi(cnt[0]);
    q.push(root);
    int cont = 1;
    while (q.size()) {
        if (cont >= cnt.size()) break;
        TreeNode * p = q.front();
        q.pop();
        if (p == NULL) {
            cont += 2;
            continue;
        }
        string nodeVal = cnt[cont++];
        if (nodeVal != "null") {
            TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
            node -> val = stoi(nodeVal);
            p -> left = node;
            node -> parent = p;
            q.push(node);
        } else {
            p -> left = NULL;
            q.push(NULL);
        }

        nodeVal = cnt[cont++];
        if (nodeVal != "null") {
            TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
            node -> val = stoi(nodeVal);
            p -> right = node;
            node -> parent = p;
            q.push(node);
        } else {
            q.push(NULL);
            p -> right = NULL;
        }
    }
    cout << (root -> left == NULL);
    return 0;
}

// 使用后序遍历，存储 遍历路径上的结点值，每到一个结点只需判断 这些结点值是否都小于等于当前结点值 即是关键结点
//int main() {
//    // 测试案例：3 1 4 3 null 1 5
//    string s;
//    getline(cin ,s);
//    stringstream ss(s);
//    vector<string> cnt;
//    string c;
//    while (getline(ss, c, ' ')) {
//        cnt.push_back(c);
//    }
//    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
//    root -> val = stoi(cnt[0]);
//    q.push(root);
//    int cont = 1;
//    while (q.size()) {
//        if (cont >= cnt.size()) break;
//        TreeNode * p = q.front();
//        q.pop();
//        if (p == NULL) {
//            cont += 2;
//            continue;
//        }
//        string nodeVal = cnt[cont++];
//        if (nodeVal != "null") {
//            TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
//            node -> val = stoi(nodeVal);
//            p -> left = node;
//            node -> parent = p;
//            q.push(node);
//        } else {
//            p -> left = NULL;
//            q.push(NULL);
//        }
//
//        nodeVal = cnt[cont++];
//        if (nodeVal != "null") {
//            TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
//            node -> val = stoi(nodeVal);
//            p -> right = node;
//            node -> parent = p;
//            q.push(node);
//        } else {
//            q.push(NULL);
//            p -> right = NULL;
//        }
//    }
//    cout << (root -> left == NULL);
//    return 0;
//}

