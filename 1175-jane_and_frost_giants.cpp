#include <bits/stdc++.h>
#define ll long long
#define MAX 100100

using namespace std;

char arr[210][210];
char mark[210][210];
ll fdist[210][210];
ll jdist[210][210];

ll n, m;

void bfs2(int i, int j)
{
	queue < pair <ll, pair <ll, ll > >  > q;
	q.push(make_pair(0, make_pair( i, j)));
	memset(mark, -1, sizeof mark);
	ll contr = 0;

	while (!q.empty()) {
		contr++;
		//cout << "elem pos " << i << " " << j << " data " << jdist[i][j] << endl;
		pair < ll, pair <ll, ll > > pr	= q.front();
		q.pop();
		i = pr.second.first;
		j = pr.second.second;

		if (i < 0 || i >= n || j < 0 || j >= m )
			continue;

		if (mark[i][j] == 1)
			continue;

		jdist[i][j] = min(jdist[i][j], pr.first);
		mark[i][j] = 1;

		if ( arr[i - 1][j] == '.' ) {
			q.push(make_pair(pr.first + 1, make_pair(i - 1, j) ));
		}

		if ( arr[i + 1][j] == '.') {
			q.push(make_pair(pr.first + 1, make_pair(i + 1, j) ));
		}

		if ( arr[i][j - 1] == '.' ) {
			q.push(make_pair(pr.first + 1, make_pair(i, j - 1) ));
		}

		if ( arr[i][j + 1] == '.' ) {
			q.push(make_pair(pr.first + 1, make_pair(i, j + 1) ));
		}
	}

	//cout << "contt " << contr << endl;
}


void bfs()
{
	ll i, j;
	queue < pair <ll, pair <ll, ll > > > q;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr[i][j] == 'F')
				q.push(make_pair(0, make_pair( i, j)));
		}
	}

	memset(mark, -1, sizeof mark);
	ll contr = 0;

	while (!q.empty()) {
		contr++;
		pair < ll, pair <ll, ll >  >pr	= q.front();
		q.pop();
		i = pr.second.first;
		j = pr.second.second;

		if (mark[i][j] == 1)
			continue;

		fdist[i][j] = min(fdist[i][j], pr.first);
		mark[i][j] = 1;

		if (i - 1 >= 0 ) {
			if (i - 1 >= 0 and arr[i - 1][j] == '.' and mark[i - 1][j] == -1) {
				q.push(make_pair(pr.first + 1, make_pair(i - 1, j) ));
			}
		}

		if (i + 1 < n ) {
			if (i + 1  < n and arr[i + 1][j] == '.' and mark[i + 1][j] == -1) {
				q.push(make_pair(pr.first + 1, make_pair(i + 1, j) ));
			}
		}

		if (j - 1 >= 0) {
			if (j - 1  >= 0 and arr[i][j - 1] == '.' and mark[i][j - 1] == -1) {
				q.push(make_pair(pr.first + 1, make_pair(i, j - 1) ));
			}
		}

		if (j + 1 < m) {
			if (j + 1 < m and arr[i][j + 1] == '.' and mark[i][j + 1] == -1) {
				q.push(make_pair(pr.first + 1, make_pair(i, j + 1) ));
			}
		}
	}

//	cout << "contt " << contr << endl;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, t, cont, a, b;
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> m;

		for (i = 0; i < n ; i++) {
			for (j = 0; j < m; j++) {
				fdist[i][j] =  INT_MAX;
				jdist[i][j] =  INT_MAX;
			}
		}

		for (i = 0; i < n ; i++) {
			for (j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		bfs();

		for (i = 0; i < n ; i++) {
			for (j = 0; j < m; j++) {
				if (arr[i][j] == 'J')
					bfs2(i, j);
			}
		}

		ll temp = INT_MAX;

		for (i = 0; i < m; i++) {
			if (jdist[0][i] < fdist[0][i])
				temp = min(temp, jdist[0][i]);

			if (jdist[n - 1][i] < fdist[n - 1][i])
				temp = min(temp, jdist[n - 1][i]);
		}

		for (i = 0; i < n; i++) {
			if (jdist[i][0] < fdist[i][0])
				temp = min(temp, jdist[i][0]);

			if (jdist[i][m - 1] < fdist[i][m - 1])
				temp = min(temp, jdist[i][m - 1]);
		}

		if (temp == INT_MAX)
			cout << "Case " << cases - t << ": "  << "IMPOSSIBLE" << endl;
		else
			cout << "Case " << cases - t << ": "  << temp + 1 << endl;
	}

	return 0;
}