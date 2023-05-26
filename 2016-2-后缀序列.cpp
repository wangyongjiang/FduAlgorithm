#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/4 4:15 下午
 * Desc ：给定一个后缀序列，要求求值，只有加减 输入：23+1+，输出：6
 */

int main() {
    // 思路：利用栈实现表达式求值中，如果是中序序列，那么要用到操作数栈和运算符栈
    // 而这里是后缀，那么用到操作数栈即可
    // 遍历字符串，遇到数字入栈，字符出栈，先出栈的是右操作数
    stack<int> op;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) op.push(s[i] - '0');
        else if (s[i] == '+') {
            int rNum = op.top(); op.pop();
            int lNum = op.top(); op.pop();
            op.push(lNum + rNum);
        } else if (s[i] == '-') {
            int rNum = op.top(); op.pop();
            int lNum = op.top(); op.pop();
            op.push(lNum - rNum);
        }
    }
    cout << op.top();
    return 0;
}