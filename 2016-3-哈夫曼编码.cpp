#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/4 4:29 下午
 * Desc ：给定一个字符串，求哈夫曼编码的最短长度。 输入"aaaaabbbbcccdde"，输出33
 */
int main() {
    unordered_map<char, int> cnt; // 记录字符串中字符出现次数
    priority_queue<int, vector<int>, greater<int>> q; // 小根堆
    string str;
    cin >> str;
    for (auto s : str) {
        cnt[s]++;
    }
    for (auto e : cnt) {
        q.push(e.second);
    }

    int alls = 0; // 所有非叶子结点权值和
    while (q.size() != 1) {
        int min1 = q.top(); q.pop();
        int min2 = q.top(); q.pop();
        alls += min1 + min2;
        q.push(min1 + min2);
    }
    cout << alls;
    return 0;
}