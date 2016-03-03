#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen ( "/home/sameer/sameer/sam.sam", "r", stdin );
#endif
	ios_base::sync_with_stdio ( false );
	ll i, j, k, n, m, t, cont;
	cin >> t;
	ll cases = t;

	while ( t-- ) {
		cin >> n;
		int k = __builtin_popcount ( n );

		if ( k & 1 ) {
			cout << "Case " << cases - t  << ": odd"   << endl;
		}

		else {
			cout << "Case " << cases - t  << ": even"   << endl;
		}
	}

	return 0;
}