#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];

vector <ll> primes;

ll big = pow(2, 33);
ll bigi = -big;
map <ll, ll> mp;

void sieve()
{
	ll i, j;

	for (i = 2; i < 100100; i++) {
		if (arr[i] == 0) {
			primes.push_back(i);

			for (j = i ; j < 100100; j *= i) {
				arr[j] = 1;
			}
		}
	}

	//cout << big << endl;

	for (i = 0; i < primes.size(); i++) {
		ll elem = primes[i];
		ll base = elem;
		ll pwr = 1;

		while (elem <= big) {
			mp[elem] = pwr;

			if (pwr % 2)
				mp[-elem] = pwr;

			ll loc = pwr;

			while (loc % 2 == 0) {
				loc /= 2;
			}

			mp[-elem] = loc;
			elem *= base;
			pwr++;
		}
	}
}






int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	sieve();
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n ;
		ll ans = 1;

		if (mp.find(n) != mp.end())
			ans = mp[n];

		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}