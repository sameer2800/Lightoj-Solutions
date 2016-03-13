#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

vector <ll > v[10100];
ll dp[10100][2];
ll mark[10100];

ll func(ll cur, ll taken, ll parent)
{
	mark[cur] = 1;

	if (v[cur].size() == 0) {
		if (taken == 1)
			return 1;
		else
			return 0;
	}

	if (dp[cur][taken] != -1)
		return dp[cur][taken];

	ll ans = taken;

	for (int i = 0; i < v[cur].size(); i++) {
		ll elem = v[cur][i];

		if (elem != parent) {
			if (taken == 1) {
				ans += func(elem, 0, cur);

			} else {
				ans += max(func(elem, 0, cur) , func(elem, 1, cur));
			}
		}
	}

	return dp[cur][taken] = ans;
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
		cin >> n >> m;
		memset(mark, 0, sizeof mark);
		memset(dp, -1, sizeof dp);

		for (i = 1; i <= n; i++)
			v[i].clear();

		for (i = 0; i < m; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		ll ans = 0;

		for (i = 1; i <= n; i++) {
			if (mark[i] == 0 ) {
				//	cout << "hel";
				ans += max( func(i, 0, -1) , func(i, 1, -1));
			}
		}

		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}