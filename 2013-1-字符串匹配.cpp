#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/17 3:34 下午
 * Desc ：对于主串M和模式串P，找到P在M中出现的所有子串
            的第一个字符在P中的位置。
            P中第一个字符所在的位置为0。
            首行的数字表示有多少组字符串。
 */

int main() {
    string sstr, pstr;
    int x;
    cin >> x;
    while (x--) {
        cin >> (sstr) >> (pstr);
        int pos = 0;
        while (pos < sstr.size()) {
            int ans = sstr.find(pstr, pos);
            if (ans != -1) cout << ans << " ";
            pos = max(++pos, ans+1);
        }
        cout << endl;

//        int n = sstr.size(), m = pstr.size();
//        vector<char> s(n + 1), p(m + 1);
//        for(int i = 0; i < n; i++) s[i + 1] = sstr[i]; // 转为下标从1开始
//        for(int i = 0; i < n; i++) p[i + 1] = pstr[i];
//        vector<int> ne(m + 1);
//
//        for (int i = 2, j = 0; i <= m; i++) {
//            while (j && p[i] != p[j + 1]) j = ne[j];
//            if (p[i] == p[j + 1]) j++;
//            ne[i] = j;
//        }
//        for (int i = 1, j = 0; i <= n; i++) {
//            while (j && s[i] != p[j + 1]) j = ne[j];
//            if (s[i] == p[j + 1]) j++;
//            if (j == m) {
//                cout << i - j << " ";
//                j = ne[j];
//            }
//        }
//        cout << endl;
    }
    return 0;
}