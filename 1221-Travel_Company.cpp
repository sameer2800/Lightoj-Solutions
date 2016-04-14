#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

vector <ll> revgraph[1010];

struct edg {
	int src;
	int dest;
	int inc, expen;
};

vector <struct edg > edgo;


int dist_exp[1010], dist_inc[1010];
int mark[1010];
vector <ll> ans;

ll n, m;
ll profit;



ll bellmanford()
{
	dist_inc[n] = 0;
	dist_exp[n] = 0;
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < edgo.size(); j++) {
			edg sam = edgo[j];
			int src = sam.src , dest = sam.dest;
			ll rhs = -(dist_inc[src] + sam.inc) - profit * (dist_exp[src] + sam.expen);

			if (dist_inc[src] != INT_MAX and  (profit * dist_exp[dest] - dist_inc[dest] ) > rhs ) {
				dist_inc[dest] = dist_inc[src] + sam.inc;
				dist_exp[dest] = dist_exp[src] + sam.expen;
				cout << src <<  " " << dest << endl;
			}
		}
	}

	for (j = 0; j < edgo.size(); j++) {
		edg sam = edgo[j];
		int src = sam.src , dest = sam.dest;
		ll rhs = (dist_inc[src] + sam.inc) - profit * (dist_exp[src] + sam.expen);

		if (dist_inc[src] != INT_MAX and dist_inc[dest] - profit * dist_exp[dest] > rhs ) {
			return 1;
		}
	}

	return 0;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, t, cont, a, b, c, d;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> m >> profit;
		edgo.clear();

		for (i = 0; i <= n; i++)
			revgraph[i].clear();

		for (i = 0; i < m; i++) {
			cin >> a >> b >> c >> d;
			revgraph[a].push_back(b);
			edg sam;
			sam.src = a;
			sam.dest = b;
			sam.inc = c;
			sam.expen = d;
			edgo.push_back(sam);
		}

		for (i = 0; i < n; i++) {
			revgraph[n].push_back(i);
			edg sam;
			sam.src = n;
			sam.dest = i;
			sam.inc = 0 ;
			sam.expen = 0;
			edgo.push_back(sam);
			dist_inc[i] = INT_MAX;
			dist_exp[i] = INT_MAX;
		}

		ll ans = bellmanford();
		cout << "Case " << cases - t  << ": " ;

		if (ans == 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}

