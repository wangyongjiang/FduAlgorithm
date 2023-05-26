#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/5 4:54 下午
 * Desc ：给定一个9位数字的ISBN，求其校验位。ISBN格式为2-02-033598，
            校验位的计算方法如下：从左到右依次将各位数字乘10，9，8，……，2，
            求出其和S，作模运算得M=S mod 11。若11-M在1和9之间，校验位即为该数字
            若11-M等于10，校验位为X；11-M等于11，校验位为0。
            输出添加校验位的ISBN，如2-02-033598-0。

           输入样例：为2-02-033598  （注：计算得和S为0）
           输出样例：2-02-033598-0
 */
int main() {
    string isbn;
    cin >> isbn;

    int s = 0, cnt = 10;
    for (int i = 0; i < isbn.size(); i++) {
        if (isbn[i] == '-') continue;
        int currentNum = isbn[i] - '0';
        s += currentNum * (cnt--);
    }
    int m = s % 11;
    int subM = 11 - m;

    if (subM >= 1 && subM <= 9) {
        isbn.append("-" + to_string(subM));
    } else if (subM == 10) {
        isbn.append("-X");
    } else { // subM == 11
        isbn.append("-0");
    }
    cout << isbn;
    return 0;
}