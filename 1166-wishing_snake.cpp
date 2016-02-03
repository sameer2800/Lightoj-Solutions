#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[120];
ll mark[120];
vector <pair <ll, ll> > v;
ll n;

int global = 0;

void dfs(int par, int cur, int ans)
{
	if (par == cur) {
		global += (ans - 1);
		return;
	}

	mark[cur] = 1;
	dfs(par, arr[cur], ans + 1);
}


void epicdfs()
{
	memset(mark, 0, sizeof mark);
	global = 0;

	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			mark[i] = 1;
			dfs(i, arr[i], 1);
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n ;

		for (i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		epicdfs();
		cout << "Case " << cases - t << ": "  << global << endl;
	}

	return 0;
}