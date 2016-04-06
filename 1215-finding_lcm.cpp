#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <ll > vk;

ll lcm ( ll a , ll b )
{
	return ( a * b ) / __gcd ( a, b );
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ( "/home/placements2016/input.sam", "r", stdin );
#endif
	ios_base::sync_with_stdio ( false );
	ll i, j, k, n, m, t, cont, a, b, l;
	cin >> t;
	ll cases = t;

	while ( t-- ) {
		cin >> a >> b >> l;
		//cout << "hello" << a << b << endl;
		ll lc  = lcm ( a, b );

		if ( lc == l ) {
			cout << "Case " << cases - t << ": 1\n";
			continue;
		}

		if ( l % lc != 0 ) {
			cout << "Case " << cases - t << ": impossible\n";
			continue;
		}

		ll temp = 0;

		for ( i = 1; i * i <= l; i++ ) {
			if ( l % i == 0  ) {
				if ( lcm ( lc, i ) == l ) {
					cout << "Case " << cases - t << ": " << i << endl;
					temp = 1;
					break;
				}
			}
		}

		if ( temp == 0 ) {
			for ( i = sqrt ( l ); i >= 2; i-- ) {
				if ( l % i == 0 ) {
					if ( l % ( l / i ) == 0 ) {
						if ( lcm ( lc, l / i ) == l ) {
							cout << "Case " << cases - t << ": " << l / i << endl;
							temp = 1;
							break;
						}
					}
				}
			}
		}

		if ( temp == 0 ) {
			cout << "Case " << cases - t << ": " << l << endl;
		}
	}

	return 0;
}
/*
Case 1: 34572482884
Case 2: 1204930592
Case 3: 193
Case 4: 464
Case 5: 169
Case 6: 13370699342
*/
