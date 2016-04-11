#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <pair <ll, ll> > v;

ll mod;

ll power(ll a, ll b)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a;

	ll half = power(a, b / 2);

	if (b % 2 != 0) {
		return (((half * half) % mod ) * a) % mod;
	}

	else
		return ((half * half) % mod ) ;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> k >> mod;
		ll sum  = 0;

		for (i = 0; i < n; i++) {
			cin >> m;
			sum = (sum + m) % mod;
		}

		ll ans = (power(n, k - 1) * sum ) % mod;
		ans =  ( ans * ((k) % mod )) % mod;
		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}