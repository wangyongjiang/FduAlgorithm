#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/7 10:49 上午
 * Desc ：下课了，有 n 位同学陆续赶到⻝堂进⾏排队打饭，其中第 i 位同学的到达时间为 ai，
          打饭耗时为 ti，等待时间上限为 bi，即如果其在第 ai+bi秒的时刻仍然没有轮到他开
          始打饭，那么他将离开打饭队列，另寻吃饭的地⽅。问每位同学的开始打饭时间，或者
          指出其提前离开了队伍（如果这样则输出 -1）。
 */
const int N = 100010;

struct Student {
    int arrive, consume, wait;
}students[N];

bool cmp(Student a, Student b) {
//    return a.arrive + a.consume < b.arrive + b.consume;
    return a.arrive < b.arrive;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, t, b;
        cin >> a >> t >> b;
        students[i] = {a, t, b};
    }
    sort(students + 1, students + 1 + n, cmp);

    int lastOver = 1;
    for (int i = 1; i <= n; i++) {
        auto stu = students[i];
        if (stu.arrive + stu.wait < lastOver) {
            cout << "-1 ";
        } else {
            cout << lastOver << " ";
            lastOver += stu.consume;
        }
    }

    return 0;
}