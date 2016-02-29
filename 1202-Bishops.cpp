#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <pair <ll, ll> > v;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n1, m1, n2, m2, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n1 >> m1 >> n2 >> m2;

		if ((n1 + m1) % 2 != (n2 + m2) % 2 )
			cout << "Case " << cases - t << ": impossible"   << endl;
		else {
			if (abs(n2 - n1) == abs(m2 - m1)) {
				cout << "Case " << cases - t << ": 1"   << endl;

			} else {
				cout << "Case " << cases - t << ": 2"   << endl;
			}
		}
	}

	return 0;
}