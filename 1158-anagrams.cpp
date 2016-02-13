#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll  fact[11], countr[11];

char s[11];
ll dp[1 << 11][1005];
ll d;
ll glob_len_s;

ll permutations(int num, int curr)
{
	//cout << num << " " << curr << endl;
	int len = __builtin_popcount(num);

	if (num == (1 << glob_len_s) - 1) return curr ? 0 : 1;

	if (len > glob_len_s || num >= (1 << glob_len_s ) )
		return 0;

	if (dp[num][curr] != -1)
		return dp[num][curr];

	dp[num][curr] = 0;

	for (int i = 0; i < glob_len_s; i++) {
		if ((num & (1 << i)) == 0) {
			int elem = s[i] - '0';
			dp[num][curr] += permutations(num | (1 << i), (curr * 10 + elem) % d );
		}
	}

	return dp[num][curr];
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	//ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	scanf("%lld", &t);
	ll cases = t ;
	fact[0] = 1;

	for (i = 1; i < 14; i++) {
		fact[i] = i * fact[i - 1];
	}

	while (t--) {
		memset(dp, -1, sizeof dp);
		memset(countr, 0, sizeof countr);
		scanf("%s %lld", s, &d);
		glob_len_s = strlen(s);

		for (i = 0; i < glob_len_s; i++) {
			countr[s[i] - '0']++;
		}

		ll ans = permutations(0, 0);
		ll divide = 1;

		for (i = 0; i <= 9; i++) {
			divide *= fact[countr[i]];
		}

		printf("Case %lld: %lld\n", cases - t, ans / divide);
	}

	return 0;
}