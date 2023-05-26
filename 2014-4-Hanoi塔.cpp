#include <bits/stdc++.h>

using namespace std;

/**
 * Author ：Jaryn
 * Time ：2023/3/19 4:34 下午
 * Desc ：Hanoi 塔问题是印度的一个古老的传说。开天辟地的神勃拉玛在一个庙里留下了三根金刚石的棒，
 * 第一根上面套着64 个圆的金片，最大的一个在底下，其余一个比一个小，依次叠上去，
 * 庙里的众僧不倦地把它们一个个地从这根棒搬到另一根棒上，规定可利用中间的一根棒作为帮助，但每次只能搬一个，
 * 而且大的不能放在小的上面。
 *
    请编写程序，把A 柱上的n 个金片，搬动到C 柱（中间可以使用B 柱），使得搬动的次数最少。
    输入金片的个数n（1<=n<=64），输出总搬动次数，以及最后100 次搬动。如果搬动次数小于等于100 则全部输出；
    每个搬动占一行，加上是这第几次搬动的数字和”:”，格式见示例。
 */


int ans;
int f[70]; // f[i]表示有i个圆环时的搬动总次数
int nn;
void hanoi(int n, char a, char b, char c) { // 将a的通过b搬到c
    if (n == 1) {
        ans++;
        if (f[nn] - ans <= 100)
             cout << ans << ":" << a << "->" << c << endl;
        return;
    }
    hanoi(n - 1, a, c, b); // 把a的前n-1个移到b先
    hanoi(1, a, b, c); // 把a的最后一个移到c
    hanoi(n - 1, b, a, c); // 把b的n-1个移到c
}
int main() {

    cin >> nn;

    // 计算f[i]
    f[1] = 1;
    for (int i = 2; i <= nn; i++) {
        f[i] = f[i - 1] * 2 + 1; // 先把前i-1个搬到b，再把最大的搬到c，再把b的n-1个搬到c。所以是2* + 1
    }
    cout << f[nn] << endl;
    hanoi(nn, 'A', 'B', 'C');

    return 0;
}