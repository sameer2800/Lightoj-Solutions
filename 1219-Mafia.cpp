#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll boys[10100];
bool visited[10100];
vector <ll> edges[10100];


ll ans;

ll dfs(ll curr)
{
	if (visited[curr])
		return 0;

	ll extr = boys[curr] - 1;
	visited[curr] = true;

	for (int i = 0; i < edges[curr].size(); i++) {
		ll child = edges[curr][i];
		ll temp = dfs(child);
		extr += temp;
		ans += abs(temp);
	}

	return extr;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b, edge;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n ;

		for ( i = 0; i < n; ++i)
		{
			edges[i].clear();
		}

		memset(visited, false, sizeof visited);
		ans = 0;

		for (i = 0; i < n; i++) {
			cin >> k;
			k--;
			cin >> boys[k];
			cin >> edge;

			for (j = 0; j < edge; j++) {
				cin >> a;
				a--;
				edges[k].push_back(a);
				edges[a].push_back(k);
			}
		}

		for (i = 0; i < n; i++) {
			if (visited[i] == false)
				dfs(i);
		}

		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}