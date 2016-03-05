#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[100100];
vector <pair <ll, ll> > v;

struct sam {

	int count;

};

struct sam nodes[510100];

void initilize(int node)
{
	nodes[node].count = 0;
}

void buildtree(int node, int start, int end)
{
	if (start > end)
		return;

	if (start == end)
	{
		nodes[node].count = 1;
		return;
	}

	int mid = start + end;
	mid /= 2;
	buildtree(node * 2 + 1, start , mid);
	buildtree(node * 2 + 2, mid + 1, end);
	nodes[node].count  = nodes[2 * node + 1].count + nodes[2 * node + 2].count;
}

ll deleter(int node, int start, int end, int pos)
{
	//cout << node << " " << start << " " << end << " " << pos << endl;
	if (start > end)
		return -1;

	if (start == end) {
		nodes[node].count = 0;
		return start;
	}

	nodes[node].count--;
	int mid = start + end;
	mid /= 2;

	if (nodes[node * 2 + 1].count >= pos) {
		return deleter(node * 2 + 1, start, mid, pos);

	} else {
		return deleter(node * 2 + 2, mid + 1, end, pos - nodes[node * 2 + 1].count);
	}
}


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
		cin >> n ;
		v.clear();

		for (i = 0; i < n; i++)
			cin >> arr[i];

		buildtree(0, 0, n - 1);
		ll ans ;
		//cout << nodes[1].count << endl;

		for (i = n - 1; i >= 0; i--) {
			ans = deleter(0, 0, n - 1, i + 1 - arr[i]);
			//cout << "--------------------\n";
			//cout << ans << endl;
		}

		cout << "Case " << cases - t << ": "  << ans + 1 << endl;
	}

	return 0;
}