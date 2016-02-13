#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll lcs[55][55][55];
vector <pair <ll, ll> > v;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont;
	string a, b, c;
	cin >> t;
	ll cases = t;

	while (t--) {
		memset(lcs, 0, sizeof lcs);
		cin >> a >>  b >> c;

		for (int i = a.size(); i >= 0; i--) {
			for (int j = b.size(); j >= 0; j--) {
				for (int k = c.size(); k >= 0; k--) {
					if (i == a.size() || j == b.size() || k == c.size()) {
						lcs[i][j][k] = 0;
						continue;
					}

					if (a[i] == b[j] and a[i] == c[k]) {
						lcs[i][j][k] = lcs[i + 1][j + 1][k + 1] + 1;

					} else {
						lcs[i][j][k] = max(lcs[i + 1][j][k], max( lcs[i][j + 1][k], lcs[i][j][k + 1]));
					}
				}
			}
		}

		cout << "Case " << cases - t << ": "  << lcs[0][0][0] << endl;
	}

	return 0;
}