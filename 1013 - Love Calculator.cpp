/*
Took hint from Internet.

First part is relatively simple. its just a.size()+b.size()-lcs(a,b). Now for the second part, we
need to consider these cases on the shortest string generated in part1. Call it X.
1) if the character k of X is same in both the strings, then dp[k,i,j] = dp[k-1,i-1,j-1]
2) if the character k was from a, then dp[k,i,j]+=dp[k-1,i-1,j]
3) if the character k was from b, then dp[k,i,j]+=dp[k-1,i,j-1]*

*/


#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector < pii >
#define si set<int>
#define ll long long int
#define pb push_back
#define mp make_pair
#define fr first
#define se second
#define MOD 1000003
#define MAX 10100

int main ()
{
    cout << setprecision(7) << fixed;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int cas=1;
	while (t--){
		cout<<"Case "<<cas++<<": ";
        string a,b;
        cin>>a>>b;
        int n=a.size();
        int m=b.size();
        unsigned ll dp[n+1][m+1];
        unsigned ll num[n+1][m+1];
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
                num[i][j]=false;

        for (int i=0;i<=n;i++){
            for (int j=0;j<=m;j++){
                if (i==0 || j==0){
                    dp[i][j]=0;
                    num[i][j]=1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    num[i][j]=0;
                    if (a[i-1] == b[j-1]){
                        dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                        num[i][j] = num[i-1][j-1];
                    }
                    else{
                        if (dp[i-1][j] >= dp[i][j-1])
                            num[i][j] += num[i-1][j];
                        if (dp[i][j-1] >= dp[i-1][j])
                            num[i][j] += num[i][j-1];
                    }
                }
            }
        }
        cout<<(n+m-dp[n][m])<<" "<<num[n][m];
        cout<<endl;
	}
	return 0;
}
