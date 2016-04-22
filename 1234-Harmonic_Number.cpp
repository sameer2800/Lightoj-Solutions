#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

double arr[1000100]; // 10 ^ 8 / 100


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;
	arr[0] = 0;
	ll curr = 0;

	for (i = 1; i < 1e6 + 5; i++) {
		double temp = 0;

		for (j = 1; j <= 100; j++) {
			temp += (double) 1 / double(j + curr);
		}

		curr += 100;
		arr[i] = arr[i - 1] + temp;
	}

	while (t--) {
		cin >> n ;
		double ans = arr[n / 100];
		ll yo = (n / 100) * 100;

		for (i = 1; i <= n % 100; i++) {
			ans += (double)1.0 / double(yo + i);
		}

		cout << fixed << setprecision(11) << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}