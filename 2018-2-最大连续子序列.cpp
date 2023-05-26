#include<bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/6 6:44 下午
 * Desc ：dp,f[i]表示以下标i元素结尾的最大连续子序列和
 */
const int N = 100010;
int a[N], f[N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    f[0] = a[0];
    for (int i = 1; i < n; i++) {
        // 必须要以a[i]结尾，那么有俩种情况：
        //          之前的最大连续序列包含a[i]，这种情况是前i-1个大于0
        //          或者是 a[i]独自成为一个序列，这种情况是前i-1个小于等于0
        if(f[i - 1] > 0) f[i] = f[i - 1] + a[i];
        else f[i] = a[i];
    }

    int ans = -2e9;
    for (int i = 0; i < n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}