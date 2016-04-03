#include <iostream>
#include <stdio.h>

#define ll long long

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	//ios_base::sync_with_stdio(false);
	ll i, j,   m, t, cont, a, b;
	ll n, k;
	ll dp[10010];
	ll arr[110];
	ll mod = 100000007;
	scanf("%lld", &t);
	ll cases = t;

	while (t--) {
		scanf("%lld %lld", &n, &k);

		for (i = 0; i <= k + 1; i++)
			dp[i] = 0;

		for (i = 0; i < n; i++)
			scanf("%lld", &arr[i]);

		dp[0] = 1;

		for (i = 0; i < n; i++) {
			for (j = 1; j <= k; j++) {
				if (j - arr[i] >= 0)
					dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
			}
		}

		//ll ans = dp[k];
		printf("Case %lld: %lld\n", cases - t, dp[k]);
	}

	return 0;
}