#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll visited[1010];
ll dp[1010][2];
ll dpcountr[1010][2];
vector <ll > edge[1010];

ll dfs(ll curr, ll taken, ll prev)
{
	visited[curr] = 1;

	if (edge[curr].size() == 1 and edge[curr][0] == prev) {
		if (taken == 1)
			return 1;
		else
			return 0;
	}

	if (dp[curr][taken])
		return dp[curr][taken];

	ll ans = 0;
	dpcountr[curr][taken]  = 0;

	if (taken == 0) {
		for (int i = 0; i < edge[curr].size(); i++) {
			if (edge[curr][i] != prev) {
				ans += dfs(edge[curr][i], 1 , curr);
				dpcountr[curr][taken] += dpcountr[edge[curr][i]][1];
			}
		}

	} else {
		ans = 1;

		for (int i = 0; i < edge[curr].size(); i++) {
			if (edge[curr][i] != prev) {
				ll a1 = dfs(edge[curr][i], 0 , curr);
				ll a2 = dfs(edge[curr][i], 1 , curr);

				if (a1 < a2) {
					ans += a1;
					dpcountr[curr][taken] += dpcountr[edge[curr][i]][0];

				} else if (a2 < a1) {
					ans += a2;
					dpcountr[curr][taken] += 1 +  dpcountr[edge[curr][i]][1];

				} else {
					ans += a2;
					dpcountr[curr][taken] += max(dpcountr[edge[curr][i]][0], 1 +  dpcountr[edge[curr][i]][1]);
				}
			}
		}
	}

	return  dp[curr][taken] = ans;
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
		memset(visited, 0, sizeof visited);
		memset(dp, 0, sizeof dp);
		memset(dpcountr, 0, sizeof dpcountr);

		for (i = 0; i < 1010; i++)
			edge[i].clear();

		for (i = 0; i < m; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		ll ans = 0;
		ll cnt = 0;

		for (i = 0; i < n; i++) {
			if (visited[i] == 0) {
				ll a1 = dfs(i, 0, -1);
				ll a2 = dfs(i, 1, -1);

				if (a1 < a2) {
					ans += a1;
					cnt += dpcountr[i][0];

				} else if (a2 < a1) {
					ans += a2;
					cnt += dpcountr[i][1];

				} else {
					ans += a1;
					cnt += max(dpcountr[i][0], dpcountr[i][1]);
				}
			}
		}

		cout << "Case " << cases - t << ": "  << ans << " "  << cnt << " " <<  m - cnt << endl;
	}

	return 0;
}
