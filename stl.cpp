#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010; // 映射后的数组下标范围

int a[N], s[N];

vector<PII> query, add;
vector<int> alls;

// 二分查找alls中x的下标
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1；
}

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 排序 + 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto addPair : add) {
        // 取出x和c
        int x = addPair.first;
        int c = addPair.second;
        a[find(x)] += c;
    }

    for (int i = 1; i <= alls.size(); i++) {
        s[i] = s[i - 1] + a[i];
    }

    for (auto queryPair : query) {
        int l = queryPair.first;
        int r = queryPair.second;
        cout << s[find(r)] - s[find(l) - 1] << endl
    }

    return 0;
}