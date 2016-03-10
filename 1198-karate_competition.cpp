#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100];
ll mark[100];
vector <pair <ll, ll> > v;
map <ll, ll> mpa, mpb;

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
		cin >> n;
		mpa.clear();

		for (i = 0; i < n; i++)
			cin >> arr[i];

		for (i = 0; i < n; i++) {
			cin >> k;
			mpa[k]++;
		}

		map <ll, ll>::reverse_iterator it;
		sort(arr, arr + n);
		ll ans = 0;
		memset(mark, 0, sizeof mark);

		for (i = 0; i < n; i++) {
			for (it = mpa.rbegin(); it != mpa.rend(); it++) {
				ll fir = it-> first, sec = it->second;

				if (fir < arr[i] and mpa[fir] > 0 ) {
					//cout << fir << " " << arr[i] << endl;
					mpa[fir]--;
					mark[i] = 1;
					ans += 2;
					break;
				}
			}
		}

		for (i = 0; i < n; i++) {
			if (mark[i] == 0) {
				if (mpa[arr[i]] > 0) {
					ans += 1;
					mark[i] = 1;
					mpa[arr[i]]--;
				}
			}
		}

		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}