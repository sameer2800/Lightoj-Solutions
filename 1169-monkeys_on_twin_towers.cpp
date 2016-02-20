#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll a[1010], b[1010], crossa[1010], crossb[1010];
ll n;
ll dp[3][1010];

ll bottomup(int building, int floor)
{
	if (floor == n - 1) {
		if (building == 0) {
			return a[floor];

		} else {
			return b[floor];
		}
	}

	if (dp[building][floor])
		return dp[building][floor];

	ll temp = 0;

	if (building == 0) {
		temp = a[floor] + min(bottomup(building, floor + 1) , crossa[floor] + bottomup(1, floor + 1));

	} else {
		temp = b[floor] + min(bottomup(building, floor + 1) , crossb[floor] + bottomup(0, floor + 1));
	}

	dp[building][floor] = temp;
	return temp;
}

ll twintowers()
{
	memset(dp, 0, sizeof dp);
	// building_no,floor_no
	return min(bottomup(0, 0) , bottomup(1, 0) );
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, m, t, cont;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n;

		for (i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (i = 0; i < n; i++) {
			cin >> b[i];
		}

		for (i = 0; i < n - 1; i++) {
			cin >> crossa[i];
		}

		for (i = 0; i < n - 1; i++) {
			cin >> crossb[i];
		}

		ll ans = twintowers();
		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}