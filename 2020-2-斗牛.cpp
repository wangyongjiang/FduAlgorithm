#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/7 11:04 上午
 * Desc ：给定五个 0~9 范围内的整数 a1, a2, a3, a4, a5。如果能从五个整数中选出三个并
        且这三个整数的和为10 的倍数（包括 0），那么这五个整数的权值即为剩下两个没被
        选出来的整数的和对 10 取余的结果，显然如果有多个三元组满⾜和是 10 的倍数，
        剩下两个数之和对 10 取余的结果都是相同的(因为5个元素总和一样)；如果
        选不出这样三个整数，则这五个整数的权值为 -1。
        现在给定 T 组数据，每组数据包含五个 0~9 范围内的整数，分别求这 T 组数据中
        五个整数的权值。
 */
vector<int> nums(5);

// 这里可以改为三数之和，三指针，找出三个并且这三个整数的和为10 的倍数
tuple<int, int, int> find() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (i != j && j != k && i != k && ((nums[i] + nums[j] + nums[k]) % 10 == 0)) {
                    return {i, j, k};
                }
            }
        }
    }
    return {-1, -1, -1};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        nums.clear(); // 多组数据
        for (int i = 0; i < 5; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());

        // 找出三个并且这三个整数的和为10的倍数（包括 0）
        auto res = find();
        if (get<0>(res) == -1) {
            cout << -1 << endl;
            continue;
        }

        int sum = 0;
        for (int i = 0; i < 5; i++) {
            if (i != get<0>(res) && i != get<1>(res) && i != get<2>(res)) {
                sum += nums[i];
            }
        }
        cout << sum % 10 << endl;
    }
    return 0;
}

