#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int n;
int dp[100000][20];

int func(long long int mask,int pos)
{
    if (pos==n)
        return 0;
    if (dp[mask][pos]!=-1)
        return dp[mask][pos];
    int ret=0;
    for (int i=0;i<n;i++){
        if (mask & (1<<i))
            continue;
        ret = max(ret,func((mask | 1<<i),pos+1)+a[pos][i]);
    }
    dp[mask][pos]=ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        memset(a,0,sizeof(a));
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        cout<<"Case "<<cas++<<": "<<func(0,0)<<endl;
    }
}

