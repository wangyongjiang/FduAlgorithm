#include <iostream>
#include <algorithm>
using namespace std;
const int N=3000+5;
int a[N];
int b[N];
int dp[N][N];
int t[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                for(int k=0;k<j;k++)
                    if(b[k]<b[j])
                        dp[i][j]=max(dp[i-1][k]+1,dp[i][j]);
            } else dp[i][j]=dp[i-1][j];    //比较包含a[i]和不包含哪个更好
        }
    }
    for(int i=1;i<=n;i++)
        res=max(res,dp[n][i]);
    cout<<res;
}