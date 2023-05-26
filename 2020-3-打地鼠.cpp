#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/7 11:35 上午
 * Desc ：给定 n 个整数 a1, a2, …, an 和⼀个 d，你需要选出若⼲个整数，使得将这些整数从⼩到⼤排好序之后，
 *  任意两个相邻的数之差都不⼩于给定的d(>=d)，问最多能选多少个数出来。
 */
const int N = 100010;
int a[N];
int main() {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int cnt = 1; // 默认选了a[0]
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] >= d) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}