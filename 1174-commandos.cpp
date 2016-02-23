#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

ll arr[110][110];
ll n;

void floyd_warshall()
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll   k, m, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n ;
		cin >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					arr[i][j] = 0;
				else
					arr[i][j] = INT_MAX;
			}
		}

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			arr[a][b] = 1 ;
			arr[b][a] = 1;
		}

		floyd_warshall();
		ll st, dest;
		cin >> st >> dest;
		ll maxi = 0;

		for (int i = 0; i < n; i++) {
			maxi = max(arr[st][i] + arr[i][dest], maxi);
		}

		cout << "Case " << cases - t << ": "  << maxi << endl;
	}

	return 0;
}