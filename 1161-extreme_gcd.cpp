#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[10100];
ll prime[10100];
ll cnt[10100];

vector <pair <ll, ll> > v;
vector <ll > primes;


ll nc4(ll k)
{
	if (k <= 3)
		return 0;

	ll large = k * (k - 1) * (k - 2) * (k - 3);
	return large / 24;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	//ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	scanf("%lld", &t);
	ll cases = t;

	while (t--) {
		//cin >> n ;
		scanf("%lld", &n);
		ll maxi = 0;
		memset(cnt, 0, sizeof cnt);

		for (i = 0; i < n; i++) {
			//cin >> k;
			scanf("%lld", &k);
			//cnt[k]++;

			for (j = 1; j * j <= k; j++) {
				if ( (k % j) == 0) {
					cnt[j]++;
				}

				if ((k / j != j)   and (k % j == 0)) {
					cnt[k / j]++;
				}
			}

			arr[i] = k;
			maxi = max(maxi, k);
		}

		ll ans = nc4(n);
		ll loopans = 0;

		for (i = maxi; i >= 1; i--) {
			ll temp = nc4(cnt[i]);

			for (j = i + i ; j <= maxi; j = j + i) {
				temp -= cnt[j];
			}

			cnt[i] = temp;
		}

		printf("Case %lld: %lld\n", cases - t, cnt[1]);
	}

	return 0;
}