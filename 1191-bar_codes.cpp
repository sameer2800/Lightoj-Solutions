#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <pair <ll, ll> > v;
ll dp[55][55];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	//cin >> t;
	scanf("%lld", &t);
	ll cases = t;

	while (t--) {
		memset(dp, 0, sizeof dp);
		//cin >> n >> k >> m;
		scanf("%lld %lld %lld", &n, &k, &m);
		dp[1][1]  = 1; //black

		for (i = 1; i <= m; i++) {
			dp[i][1] = 1;
		}

		for (i = 2; i <= n; i++) {
			for (j = 2; j <= k; j++) {
				if (i - 1 - m >= 0)
					dp[i][j] = dp[i - 1][j] - dp[i - 1 - m][j - 1] + dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j]  + dp[i - 1][j - 1];
			}
		}

		printf("Case %lld: %lld\n", cases - t, dp[n][k] );
	}

	return 0;
}