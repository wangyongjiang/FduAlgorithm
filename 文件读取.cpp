#include<bits/stdc++.h>

using namespace std;
typedef struct Node {
    int weight;
} Node;

struct cmp {
    bool operator() (Node node1, Node node2) {
        return node1.weight < node2.weight;
    }
};


vector<int> a;
int main()
{
    // "/Users/wangyongjiang/Desktop/p1.txt"
    // "/Users/wangyongjiang/Desktop/p1out.txt
    freopen("/Users/wangyongjiang/Desktop/p1.txt", "r", stdin);
    freopen("/Users/wangyongjiang/Desktop/p1out.txt", "w", stdout);

    int cnt = 0;
    int x;
    while (cin >> x) cnt++;
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//int main()
//{
//    freopen("/Users/wangyongjiang/Desktop/p1.txt","r",stdin);
//    freopen("/Users/wangyongjiang/Desktop/p1out.txt","w",stdout);
//    string tt;
//    cin>>tt;
//
//    fclose(stdin);
//    fclose(stdout);
//    return 0;
//}