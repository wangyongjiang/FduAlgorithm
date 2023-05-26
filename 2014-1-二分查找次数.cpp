#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/19 4:34 下午
 * Desc ：第一行输入一个整数N（N<=10000）。
        第二行输入N个升序整数。
        第三行输入一个待查找的整数（必定在第二行中出现过）。

        输出二分查找该整数时，进行过多少次二分。
 */
const int N = 100010;
int a[N];
int main() {
    int n, target, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> target;

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        cnt++;
    }

    cout << cnt;
    return 0;
}