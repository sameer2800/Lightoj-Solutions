#include <bits/stdc++.h>
#define ll long long
#define MAX 100100
#define mod 1000007

using namespace std;

ll lcs[1010][1010];
ll nextoccura[1010][28];
ll nextoccurb[1010][28];
ll dp[1010][1010];
string a, b;

void find_lcs()
{
	for (int i = a.size(); i >= 0; i--) {
		for (int j = b.size(); j >= 0; j--) {
			if (i == a.size() || j == b.size()) {
				lcs[i][j] = 0;
				continue;
			}

			if (a[i] == b[j]) {
				lcs[i][j] = lcs[i + 1][j + 1] + 1;

			} else {
				lcs[i][j] = max(lcs[i + 1][j], lcs[i][j + 1]);
			}
		}
	}
}

ll sum(ll su, ll um)
{
	su = (su + um) % mod;

	if (su < 0)
		su += mod;

	return su;
}

ll dfs(int cur_a, int cur_b)
{
	if (lcs[cur_a][cur_b] == 0)
		return 1;

	if (dp[cur_a][cur_b])
		return dp[cur_a][cur_b];

	dp[cur_a][cur_b] = 0;

	for (int i = 0; i <= 26; i++) {
		int x = nextoccura[cur_a][i] , y = nextoccurb[cur_b][i];

		if (lcs[cur_a][cur_b] == lcs[x][y]) {
			dp[cur_a][cur_b] = sum(dp[cur_a][cur_b], dfs(x + 1, y + 1));
		}
	}

	return dp[cur_a][cur_b];
}


void precomp()
{
	for (int i = 0; i < 27; i++) {
		nextoccura[a.size()][i] = a.size();
		nextoccurb[b.size()][i] = b.size();
	}

	for (int i = a.size() - 1; i >= 0; i--) {
		for (int k = 0; k <= 26; k++) {
			char ck = 'a' + k;

			if (a[i] == ck) {
				nextoccura[i][k] = i;

			} else {
				nextoccura[i][k] = nextoccura[i + 1][k];
			}
		}
	}

	for (int i = b.size() - 1; i >= 0; i--) {
		for (int k = 0; k <= 26; k++) {
			char ck = 'a' + k;

			if (b[i] == ck) {
				nextoccurb[i][k] = i;

			} else {
				nextoccurb[i][k] = nextoccurb[i + 1][k];
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> a;
		cin >> b;
		memset(lcs, 0, sizeof lcs);
		memset(dp, 0, sizeof dp);
		find_lcs();
		precomp();
		ll ans = dfs(0, 0);
		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}