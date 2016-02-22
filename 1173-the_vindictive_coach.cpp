#include <bits/stdc++.h>
#define ll unsigned long long
#define MAX 100100

using namespace std;

ll f[60][60] ; // f(a,b) => a contains count of smaller elements , b contains
ll g[60][60];  // number of larger elements.f(a,b) chosing element from a.
ll mod;

ll recursive_gdp(ll mins, ll maxs);

ll recursive_fdp(ll mins, ll maxs)
{
	if (mins ==  1 and maxs == 0) {
		f[mins][maxs] = 1;
		return 1;
	}

	if (mins == 0) {
		f[mins][maxs] = 0;
		return 0;
	}

	if (mins < 0 || maxs < 0)
		return 0;

	if (f[mins][maxs] != -1)
		return f[mins][maxs];

	ll temp = 0;

	for (int k = 0; k < mins; k++) {
		temp += recursive_gdp(k, maxs + mins - 1 - k);
	}

	f[mins][maxs] = temp;
	return temp;
}

ll recursive_gdp(ll mins, ll maxs)
{
	if (mins ==  0 and maxs == 1) {
		g[mins][maxs] = 1;
		return 1;
	}

	if (maxs == 0) {
		g[mins][maxs] = 0;
		return 0;
	}

	if (mins < 0 || maxs < 0)
		return 0;

	if (g[mins][maxs] != -1)
		return g[mins][maxs];

	ll temp = 0;

	for (int k = 0; k < maxs; k++) {
		temp =  (temp + recursive_fdp( mins + (maxs - 1 - k), k)) ;
	}

	g[mins][maxs] = temp;
	return temp;
}


void dptable()
{
	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);
	f[1][0]  = 1;
	g[0][1] = 1;

	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			f[i][j] = recursive_fdp(i, j);
			g[i][j] = recursive_gdp( i, j);
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/sameer/Documents/sameer/input.sam", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	ll i, j, k, n, m, t, cont, a, b;
	dptable();
	cin >> t;
	ll cases = t;

	while (t--) {
		cin >> n >> m;

		if (m != 1) {
			cout << "Case " << cases - t << ": "   <<  f[m - 1][n - m] << endl;
		}

		else {
			if (n >= 3)
				cout << "Case " << cases - t << ": "   <<  f[1][n - 3] << endl;
			else
				cout << "Case " << cases - t << ": "   <<  "1" << endl;
		}
	}

	return 0;
}