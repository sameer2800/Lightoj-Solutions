#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[1100], n ;
ll dp[1100][2][2];


ll recurse(ll curr, ll taken, ll first)
{
	if (curr == n)
		return 0;

	ll ans = 0;

	if (curr == n - 1) {
		if (taken == 0) {
			return 0;

		} else {
			if (first == 0) {
				return arr[curr];

			} else {
				return 0;
			}
		}
	}

	if (dp[curr][taken][first])
		return dp[curr][taken][first];

	if (taken == 0) {
		ans = max(ans, recurse(curr + 1, 1, first) );
		ans = max(ans, recurse(curr + 1, 0, first) );

	} else {
		ans = max(ans, arr[curr] + recurse(curr + 1, 0, first) );
	}

	return  dp[curr][taken][first] = ans;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		memset(dp, 0, sizeof dp);
		cin >> n ;

		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}

		ll ans  = max( recurse(0, 1, 1), recurse (0, 0, 0));
		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}