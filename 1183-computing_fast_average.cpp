#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <pair <ll, ll> > v;

struct sam {
	int lazy;
	int cnt;
	int sum;

};

struct sam nodes[500100];

void initilize ( int node )
{
	nodes[node].lazy = -1;
	nodes[node].sum = 0;
	nodes[node].cnt = 0;
}

void buildtree ( int node, int start, int end, int val )
{
	if ( start > end ) {
		return;
	}

	if ( start == end )
	{
		initilize ( node );
		return;
	}

	int mid = start + end;
	mid /= 2;
	buildtree ( node * 2 + 1, start , mid, val );
	buildtree ( node * 2 + 2, mid + 1, end, val );
	initilize ( node );
	return;
}

void update ( int node, int start, int end, int qstr, int qend, int val )
{
	if ( nodes[node].lazy != -1 ) {
		int temp = nodes[node].lazy ;

		if ( start != end ) {
			nodes[node * 2 + 1].lazy = temp, nodes[node * 2 + 2].lazy  = temp;
		}

		nodes[node].sum = ( end - start + 1 ) * temp;
		nodes[node].lazy = -1;
	}

	if ( start > end ) {
		return;
	}

	if ( qend < start || qstr > end ) {
		return;
	}

	if ( qstr <= start and qend >= end ) {
		int	temp = val;

		if ( start != end ) {
			nodes[node * 2 + 1].lazy = temp, nodes[node * 2 + 2].lazy = temp;
		}

		nodes[node].sum = ( end - start + 1 ) * temp;
		nodes[node].lazy = -1;
		return;
	}

	int mid = start + end;
	mid /= 2;
	update ( node * 2 + 1, start, mid, qstr, qend, val );
	update ( node * 2 + 2, mid + 1, end, qstr, qend, val );
	nodes[node].sum = nodes[node * 2 + 1].sum + nodes[node * 2 + 2].sum;
}

ll query ( int node, int start, int end, int qstr, int qend )
{
	if ( nodes[node].lazy != -1 ) {
		int temp = nodes[node].lazy ;

		if ( start != end ) {
			nodes[node * 2 + 1].lazy = temp, nodes[node * 2 + 2].lazy  = temp;
		}

		nodes[node].sum = ( end - start + 1 ) * temp;
		nodes[node].lazy = -1;
	}

	if ( start > end ) {
		return 0;
	}

	if ( qend < start || qstr > end ) {
		return 0;
	}

	if ( qstr <= start and qend >= end ) {
		return nodes[node].sum;
	}

	int mid = start + end;
	mid /= 2;
	int left = query ( node * 2 + 1, start, mid, qstr, qend );
	int right = query ( node * 2 + 2, mid + 1, end, qstr, qend );
	return left + right;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ( "/home/placements2016/input.sam", "r", stdin );
#endif
	//ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b, c;
	//cin >> t;
	scanf ( "%lld", &t );
	ll cases = t;
	ll temp = 0;

	while ( t-- ) {
		//cin >> n >> m;
		scanf ( "%lld %lld", &n, &m );
		memset ( nodes, 0, sizeof nodes );
		//  cout << "Case " << cases-t << ":"  << endl;
		printf ( "Case %lld:\n", cases - t );
		buildtree ( 0, 0, n - 1, 0 );

		//cout << "after bldng :" << nodes[1].arr[0] << " " << nodes[2].arr[0] << " "<< nodes[0].arr[2] << endl;

		for ( i = 0; i < m; i++ ) {
			//cin >> k;
			//cin >> a >> b;
			scanf ( "%lld %lld %lld ", &k, &a, &b );

			if ( k == 1 ) {
				//cin >> c;
				scanf ( "%lld", &c );
				update ( 0, 0, n - 1, a, b, c );

			} else if ( k == 2 ) {
				ll ans ;
				ans = query ( 0, 0, n - 1, a, b ) ;

				if ( ans % ( b - a + 1 ) == 0 ) {
					printf ( "%lld\n",  ans / ( b - a + 1 ) );
				}

				else {
					printf ( "%lld/%lld\n", ans / __gcd ( ans,  ( b - a + 1 ) ), ( b - a + 1 ) / __gcd ( ans,  ( b - a + 1 ) ) );
				}
			}
		}
	}

	return 0;
}