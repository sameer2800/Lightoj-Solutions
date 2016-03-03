#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arra[150], arrb[150];
vector <ll > vk;

int main()
{
#ifndef ONLINE_JUDGE
	freopen ( "/home/placements2016/input.sam", "r", stdin );
#endif
	ios_base::sync_with_stdio ( false );
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while ( t-- ) {
		cin >> n;

		for ( i = 0; i < n; i++ ) {
			cin >> arra[i];
		}

		for ( i = 0; i < n; i++ ) {
			cin >> arrb[i];
		}

		ll ans = 0;

		for ( i = 0; i < n; i++ ) {
			ans ^= ( arrb[i] - arra[i] - 1 );
		}

		if ( ans == 0 ) {
			printf ( "Case %lld: black wins\n", cases - t );

		} else {
			printf ( "Case %lld: white wins\n", cases - t );
		}
	}

	return 0;
}