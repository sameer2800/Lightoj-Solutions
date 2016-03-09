#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
ll grundy[10010];
ll tempg[10010];

vector <pair <ll, ll> > v;

void sprague_grundy()
{
	grundy[0] = grundy[1] = grundy[2] = 0;

	for (int i = 3; i < 10010; i++) {
		memset(tempg, 0, sizeof tempg);

		for (int j = 1; j <= i / 2; j++) {
			if (j != i - j) {
				ll k = grundy[j] ^ grundy[i - j];
				tempg[k] = 1;
			}
		}

		for (ll yo = 0; yo < 10010; yo++) {
			if (tempg[yo] == 0 ) {
				grundy[i] = yo;
				break;
			}
		}
	}
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
	sprague_grundy();

	while (t--) {
		cin >> n;
		ll ans = 0;

		for (i = 0; i < n; i++) {
			cin >> k;
			ans ^= grundy[k];
		}

		if (ans == 0)
			cout << "Case " << cases - t << ": Bob"   << endl;
		else
			cout << "Case " << cases - t << ": Alice"   << endl;
	}

	return 0;
}