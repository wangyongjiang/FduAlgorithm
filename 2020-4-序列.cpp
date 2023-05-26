#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/7 11:35 上午
 * Desc ：给定⼀个⻓为 n 的序列 A，其中序列中的元素都是 0~9 之间的整数，对于⼀个⻓度同样为 n 整数序列B
         定义其权值为 |A[i]-B[i]| (1<=i<=n) 之和加上 (B[j]-B[j+1])的平方 (1<=j<n) 之和。
         求所有⻓为 n 的整数序列中，权值最⼩的序列的权值是多少。
 */

// 1. f[i][j]表示前i个数字（也就是1到i），且b[i] == j 的权值和最小值，其中j小于10
int f[100001][10], a[100001];
int main() {
    // 2.定状态转移方程：f[i][j]可由 前i-1个数字，且b[i - 1] == k 的权值和最小值f[i - 1][k]
    //                                                  加上a[i]这一位的权值，最后取min
    // 3.定边界，f[0][0]前0个字符，且 b[0] == j 的权值和最小值(次数)，不存在，就是0
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) { // 这里的j就是b[i]
            f[i][j] = INT_MAX;
            for (int k = 0; k < 10; k++) { // 这里的就是b[i - 1]
                // 转移方程
                f[i][j] = min(f[i][j], f[i - 1][k] + abs(a[i] - j) + (j - k) * (j - k));
            }
        }
    }

    int res = INT_MAX;
    for (int i = 1; i <= n; i++) res = min(f[n][i] ,res);

    cout << res;
    return 0;
}