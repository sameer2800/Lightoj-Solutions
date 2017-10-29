#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define pb push_back

vi g[20100];
bool visit[20100];
bool pre[20100];
vi ff;
vi ss;

void clea()
{
    for (int i=0;i<20100;i++){
        g[i].clear();
        visit[i]=0;
        pre[i]=0;
    }
    ff.clear();
    ss.clear();
}

void dfs(int v,int fl)
{
    if (visit[v] != 0)
        return;
    visit[v]=1;
    int nfl = ((fl==1) ? 2 : 1);
    if (fl == 1)
        ff.pb(v);
    else
        ss.pb(v);
    for (int i=0;i<g[v].size();i++){
        int u = g[v][i];
        dfs(u,nfl);
    }
}

int main ()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        cout<<"Case "<<cas++<<": ";
        int n;
        cin>>n;
        clea();
        int ma=0;
        for (int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
            pre[u]=1;
            pre[v]=1;
            ma=max(ma,max(u,v));
        }
        int co=0;
        for (int i=1;i<=ma;i++){
            if (pre[i]==1 && visit[i]==0){
                dfs(i,1);
                co+=max(ff.size(),ss.size());
                ff.clear();
                ss.clear();
            }
        }
        cout<<co<<endl;
    }
    return 0;
}

