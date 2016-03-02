#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll dp[100100];
vector <ll > vk;

ll g ( ll n, ll k )
{
	if ( n == 1 ) {
		return 0;
	}

	if ( dp[n] != -1 ) {
		return dp[n];
	}

	ll big  = ( g ( n - 1, k ) + k ) % n ;
	return dp[n] = big;
}


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
		memset ( dp, -1, sizeof dp );
		cin >> n >> k;
		ll ans = g ( n, k );
		printf ( "Case %lld: %lld\n", cases - t, ans + 1 );
	}

	return 0;
}