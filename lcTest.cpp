#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/2/14 6:14 下午
 * Desc ：
 */
class Solution {
public:
    typedef struct Person {
        int score, age;
    } Person;

    static bool cmp(Person a, Person b) {
        if (a.age != b.age) return a.age < b.age;
        return a.score < b.score;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // 先根据年龄升序，再根据分数升序
        // f[i]表示以第i个球员为结尾的最大无矛盾球队分数
        // f[i] = max(f[j]+score[i])，其中j < i 且 score[i] > score[j] （不会冲突）
        int f[1005];
        Person persons[1005];
        for (int i = 0; i < scores.size(); i++) {
            persons[i] = {scores[i], ages[i]};
        }

        memset(f, 0, sizeof f);
        sort(persons, persons + scores.size(), cmp);
        f[0] = persons[0].score;

        int ans = -1;
        for (int i = 1; i < scores.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (persons[i].score >= persons[j].score) {
                    f[i] = max(f[i], f[j] + persons[i].score);
                }
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
int main() {
    vector<int> res(2, 1);
    vector<vector<int>> blue{ {1,2},{3,4},{5,6},{7,8} };
    vector<string> a{"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    vector<int> b1{1,2,3, 5};
    vector<int> b2{8,9,10,1};
    Solution solution;
 //   cout << solution.threeSum(triangle) << endl;
    cout << solution.bestTeamScore(b1, b2) ;
}

//"abccef"
//"cgdhga"