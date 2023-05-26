#include<bits/stdc++.h>

using namespace std;

/**
 * 解方程，给定一个字符串，代表一个一元一次方程。
    如果有解求解，输出格式“x=数字”，
    如果解的个数无穷，输出 “infinite solutions”。
    如果没有解输出“no solution”，字符串长度不超过 256 。

    输入：2x+4-3x=x-2，输出：x=3
 */


// 是否是操作符号
bool isOperateCharacter(char c) {
    return c == '+' || c == '-' || c == '*' ||c == '/' ||c == 'x';
}

bool isNum(char c) {
    return  c >= '0' && c <= '9';
}

int main() {
    string s; // 2x+4-3x=x-2
    cin >> s;
    // 记录等式左边x的系数，以及出现的常数
    // 记录等式右边x的系数，以及出现的常数
    // 将右边x的系数变负（移到左边）加上左边x系数，左边x的常数变负（移到右边）加上右边x常数
    // 若x系数为0且常数不为0，那么无解，若都为0则无穷解
    // 先处理左边

    // 首字母带负号则插入个0
    if (s[0] == '-') s.insert(s.begin(), '0');// 处理首个-号
    vector<int> xNums, nums; // 存x的系数
    bool neg = false;
    int equalIndex = -1;
    // 2x+4-3x=x-2
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '=') {
            equalIndex = i;
            break;
        }
        int currentNum = 0;

        if (isNum(s[i])) {
            int j = i; // j找到+-*/或者x前的第一个数为止
            while (j < s.size() && !isOperateCharacter(s[j])) {
                currentNum = currentNum * 10 + s[j] - '0';
                j++;
            }
            if (s[j] == 'x') {
                xNums.push_back(neg ? -currentNum : currentNum);
            } else if (isOperateCharacter(s[j])){ // 运算符+-，/号貌似不会出现，*也不会
                nums.push_back(neg ? -currentNum : currentNum);
            }
            i = j - 1; // -1是因为会i++一次
        } else if (isOperateCharacter(s[i])){ // 运算符+-，/号貌似不会出现，*也不会
            if (s[i] == '-') neg = true;
            if (s[i] == '+') neg = false;
            if (s[i] == 'x' && !isdigit(s[i - 1])) { // 处理-x，x
                if (s[i - 1] == '-') xNums.push_back(-1);
                else xNums.push_back(1);
            }
        }


    }

    // 右边 2x+4-3x=x-2
    neg = false;
    if (s[equalIndex + 1] == '-') s.insert(s.begin() + equalIndex + 1, '0'); // 处理首个-号
    vector<int> xNumsRight, numsRight; // 存x的系数
    for (int i = equalIndex + 1; i < s.size(); i++) {
        int currentNum = 0;

        if (isNum(s[i])) {
            int j = i; // j找到+-*/或者x前的第一个数为止
            while (j < s.size() && !isOperateCharacter(s[j])) {
                currentNum = currentNum * 10 + s[j] - '0';
                j++;
            }
            if (s[j] == 'x') {
                xNumsRight.push_back(neg ? -currentNum : currentNum);
            } else if (isOperateCharacter(s[j]) || j == s.size()){ // 运算符+-，/号貌似不会出现，*也不会
                if (currentNum != 0)
                    numsRight.push_back(neg ? -currentNum : currentNum);
            }
            i = j - 1; // -1是因为会i++一次
        } else if (isOperateCharacter(s[i])){ // 运算符+-，/号貌似不会出现，*也不会
            if (s[i] == '-') neg = true;
            if (s[i] == '+') neg = false;
            if (s[i] == 'x' && !isdigit(s[i - 1])) { // 处理-x，x
                if (s[i - 1] == '-') xNumsRight.push_back(-1);
                else xNumsRight.push_back(1);
            }
        }
    }
    // 将右边x的系数变负（移到左边）加上左边x系数，左边x的常数变负（移到右边）加上右边x常数
    // 若x系数为0且常数不为0，那么无解，若都为0则无穷解 2x+4-3x=x-2
    int leftXSum = -1, rightXSum = -1, leftSum = -1, rightSum = -1;
    for (auto x : xNums) {
        leftXSum += x;
    }
    for (auto x : nums) {
        leftSum += x;
    }
    for (auto x : xNumsRight) {
        rightXSum += x;
    }
    for (auto x : numsRight) {
        rightSum += x;
    }

    int xNum = leftXSum - rightXSum;
    int num = rightSum - leftSum;

    if (xNum == 0 && num != 0) cout << "no solution";
    else if (xNum == 0 && num == 0) cout << "infinite solutions";
    else printf("%.2f", (double)num / xNum);
    return 0;
}
