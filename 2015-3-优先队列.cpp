#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/4 3:34 下午
 * Desc ：给出优先队列的实现，实现 4 个操作
             ADD N P：往队列里加入id为N的优先级为P的任务
             NEXT:输出下一个最高优先级的任务的id，如果优先级相同输出id小的任务，若队列中没有任务输出-1
             REMOVE N：移除id为N的任务
             COUNT：输出队列中的任务数量
 */
typedef struct Task {
     int id, p;
 } Task;

// 先按优先级p倒序，再按id升序，即最高优先级的任务的id，如果优先级相同输出id小的任务
bool cmp(Task a, Task b) {
    if (a.p != b.p) return a.p > b.p;
    return a.id < b.id;
}

int main() {
    int n;
    cin >> n;
    vector<Task> q;
    while (n--) {
        string op;
        cin >> op;
        int id, p;
        if (op == "ADD") { // 往队列里加入id为N的优先级为P的任务
            cin >> id >> p;
            Task task = {id, p};
            q.push_back(task);
            sort(q.begin(), q.end(), cmp); // 排序
            reverse(q.begin(), q.end()); // 逆序是为了从尾部拿，方便
        } else if (op == "NEXT") {
            // 输出下一个最高优先级的任务的id，如果优先级相同输出id小的任务，若队列中没有任务输出-1
            if (q.empty()) {
                cout << -1 << endl;
                break;
            }
            cout << q[q.size() - 1].id << endl;
            q.pop_back();
        } else if (op == "REMOVE") {
            cin >> id; // 移除id为N的任务

            int size = q.size();
            while (size --) { // 这个for是为了删除出现多个相同id的task
                int pos = 0;
                for (auto t : q) {
                    if (t.id == id) {
                        q.erase(q.begin() + pos); // 删除指定id
                        break;
                    }
                    pos++;
                }
            }

        } else if (op == "COUNT") { // 输出队列中的任务数量
            cout << q.size() << endl;
        }
    }
    return 0;
}