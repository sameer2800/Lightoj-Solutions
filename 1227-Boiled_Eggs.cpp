#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <pair <ll, ll> > v;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b, p, q;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> p >> q;

		for (i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);
		ll sum = 0;
		ll cnt = 0;
		ll ans = 999;

		for (i = 0; i < n; i++) {
			sum += arr[i];
			cnt++;

			if (sum > q and cnt == p) {
				ans = cnt - 1;
				break;
			}

			if (sum > q) {
				ans = cnt - 1;
				break;
			}

			if (sum <= q and cnt == p) {
				ans = cnt;
				break;
			}
		}

		if (ans == 999)
			ans = n;

		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}