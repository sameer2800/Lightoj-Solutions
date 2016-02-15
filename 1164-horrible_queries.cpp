#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

struct sam {
	ll sum;
	ll todown;
};

sam  nodes[1000100];


void update(int id, int start, int end, int qstart, int qend, int val)
{
	if (qstart > end || qend < start || start > end ) {
		nodes[id].sum += (end - start + 1) * (nodes[id].todown );
		nodes[id * 2 + 1].todown += nodes[id].todown;
		nodes[id * 2 + 2].todown += nodes[id].todown;
		nodes[id].todown = 0;
		return;
	}

	if (start >= qstart and end <= qend) {
		nodes[id].sum += (end - start + 1) * (nodes[id].todown + val);
		nodes[id * 2 + 1].todown +=  nodes[id].todown + val;
		nodes[id * 2 + 2].todown +=  nodes[id].todown + val;
		nodes[id].todown = 0;
		return;
	}

	int mid = start + end;
	mid /= 2;
	nodes[id].sum += (end - start + 1) * nodes[id].todown;
	nodes[id * 2 + 1].todown += nodes[id].todown;
	nodes[id * 2 + 2].todown += nodes[id].todown;
	nodes[id].todown = 0;
	update(id * 2 + 1, start, mid, qstart, qend, val);
	update(id * 2 + 2, mid + 1, end, qstart, qend, val);
	nodes[id].sum = nodes[id * 2 + 1].sum + nodes[id * 2 + 2].sum;
}

ll query(int id, int start, int end, int qstart, int qend)
{
	if (qstart > end || qend < start || start > end) {
		nodes[id].sum += (end - start + 1) * (nodes[id].todown);
		nodes[id * 2 + 1].todown += nodes[id].todown;
		nodes[id * 2 + 2].todown += nodes[id].todown;
		nodes[id].todown = 0;
		return 0 ;
	}

	if (start >= qstart and end <= qend) {
		nodes[id].sum += (end - start + 1) * (nodes[id].todown);
		nodes[id * 2 + 1].todown += nodes[id].todown;
		nodes[id * 2 + 2].todown += nodes[id].todown;
		nodes[id].todown = 0;
		return nodes[id].sum;
	}

	int mid = start + end;
	mid /= 2;
	//nodes[id].sum += (end -start+1)* nodes[id].todown;
	nodes[id * 2 + 1].todown += nodes[id].todown;
	nodes[id * 2 + 2].todown += nodes[id].todown;
	nodes[id].todown = 0;
	ll hq1 = query(id * 2 + 1, start, mid, qstart, qend);
	ll hq2 = query(id * 2 + 2, mid + 1, end, qstart, qend);
	nodes[id].sum = nodes[id * 2 + 1].sum + nodes[id * 2 + 2].sum;
	return hq1 + hq2 ;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/sameer/sam.sam", "r", stdin);
#endif
//	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b, c;
	//cin >> t;
	scanf("%lld", &t);
	ll cases = t;

	//t = 1;

	while (t--) {
		memset(nodes, 0, sizeof nodes);
		//cin >> n >> m;
		scanf("%lld %lld", &n, &m);
		//	cout << "Case " << cases - t  << ": "  << endl;
		printf("Case %lld:\n", cases - t );

		for (i = 0; i < m; i++) {
			//	cin >> k ;
			scanf("%lld", &k);

			if (k == 0) {
				//	cin >> a  >> b >> c;
				scanf("%lld %lld %lld", &a, &b, &c);
				update(0, 0, n - 1, a, b, c);

			} else {
				//	cin >> a >> b;
				scanf("%lld %lld", &a, &b);
				ll sae =  query(0, 0, n - 1, a, b) ;
				printf("%lld\n", sae);
			}
		}
	}

	return 0;
}