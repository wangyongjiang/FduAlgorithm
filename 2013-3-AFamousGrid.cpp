#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/18 6:34 下午
 * Desc ：在螺旋矩阵中，问两个位置（不能经过素数位置）之间的最短距离是多少
 * 思路：先用筛法，找出101*101内的素数（因为输入的两点值限制是一万内）；
 * 之后去填满数组arr[110][110]，像图片中那样从arr[50][50]（也就是1的位置）开始填起，
 * 如果是素数就填-1表示这个路径不通，否则填入相应的数字；之后用bfs找出最短路径（走迷宫）
 *
 */
typedef pair<int, int> PII;
const int N = 20010;
int primes[N];
bool flag[N]; // false表示是素数
int g[110][110], cnt;
PII pos[N]; // 数组下标是矩阵的值，内容是对应的下标


void lineSelect() {
    flag[1] = true; // 1不是素数
    for (int i = 2; i <= 10000; i++) {
        if (!flag[i]) primes[cnt++] = i;
        for (int j = 0; i * primes[j] <= 10000; j++) {
            flag[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void generateSpiralArray() {
    // 具体思路：观察可知，1先向右边走1步生成2，再向上走1步生成3，| 再向左走2步生成4/5，再向下走2步生成6/7 | 再向右边走3步生成8/9/10，再向上走3步生成11/12/13....
    // 可知：先是右上各走1，左下各走2，右上各走3，可利用一个bool变量表示是右上还是左下，
    // 自增变量表示步长，当生成的数大于1万就可以停止。
    pos[1] = {50, 50}; // 只要是中心位置就可，49，49也行，通过pos下标已经对应好了
    g[50][50] = 1;
    int num = 1;
    int len = 1; // 步长
    bool direct = true; // true就是右上，false就是左下
    PII start = {50, 50};
    while (num <= 10000) {
        if (direct) { // 右 + 上，走len步
            // 右走len步
            int x = start.first, y = start.second;
            for (int i = 1; i <= len; i++) {
                y++;
                num++;
                pos[num] = {x, y};
                g[x][y] = flag[num] ? num : -1;
            }
            // 上走len步
            for (int i = 1; i <= len; i++) {
                x--;
                num++;
                pos[num] = {x, y};
                g[x][y] = flag[num] ? num : -1;
            }
            start = {x, y};
            direct = false;
            len++;
        } else {
            // 左 + 下
            int x = start.first, y = start.second;
            // 左
            for (int i = 1; i <= len; i++) {
                y--;
                num++;
                pos[num] = {x, y};
                g[x][y] = flag[num] ? num : -1; // 质数存-1
            }
            // 下走len步
            for (int i = 1; i <= len; i++) {
                x++;
                num++;
                pos[num] = {x, y};
                g[x][y] = flag[num] ? num : -1;
            }
            start = {x, y};
            direct = true;
            len++;
        }
    }
}

int bfs(int startNum, int endNum) {
    PII start = pos[startNum];
    PII end = pos[endNum];
    queue<PII> q;
    q.push(start);
    int dist[110][110]; // 存储从 start出发的最短路径
    memset(dist, -1, sizeof dist);
    dist[start.first][start.second] = 0;

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
    while (q.size()) { // 遇到-1就不能通过
        PII c = q.front();
        q.pop();

        int x = c.first;
        int y = c.second;
        if (x == end.first && y == end.second) {
            return dist[x][y];
        }
        for (int i = 0; i < 4; i++) {
            int nX = x + dx[i];
            int nY = y + dy[i];
            if (nX >= 0 && nX < 110 && nY >= 0 && nY < 110 && dist[nX][nY] == -1
                && g[nX][nY] != -1) {
                dist[nX][nY] = dist[x][y] + 1;
                q.push({nX, nY});
            }
        }
    }
    return -1;
}

int main() {
    // 线性筛法
    lineSelect();
    // 生成螺旋数组
    generateSpiralArray();
    // bfs
    int start, end;
    while (cin >> start >> end) {
        int res = bfs(start, end);
        if (res == -1) cout << "impossible";
        else cout << res << endl;

    }
    return 0;
}
