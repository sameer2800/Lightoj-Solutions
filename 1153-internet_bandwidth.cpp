#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[150][150];
vector <ll > v1, v2;
ll m, n, src, dest;
ll visited[150];
ll parent[150];

int bfs()
{
    queue < ll> q;
    q.push ( src );
    memset ( visited, 0, sizeof visited );
    memset ( parent, -1, sizeof parent );
    visited[src] = 1;

    while ( !q.empty() ) {
        ll fr = q.front();
        q.pop();

        if ( fr == dest ) {
            return 1;
        }

        for ( int i = 0; i <= n; i++ ) {
            if ( arr[fr][i] > 0 and visited[i] == 0 ) {
                q.push ( i );
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

    while ( bfs() ) {
        ll curr = dest;
        ll min_edge = INT_MAX;

        while ( curr != src ) {
            min_edge = min ( min_edge, arr[parent[curr]][curr] );
            curr = parent[curr];
        }

        curr = dest;

        while ( parent[curr] != -1 ) {
            arr[parent[curr]][curr] -= min_edge;
            arr[curr][parent[curr]]  += min_edge;
            curr = parent[curr];
        }

        ans += min_edge;
    }

    return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen ( "/home/placements2016/input.sam", "r", stdin );
#endif
    ll i, j, k, t, cont, a, b, c;
    scanf ( "%lld", &t );
    ll cases = t;

    while ( t-- ) {
        scanf ( "%lld", &n );
        memset ( arr, 0, sizeof arr );
        v1.clear(), v2.clear();
        scanf ( "%lld %lld %lld", &src, &dest, &m );
        src--, dest--;

        for ( i = 0; i < m; i++ ) {
            scanf ( "%lld %lld %lld", &a, &b, &c );
            a--, b--;
            arr[a][b] += c;
            arr[b][a] += c;
        }

        ll ans = max_biparitite_matching();
        printf ( "Case %lld: %lld\n", cases - t, ans );
    }

    return 0;
}