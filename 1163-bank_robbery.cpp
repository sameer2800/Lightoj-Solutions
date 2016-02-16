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
	ll i, j, k, n, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n;

		if (n % 9)
			cout << "Case " << cases - t << ": "  <<  n + (n / 9) << endl;
		else
			cout << "Case " << cases - t << ": "  << (n + (n / 9) - 1) << " " <<  n + (n / 9) << endl;
	}

	return 0;
}