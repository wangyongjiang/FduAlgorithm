#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/17 3:34 下午
 * Desc ：给一个字符串比如ABC 再给一个整数比如3输出AAABBBCCC就行了。

 */
int main() {
    string res = "";
    string s;
    cin >> s;
    int x;
    cin >> x;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < x; j++) res += s[i];
    }
    cout << res;
    return 0;
}