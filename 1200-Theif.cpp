#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
ll dp[10100];
ll price[120], weight[120];
ll n;

ll func(ll weig)
{
	//cout << weig << endl;
	if (weig == 0)
		return 0;

	if (dp[weig] != -1)
		return dp[weig];

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		if (weig >= weight[i])
			ans = max(ans, price[i] + func(weig - weight[i]));
	}

	return dp[weig] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, c, w, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> w;
		ll cntw = 0;
		memset(dp, -1, sizeof dp);

		for (i = 0; i < n; i++) {
			cin >> a >> b >> c;
			cntw += b * c;
			price[i] = a, weight[i] = c ;
		}

		if (w < cntw) {
			cout << "Case " << cases - t << ": Impossible"   << endl;

		} else if (w == cntw) {
			cout << "Case " << cases - t << ": 0"   << endl;

		} else {
			cout << "Case " << cases - t << ": " << func( w - cntw)   << endl;
		}
	}

	return 0;
}