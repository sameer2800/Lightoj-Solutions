#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

vector <ll> v[1010];
ll color[1010];
ll mark[1010];

ll n;

ll bfs(ll cur)
{
	ll countr[2];
	memset(countr, 0, sizeof countr);
	color[cur] = 0;
	countr[color[cur]]++;
	queue <ll> q;
	q.push(cur);

	while (!q.empty()) {
		ll elem = q.front();
		q.pop();
		mark[elem] = 1;

		for (int i = 0; i < v[elem].size(); i++) {
			ll loc = v[elem][i];

			if (mark[loc] != 1) {
				color[loc] = color[elem] ^ 1;
				countr[color[loc]]++;
				q.push(loc);
			}
		}
	}

	return max(countr[0], countr[1]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k,  m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> m;
		memset(mark, 0, sizeof mark);
		memset(color, -1, sizeof color);

		for (i = 1; i <= n; i++)
			v[i].clear();

		for (i = 0; i < m; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		ll ans = 0;

		for (i = 1; i <= n; i++) {
			if (mark[i] == 0 and v[i].size() != 0) {
				//	cout << "hel";
				ans += bfs(i);
			}
		}

		cout << "Case " << cases - t << ": "  << ans << endl;
	}

	return 0;
}