#include<bits/stdc++.h>

using namespace std;

unordered_map<int ,int> mp{ {1, 31}, {2, 28}, {3, 31},
                            {4, 30}, {5, 31}, {6, 30},
                            {7, 31}, {8, 31}, {9, 30},
                            {10, 31}, {11, 30}, {12, 31},  };

bool isRunYear(int year) {
    return year % 400 == 0 || (year % 4 ==0 && year % 100 != 0);
}

int distance(tuple<int, int, int> y) {
    int year = get<0>(y);
    int month = get<1>(y);
    int day = get<2>(y);
    int cnt = 0;
    for (int i = 0; i < year; i++) {
        cnt += (isRunYear(i) ? 366 : 365);
    }
    for (int i = 1; i < month; i++) {
        // 当前年是闰年，若经过2月，cnt还得加1
        if (isRunYear(year) && i == 2) cnt++;
        cnt += (mp[i]);
    }
    cnt += day;
    return cnt;
}

// 保证targetYear在sourceYear之后,{2019, 2, 5}
int sub(tuple<int, int, int> sourceYear, tuple<int, int, int> targetYear) {
    // 计算记录0年1月1日有多少天再做差
    return distance(targetYear) - distance(sourceYear);
}

bool cmp(tuple<int, int, int> year1, tuple<int, int, int> year2) {
    if (get<0>(year1) !=  get<0>(year2)) return get<0>(year1) < get<0>(year2);
    if (get<1>(year1) !=  get<1>(year2)) return get<1>(year1) < get<1>(year2);
    return get<2>(year1) <= get<2>(year2);
}


int main() {
    tuple<int, int, int> sourceYear = {0001, 01, 01};
    string s;
    cin >> s;
    tuple<int, int, int> targetYear = {stoi(s.substr(0, 4)), stoi(s.substr(4, 2)), stoi(s.substr(6, 2)) };
    if (cmp(sourceYear, targetYear)) cout << sub(sourceYear, targetYear);
    else cout << sub(targetYear, sourceYear);
    return 0;
}