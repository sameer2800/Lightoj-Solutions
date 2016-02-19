#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

vector < ll>  v[1010];
ll discovery[1010], low[1010], stac[1010], mark[1010];
ll n, global_time, set_no;
stack <ll> stk;
set < ll > st[1010];

void tarzan_dfs(int curr)
{
	discovery[curr] = global_time;
	global_time++;
	low[curr] = discovery[curr];
	stac[curr] = 1;
	stk.push(curr);

	for (int i = 0; i < v[curr].size(); i++) {
		if (discovery[v[curr][i]] == -1) {
			tarzan_dfs(v[curr][i]);
			low[curr] = min(low[curr], low[v[curr][i]]);

		} else if (stac[v[curr][i]] == 1 ) {
			low[curr] = min(low[curr], discovery[v[curr][i]]);
		}
	}

	if (discovery[curr] == low[curr]) {
		while (stk.top() != curr) {
			st[set_no].insert(stk.top());
			stac[stk.top()] = 0;
			stk.pop();
		}

		stk.pop();
		stac[curr] = 0;
		st[set_no].insert(curr);
		set_no++;
	}
}


int tarzan()
{
	for (int i = 0; i < 1010; i++)
		st[i].clear();

	global_time = 0;
	set_no = 0;
	memset(discovery, -1, sizeof discovery);
	//memset(low, 0, sizeof low);
	//memset(stac, 0, sizeof stac);
	tarzan_dfs(0);

	for (int i = 1; i < 1010; i++) {
		if (mark[i] == 1) {
			if (discovery[i] == -1) {
				return 0;
			}
		}
	}

	set < ll >::iterator it;
	ll zindex = 0;

	for (int i = 0; i < set_no; i++) {
		if (st[i].count(0)) {
			zindex = i;
			break;
		}
	}

	ll tempc = 0, tempel = 0;
	ll cntr = 0;

	while (cntr < set_no) {
		cntr++;
		tempc = 0, tempel = -1, cntr = 0;

		for (it = st[zindex].begin(); it != st[zindex].end(); it++) {
			ll elem  = *it;

			for (int j = 0; j < v[elem].size(); j++) {
				if (!st[zindex].count(v[elem][j])) {
					tempc++;
					tempel = v[elem][j];
				}
			}
		}

		if (tempc > 1)
			return 0;

		if (tempel == -1)
			return 1;

		for (int i = 0; i < set_no; i++) {
			if (st[i].count(tempel)) {
				zindex = i;
				break;
			}
		}
	}

	return 1;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ll i, j, k, m, t, cont, a, b;
	scanf("%lld", &t);
	ll cases = t;

	while (t--) {
		scanf("%lld", &n);
		memset(mark, 0, sizeof mark);

		for (i = 0; i < 1010; i++)
			v[i].clear();

		for (i = 0; i < n; i++) {
			scanf("%lld", &k);

			for (j = 0; j < k; j++) {
				scanf("%lld %lld", &a, &b);
				mark[a] = 1, mark[b] = 1;
				v[a].push_back(b);
			}
		}

		int ans  = tarzan();

		if (ans == 0)
			printf("Case %lld: NO\n", cases - t );
		else
			printf("Case %lld: YES\n", cases - t );
	}

	return 0;
}