#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
#define mod 100000007

using namespace std;

ll arr[100100];
ll dp[10010];
set < ll > st;
vector <ll > v;

void dptable()
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 5;
	ll j;

	for (ll i = 4; i < 3500; i++) {
		for ( j = 1; j <= i / 2; j++) {
			dp[i] = (dp[i] + ((2 * dp[j - 1] * dp[i - j]) % mod) ) % mod;
		}

		if (dp[i] < 0)
			dp[i] += mod;

		if (i % 2 != 0) {
			dp[i] = (dp[i] + ((dp[i / 2 ] * dp[i / 2 ]) % mod) ) % mod;
		}

		if (dp[i] < 0)
			dp[i] += mod;
	}

	//cout << dp[4] << " " << " "  << dp[5] << " " << dp[7] << " hewrlo" << endl;
}


void sieve()
{
	for (ll i = 2; i < 1e5 + 50; i++) {
		ll k = i * i;

		while (k < (1e10 + 10)) {
			st.insert(k);
			k *= i;
		}
	}

	set<ll>::iterator it;

	for (it = st.begin(); it != st.end(); it++)
		v.push_back(*it);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b, ans;
	cin >> t;
	sieve();
	dptable();
	sort(v.begin(), v.end());
	ll cases = t;

	while (t--) {
		cin >> a >> b;
		vector<ll>::iterator it1 = upper_bound(v.begin(), v.end(), b) ;
		vector<ll>::iterator it2 = lower_bound(v.begin(), v.end(), a);
		ll cnt = it1 - it2;

		if (cnt != 0)
			cout << "Case " << cases - t << ": "  << dp[cnt] << endl;
		else
			cout << "Case " << cases - t << ": "  << "0" << endl;
	}

	return 0;
}