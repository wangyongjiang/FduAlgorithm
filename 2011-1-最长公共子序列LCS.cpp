#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/17 3:34 下午
 * Desc ：输入3个子串， 输出这3个子串的最大公共子串
         输入 ： abcd acb abc  输出：ab

 */
const int N = 100;
string f[N][N][N];
int main() {
    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            for (int k = 1; k <= c.size(); k++) {
                // 相同时
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
                    f[i][j][k] = f[i - 1][j - 1][k - 1] + a[i - 1];
                } else {
                    // 不同时则选长度大
                    if (f[i - 1][j][k].size() > f[i][j - 1][k].size()
                            && f[i - 1][j][k].size() > f[i][j][k - 1].size()) {
                        f[i][j][k] = f[i - 1][j][k];
                    } else if (f[i][j - 1][k].size() > f[i - 1][j][k].size()
                               && f[i][j - 1][k].size() > f[i][j][k - 1].size()) {
                        f[i][j][k] = f[i][j - 1][k];
                    } else {
                        f[i][j][k] = f[i][j][k - 1];
                    }
                }
            }
        }
    }
    cout << f[a.size()][b.size()][c.size()];
    return 0;
}