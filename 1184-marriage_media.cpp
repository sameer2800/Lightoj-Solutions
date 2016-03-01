#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[155][155];

ll m, n, src, dest;
ll visited[155];
ll parent[155];

struct person {
	ll age, height, divorce;
};

person male[55], female[55];


int bfs()
{
	queue < ll> q;
	q.push ( src );
	memset ( visited, 0, sizeof visited );
	memset ( parent, -1, sizeof parent );
	visited[src] =   1;

	while ( !q.empty() ) {
		ll fr = q.front();
		q.pop();

		if ( fr == dest ) {
			return 1;
		}

		for ( int i = 0; i <= dest; i++ ) {
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

		ans++;
	}

	return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen ( "/home/placements2016/input.sam", "r", stdin );
#endif
	ll i, j, k, t, cont, a, b;
	scanf ( "%lld", &t );
	ll cases = t;

	while ( t-- ) {
		memset ( arr, 0, sizeof arr );
		scanf ( "%lld %lld", &n, &m );

		for ( i = 0; i < n; i++ ) {
			scanf ( "%lld %lld %lld", &male[i].height , &male[i].age, &male[i].divorce );
		}

		for ( i = 0; i < m; i++ ) {
			scanf ( "%lld %lld %lld", &female[i].height , &female[i].age, &female[i].divorce );
		}

		for ( i = 0; i < n; i++ ) {
			for ( j = 0; j < m; j++ ) {
				if ( abs ( male[i].age - female[j].age ) <= 5 and abs ( male[i].height - female[j].height ) <=  12 and ( male[i].divorce == female[j].divorce ) ) {
					arr[i][j + n] = 1;
				}
			}
		}

		src = m + n + 1 ;
		dest = m + n + 2;

		for ( i = 0; i < n; i++ ) {
			arr[m + n + 1][i] = 1;
		}

		for ( j = 0; j < m; j++ ) {
			arr[j + n][m + n + 2] = 1;
		}

		ll ans = max_biparitite_matching();
		printf ( "Case %lld: %lld\n", cases - t, ans );
	}

	return 0;
}