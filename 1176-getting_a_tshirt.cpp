#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[250][250];
map <string , ll > mp;
vector <ll > v1, v2;
ll  src, dest;
ll visited[250];
ll parent[250];

int bfs()
{
    queue < ll> q;
    q.push(src);
    memset(visited, 0, sizeof visited);
    memset(parent, -1, sizeof parent);
    visited[src] =   1;

    while (!q.empty()) {
        ll fr = q.front();
        q.pop();

        if (fr == dest)
            return 1;

        for (int i = 0; i <= dest; i++) {
            if (arr[fr][i] > 0 and visited[i] == 0) {
                q.push(i);
                parent[i] = fr;
                visited[i] = 1;
            }
        }
    }

    return 0;
}


ll max_biparitite_matching()
{
    ll ans = 0;
    ll temp = 0;

    while (bfs()) {
        ll curr = dest;
        ll min_edge = INT_MAX;

        while (curr != src) {
            min_edge = min(min_edge, arr[parent[curr]][curr]);
            curr = parent[curr];
        }

        curr = dest;

        while (parent[curr] != -1) {
            arr[parent[curr]][curr] -= min_edge;
            arr[curr][parent[curr]]  += min_edge;
            curr = parent[curr];
        }

        ans++;
    }

    return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
    ll i, j, k, t, cont, a, b, m, n;
    string s1, s2;
    scanf("%lld", &t);
    ll cases = t;
    mp["XXL"] = 0 , mp["XL"] = 1 , mp["L"] = 2, mp["M"] = 3, mp["S"] = 4, mp["XS"] = 5;

    while (t--) {
        memset(arr, 0, sizeof arr);
        scanf("%lld %lld", &n, &m);
        src = m + n * 7 + 1 ;
        dest = m + n * 7 + 2;

        for (i = 0; i < m; i++) {
            cin >> s1 >> s2;
            ll ind_s1 = mp[s1] , ind_s2 = mp[s2];

            for (j = 0; j < n; j++) {
                arr[i][m + n * ind_s1 + j] = 1;
                arr[i][m + n * ind_s2 + j] = 1;
                arr[m + n * ind_s1 + j][dest] = 1;
                arr[m + n * ind_s2 + j][dest] = 1;
            }
        }

        for (i = 0; i < m; i++) {
            arr[src][i] = 1;
        }

        ll ans = max_biparitite_matching();

        if (ans == m)
            printf("Case %lld: YES\n", cases - t);
        else
            printf("Case %lld: NO\n", cases - t);
    }

    return 0;
}