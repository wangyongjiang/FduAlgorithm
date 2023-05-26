#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/17 3:34 下午
 * Desc ：给出四个正方体箱子的边长，问能装下这四个正方体箱子
    的大正方体边长最小要多大，要求边长最小且必须能装下四个箱子。

 */

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    // 22组合的最大值
    int ans = -1;
    ans = max(ans, a + b);
    ans = max(ans, a + c);
    ans = max(ans, a + d);
    ans = max(ans, b + c);
    ans = max(ans, b + d);
    ans = max(ans, c + d);
    cout << ans;
    return 0;
}