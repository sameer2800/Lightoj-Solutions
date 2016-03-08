#include <bits/stdc++.h>
#define ll long long
#define mod 100000007

using namespace std;

ll sum[15110];
ll dp[2][15110];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b, s;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >>  k >> s;
		memset(sum, 0, sizeof sum);
		memset(dp, 0, sizeof dp);

		for (i = 1; i <= k; i++)
			dp[1][i] = i;

		for (i = 2; i <= n; i++) {
			ll temp = i & 1;
			memset(sum , 0, sizeof sum);

			for (j = 1; j <= s; j++) {
				sum[j] = (sum[j - 1] + dp[temp ^ 1][j]) % mod;
				dp[temp][j] = (dp[temp][j - 1] + sum[j - 1]) % mod;

				if (j - 1 - k >= 0) {
					dp[temp][j] = (((dp[temp][j] - sum[j - 1 - k]) % mod + mod) % mod);
					dp[temp][j] = (((dp[temp][j] - dp[temp ^ 1][j - 1 - k] * k) % mod + mod) % mod);
				}
			}
		}

		cout << "Case " << cases - t << ": "  << dp[n & 1][s] << endl;
	}

	return 0;
}